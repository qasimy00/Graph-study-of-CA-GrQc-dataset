#pragma once
#include <iostream>
#include <fstream>
using namespace std;



class Node {//adjlistNode or data of every vertice that a vertice itself is connected to 
private:
    int nodeId;
    Node* next;
public:

    Node(int value) {
        next = NULL;
        nodeId = value;
    }

    int getData() {
        return nodeId;
    }

    void setData(int a) {
        nodeId = a;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* a) {
        next = a;
    }
};



class LinkedList {//list of all vertices that vertice is connected to
private:
    Node* vertice;//vertice
    int nodeId;
public:
    void setHead(Node* ptr) {
        vertice = ptr;
    }

    Node* getHead() {
        return vertice;
    }

    LinkedList() {
        vertice = NULL;
        nodeId = 0;
    }

    void setId(int a) {
        nodeId = a;
    }

    int getId() {
        return nodeId;
    }

    /* void addEdge(int id) {
         if (vertice == NULL) {
             vertice = new Node(id);
         }
         else {
             Node* temp = vertice;
             while (temp->getData() != NULL) {
                 temp = temp->getNext();
             }
             temp->setNext(new Node(id));
         }
     }*/
};


class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void setFront(Node* ptr) {
        front = ptr;
    }
    Node* getFront() {
        return front;
    }
    void setRear(Node* ptr) {
        rear = ptr;
    }
    Node* getRear() {
        return rear;
    }
    bool isEmpty() {
        if (front == NULL && rear == NULL) {
            return true;
        }
        return false;
    }
    int showFront() {
        return front->getData();
    }
    void enQueue(int data) {//insert At tail
        if (isEmpty()) {
            Node* n = new Node(data);
            front = n;
            rear = n;
        }
        else {
            Node* n = new Node(data);
            rear->setNext(n);
            rear = n;
        }
    }
    void displayQueue() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }
    void deQueue() {//remove from head
        if (isEmpty()) {
            cout << "The queue is empty!" << endl;
        }
        else if (front->getNext() == NULL) {
            Node* temp = front;
            front = NULL;
            rear = NULL;
            delete temp;
        }
        else {
            Node* temp = front;
            front = front->getNext();
            delete temp;
        }
    }
};


class Graph {
private:
    int totalVertices;
    int edges;
    LinkedList* arr; // array of linked list of size = totalVertices

public:
    Graph(int s, int e) {
        edges = e;
        totalVertices = s;
        arr = new LinkedList[s];
        for (int i = 0; i < s; i++) {//setting every List pointer or Head/Vertice to NULL
            arr[i].setHead(NULL);
        }
    }

    void setVertices(int a) {
        totalVertices = a;
    }
    void setEdges(int a) {
        edges = a;
    }

    void addEdge(int src, int dest) {//(fromNodeId, ToNodeID)
        for (int i = 0; i < totalVertices; i++) {
            if (arr[i].getId() == 0) {
                if (dest == -1) {
                    arr[i].setId(src);
                    return;
                }
                else {
                    arr[i].setId(src);
                    arr[i].setHead(new Node(dest));
                    return;
                }
            }
            if (arr[i].getId() == src) {
                if (arr[i].getHead() != NULL) {
                    Node* temp = arr[i].getHead();
                    while (temp->getNext() != NULL) {
                        temp = temp->getNext();
                    }
                    temp->setNext(new Node(dest));
                }
                else {
                    arr[i].setHead(new Node(dest));
                }
                for (int j = 0; j < totalVertices; j++) {
                    if (arr[j].getId() == dest) {
                        break;
                    }
                    if (arr[j].getId() == 0) {
                        arr[j].setId(dest);
                        break;
                    }
                }
                return;
            }
        }
    }

    void addEdge_undir(int src, int dest) {//(fromNodeId, ToNodeID)
        Node* temp = NULL;
        bool flag = false;
        for (int i = 0; i < totalVertices; i++) {
            flag = false;
            temp = NULL;
            if (arr[i].getId() == 0) {
                arr[i].setHead(new Node(dest));
                arr[i].setId(src);
                for (int j = 0; j < totalVertices; j++) {
                    if (arr[j].getId() == dest) {
                        temp = arr[j].getHead();
                        while (temp->getNext() != NULL) {
                            if (temp->getData() == src) {
                                flag = true;
                                break;
                            }
                            temp = temp->getNext();
                        }
                        if (flag == true) {
                            break;
                        }
                        temp->setNext(new Node(src));
                        break;
                    }
                    if (arr[j].getId() == 0 && arr[j].getHead() == NULL) {
                        arr[j].setId(dest);
                        arr[j].setHead(new Node(src));
                        break;
                    }
                }
                return;
            }
            if (arr[i].getId() == src) {
                if (arr[i].getHead() == NULL) {
                    arr[i].setHead(new Node(dest));
                }
                if (arr[i].getHead() != NULL) {
                    temp = arr[i].getHead();
                    while (temp->getNext() != NULL) {
                        temp = temp->getNext();
                    }
                    temp->setNext(new Node(dest));
                }
                for (int j = 0; j < totalVertices; j++) {
                    if (arr[j].getId() == dest) {
                        temp = arr[j].getHead();
                        while (temp->getNext() != NULL) {
                            if (temp->getData() == src) {
                                flag = true;
                                break;
                            }
                            temp = temp->getNext();
                        }
                        if (flag == true) {
                            break;
                        }
                        temp->setNext(new Node(src));
                        break;
                    }
                    if (arr[j].getId() == 0 && arr[j].getHead() == NULL) {
                        arr[j].setId(dest);
                        arr[j].setHead(new Node(src));
                        break;
                    }
                }
                return;
            }
        }
    }


    void sourceNodes() {
        int counteeeer = 0;
        Node* temp;
        bool flag = true;
        for (int i = 0; i < totalVertices; i++) {
            flag = true;
            if (arr[i].getHead() != NULL) {
                for (int j = 0; j < totalVertices; j++) {
                    temp = arr[j].getHead();
                    while (temp != NULL) {
                        if (temp->getData() == arr[i].getId()) {
                            j = totalVertices + 1;
                            flag = false;
                        }
                        temp = temp->getNext();
                        if (j == totalVertices + 1) {
                            temp = NULL;
                        }
                    }
                }
                if (flag == true) {
                    //cout << arr[i].getId() << endl;
                    counteeeer++;
                }
            }
        }
        cout << "There are " << counteeeer << " number of source nodes" << endl;
        cout << endl;
    }

    void sinkNodes() {
        int counteeer = 0;
        for (int i = 0; i < totalVertices; i++) {
            if (arr[i].getHead() == NULL) {
                //cout << arr[i].getId() << endl;
                counteeer++;
            }
        }
        cout << "There are " << counteeer << " number of sink nodes" << endl;
        cout << endl;
    }

    void getVerticesEdges() {
        Node* temp;
        int vertices = 0;
        int edges = 0;
        for (int i = 0; i < totalVertices; i++) {
            vertices++;
            temp = arr[i].getHead();
            while (temp != NULL) {
                temp = temp->getNext();
                edges++;
            }
        }
        cout << "Total vertices : " << vertices << endl;
        cout << "Total edges : " << edges << endl;
        cout << endl;
    }

    void getIsolatedNodes() {
        int counteeeer = 0;
        Node* temp;
        bool flag = true;
        for (int i = 0; i < totalVertices; i++) {
            flag = true;
            if (arr[i].getHead() == NULL) {
                for (int j = 0; j < totalVertices; j++) {
                    temp = arr[j].getHead();
                    while (temp != NULL) {
                        if (temp->getData() == arr[i].getId()) {
                            j = totalVertices + 1;
                            flag = false;

                        }
                        temp = temp->getNext();
                        if (j == totalVertices + 1) {
                            temp = NULL;
                        }
                    }
                }
                if (flag == true) {
                    counteeeer++;
                }
            }
        }
        cout << "There are " << counteeeer << " number of isolated nodes" << endl;
        cout << endl;
    }

    bool isPresent(int* visited, int id) {
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == id) {
                return true;
            }
        }
        return false;
    }

    void addId(int*& visited, int id) {
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == -1) {
                visited[i] = id;
                break;
            }
        }
    }

    int BFS(int src) {
        int* visited;
        int v;
        int counter = 0;
        Node* temp;
        visited = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            visited[i] = -1;
        }

        Queue q;
        q.enQueue(src);
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == -1) {
                visited[i] = src;
                break;
            }
        }

        while (!q.isEmpty()) {
            counter++;
            v = q.showFront();
            q.deQueue();
            for (int i = 0; i < totalVertices; i++) {
                if (arr[i].getId() == v) {
                    temp = arr[i].getHead();
                    while (temp != NULL) {
                        if (!isPresent(visited, temp->getData())) {
                            q.enQueue(temp->getData());
                            addId(visited, temp->getData());
                        }
                        temp = temp->getNext();
                    }
                }

            }
        }
        return counter;
    }

    void removeEdge(int start, int dest) {
        Node* temp;
        for (int i = 0; i < totalVertices; i++) {
            if (arr[i].getId() == start) {
                temp = arr[i].getHead();
                arr[i].setHead(temp->getNext());
                delete temp;
            }
        }
    }

    void bridgeEdge() {
        int* bfscount;
        int connections = 0;
        int numOfBridgeNodes = 0;
        int* edgeS = new int[edges];
        int* edgeD = new int[edges];
        for (int i = 0; i < edges; i++) {
            edgeS[i] = -1;
            edgeD[i] = -1;
        }
        bfscount = new int[totalVertices];
        for (int j = 0; j < totalVertices; j++) {
            //cout << j << endl;
            bfscount[j] = BFS(arr[j].getId());
            Node* temp = arr[j].getHead();
            while (temp != NULL) {
                connections++;
                temp = temp->getNext();
            }
            int new_bfsCount = 0;
            int tempid = 0;
            if (connections != 0) {
                for (int i = 0; i < connections; i++) {
                    if (arr[j].getHead() != NULL) {
                        tempid = arr[j].getHead()->getData();
                        removeEdge(arr[j].getId(), arr[j].getHead()->getData());
                        new_bfsCount = BFS(arr[j].getId());
                        if (new_bfsCount != bfscount[j]) {
                            //cout << arr[j].getId() << "--" << tempid << endl;
                            for (int k = 0; k < edges; k++) {
                                if (edgeS[k] == arr[j].getId() && edgeD[k] == tempid) {
                                    break;
                                }
                                if (edgeS[k] == -1 && edgeD[k] == -1) {
                                    edgeS[k] = arr[j].getId();
                                    edgeD[k] = tempid;
                                    break;
                                }
                            }
                        }
                        addEdge(arr[j].getId(), tempid);
                    }
                }
            }
        }
        for (int i = 0; i < edges; i++) {
            if (edgeD[i] != -1 && edgeS[i] != -1) {
                numOfBridgeNodes++;
            }
        }

        cout << "There are " << numOfBridgeNodes << " number of bridge edges" << endl;
        cout << endl;
    }

    int BFSforArticulation(int src, int parent) {
        int* visited;
        int v;
        int counter = 0;
        Node* temp;
        visited = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            visited[i] = -1;
        }

        Queue q;
        q.enQueue(src);
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == -1) {
                visited[i] = src;
                break;
            }
        }

        while (!q.isEmpty()) {
            counter++;
            v = q.showFront();
            q.deQueue();
            for (int i = 0; i < totalVertices; i++) {
                if (arr[i].getId() == v) {
                    temp = arr[i].getHead();
                    while (temp != NULL) {
                        if (!isPresent(visited, temp->getData())) {
                            q.enQueue(temp->getData());
                            addId(visited, temp->getData());
                        }
                        temp = temp->getNext();
                    }
                }

            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == parent) {
                return true;
            }
        }
        return false;
    }

    void articulationNodes() {
        int counter = 0;
        int* articulationPoints = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            articulationPoints[i] = -1;
        }
        Node* temp1;
        for (int i = 0; i < totalVertices; i++) {
            int id = arr[i].getId();
            for (int j = 0; j < totalVertices; j++) {
                Node* temp = arr[j].getHead();
                while (temp != NULL) {
                    if (temp->getData() == arr[i].getId()) {
                        counter++;
                    }
                    temp = temp->getNext();
                }
            }
            if (counter == 1) {
                for (int k = 0; k < totalVertices; k++) {
                    temp1 = arr[k].getHead();
                    while (temp1 != NULL) {
                        if (temp1->getData() == arr[i].getId()) {
                            if (BFSforArticulation(arr[i].getId(), arr[k].getId()) == 0) {
                                for (int l = 0; l < totalVertices; l++) {
                                    if (articulationPoints[l] == arr[k].getId()) {
                                        break;
                                    }
                                    if (articulationPoints[l] == -1) {
                                        articulationPoints[l] = arr[k].getId();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        temp1 = temp1->getNext();
                    }
                }
            }
            counter = 0;
        }

        int numOfArtPoints = 0;

        for (int l = 0; l < totalVertices; l++) {
            if (articulationPoints[l] != -1) {
                numOfArtPoints++;
            }
        }

        cout << "There are " << numOfArtPoints << " articulation nodes in this graph" << endl;
        cout << endl;

    }

    void outDegree() {
        int* count;
        Node* temp;
        count = new int[totalVertices];
        int index = 0;
        int* unique = new int[totalVertices];
        int* uniqueCount = new int[totalVertices];
        int t = 0;
        for (int i = 0; i < totalVertices; i++) {
            count[i] = 0;
            uniqueCount[i] = 0;
            unique[i] = -1;


        }

        for (int i = 0; i < totalVertices; i++) {
            temp = arr[i].getHead();
            while (temp != NULL) {
                temp = temp->getNext();
                count[i]++;
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (!isPresent(unique, count[i])) {
                unique[index] = count[i];
                index++;
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            t = unique[i];
            for (int j = 0; j < totalVertices; j++) {
                if (count[j] == t) {
                    uniqueCount[i] = uniqueCount[i] + 1;
                }
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (unique[i] == -1) {
                uniqueCount[i] = -1;
            }
        }

        cout << "OUTDEGREE DISTRIBUTION" << endl;
        cout << "Degree       Count" << endl;
        int ct = 0;
        for (int i = 0; i < totalVertices; i++) {
            ct = 0;
            if (uniqueCount[i] == -1 && unique[i] == -1) {
                break;
            }
            int b = unique[i];
            int a = uniqueCount[i];
            cout << unique[i];
            while (a > 9) {
                a = a / 10;
                ct++;
            }
            while (b > 9) {
                b = b / 10;
                ct++;
            }
            ct = 16 - ct;
            for (int i = 0; i < ct; i++) {
                cout << " ";
            }
            cout << uniqueCount[i];
            cout << endl;
        }
        cout << endl;


    }

    void indegree() {
        int counter = 0;
        int* indegree = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            int id = arr[i].getId();
            for (int j = 0; j < totalVertices; j++) {

                Node* temp = arr[j].getHead();
                while (temp != NULL) {
                    if (temp->getData() == arr[i].getId()) {
                        counter++;
                    }
                    temp = temp->getNext();
                }
            }
            indegree[i] = counter;
            counter = 0;
        }
        cout << "INDEGREE DISTRIBUTION" << endl;
        cout << "Degree       Count" << endl;
        int* unique = new int[totalVertices];
        int* num = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            unique[i] = -1;
            num[i] = 0;
        }
        int count = 0;
        for (int i = 0; i < totalVertices; i++) {
            if (!isPresent(unique, indegree[i])) {
                unique[count] = indegree[i];
                count++;
            }
        }
        for (int i = 0; i < totalVertices; i++) {
            if (unique[i] == -1) {
                break;
            }
        }
        for (int i = 0; i < totalVertices; i++) {
            for (int j = 0; j < totalVertices; j++) {
                if (indegree[i] == unique[j]) {
                    num[j]++;
                    break;
                }
            }
        }
        for (int i = 0; i < totalVertices; i++) {
            if (unique[i] == -1) {
                break;
            }
            cout << unique[i];
            int ct = 0;
            int b = unique[i];
            int a = num[i];
            while (a > 9) {
                a = a / 10;
                ct++;
            }
            while (b > 9) {
                b = b / 10;
                ct++;
            }
            ct = 16 - ct;
            for (int i = 0; i < ct; i++) {
                cout << " ";
            }
            cout << num[i] << endl;
        }
        cout << endl;
    }


    int shortestpathlength(int src, int dest) {
        int* visited;
        int v;
        int counter = 0;
        Node* temp;
        int index = 0;
        int* distances = new int[totalVertices];
        visited = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            visited[i] = -1;
            distances[i] = -1;
        }

        Queue q;
        q.enQueue(src);
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == -1) {
                visited[i] = src;
                distances[i] = 0;
                break;
            }
        }


        while (!q.isEmpty()) {

            v = q.showFront();
            q.deQueue();
            for (int i = 0; i < totalVertices; i++) {
                if (arr[i].getId() == v) {

                    index = 0;
                    temp = arr[i].getHead();
                    while (temp != NULL) {
                        if (!isPresent(visited, temp->getData())) {
                            q.enQueue(temp->getData());
                            //cout << temp->getData() << " ";
                            if (temp->getData() == dest) {
                                int a = 0;
                                for (int h = 0; h < totalVertices; h++) {
                                    if (visited[h] == arr[i].getId()) {
                                        a = distances[h] + 1;
                                    }
                                }
                                return a;
                            }
                            addId(visited, temp->getData());
                            for (int p = 0; p < totalVertices; p++) {
                                if (visited[p] == arr[i].getId()) {
                                    addId(distances, distances[p] + 1);
                                    break;
                                }
                            }
                        }
                        temp = temp->getNext();
                    }
                }
            }
        }
        return -2;
    }

    void displayshortestpathlength(int src, int dest) {
        cout << "The shortest path length is : " << shortestpathlength(src, dest) << endl << endl;
    }

    void shortestPathLengthDist(int src) {
        int* lengths = new int[totalVertices];
        int* lengthsCount = new int[totalVertices];
        int* uniqueLengths = new int[totalVertices];
        int length = 0;
        for (int i = 0; i < totalVertices; i++) {
            lengths[i] = -1;
            uniqueLengths[i] = -1;
            lengthsCount[i] = 0;
        }
        for (int i = 0; i < totalVertices; i++) {
            if (arr[i].getId() == src) {
                for (int j = 0; j < totalVertices; j++) {
                    if (i != j) {
                        length = shortestpathlength(arr[i].getId(), arr[j].getId());
                        addId(lengths, length);
                    }
                }
                break;
            }
        }
        int t = 0;
        int index = 0;
        for (int i = 0; i < totalVertices; i++) {
            if (lengths[i] == -1) {
                break;
            }
            if (!isPresent(uniqueLengths, lengths[i])) {
                uniqueLengths[index] = lengths[i];
                index++;
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (lengths[i] == -1) {
                break;
            }
            t = lengths[i];
            for (int j = 0; j < totalVertices; j++) {
                if (uniqueLengths[j] == t) {
                    lengthsCount[j] = lengthsCount[j] + 1;
                }
            }
        }
        cout << "SHORTEST PATH LENGTH DISTRIBUTION" << endl;
        cout << "Path Length        Count" << endl;
        int ct = 0;
        for (int i = 0; i < totalVertices; i++) {
            ct = 0;
            if (uniqueLengths[i] == -1) {
                break;
            }
            int b = uniqueLengths[i];
            int a = lengthsCount[i];
            if (b == -2) {
                cout << "Infinite";
                ct = ct + 7;
            }
            else {
                cout << uniqueLengths[i];
            }
            while (a > 9) {
                a = a / 10;
                ct++;
            }
            while (b > 9) {
                b = b / 10;
                ct++;
            }
            ct = 18 - ct;
            for (int i = 0; i < ct; i++) {
                cout << " ";
            }
            cout << lengthsCount[i];
            cout << endl;
        }
        cout << endl;
    }

    void diameter() {
        int max = 0;
        for (int i = 0; i < totalVertices; i++) {
            //cout << i << endl;
            for (int j = 0; j < totalVertices; j++) {
                //  cout << j << endl;
                if (i != j) {
                    int a = shortestpathlength(arr[i].getId(), arr[j].getId());
                    if (a > max) {
                        max = a;
                    }
                }
            }
        }

        cout << "DIAMETER OF GRAPH IS : " << max << endl << endl;
    }



    int* bfs_getvertices(int src) {//Out algorithm for scc
        int* vertices = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            vertices[i] = -1;
        }
        int* visited;
        int v;
        int counter = 0;
        Node* temp;
        int index = 0;
        visited = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            visited[i] = -1;
        }

        Queue q;
        q.enQueue(src);
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] == -1) {
                visited[i] = src;
                break;
            }
        }

        while (!q.isEmpty()) {
            counter++;
            v = q.showFront();
            //cout << v << " ";
            q.deQueue();
            for (int i = 0; i < totalVertices; i++) {
                if (arr[i].getId() == v) {
                    temp = arr[i].getHead();
                    while (temp != NULL) {
                        if (!isPresent(visited, temp->getData())) {
                            q.enQueue(temp->getData());
                            vertices[index] = temp->getData();
                            index++;
                            addId(visited, temp->getData());
                        }
                        temp = temp->getNext();
                    }
                }

            }
        }
        return vertices;
    }

    int* getIn(int src) {
        int* in = new int[totalVertices];
        int index = 0;
        int* temp = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            in[i] = -1;
            temp[i] = -1;
        }

        for (int i = 0; i < totalVertices; i++) {
            temp = bfs_getvertices(arr[i].getId());
            // cout << i << " ";
            if (isPresent(temp, src)) {
                in[index] = arr[i].getId();
                //cout << in[index];
                index++;

            }
        }

        return in;
    }

    int* getIntersection(int* in, int* out) {
        int* common = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            common[i] = -1;
        }
        int index = 0;

        for (int i = 0; i < totalVertices; i++) {
            /*if (in[i] == -1) {
                break;
            }*/
            for (int j = 0; j < totalVertices; j++) {
                if (in[i] == out[j]) {
                    common[index] = in[i];
                    index++;
                    break;
                }
            }
        }
        return common;
    }


    int** SCC() {
        int** scc = new int* [totalVertices];
        int* in = new int[totalVertices];
        int* out = new int[totalVertices];
        int* intersection = new int[totalVertices];
        int count = 0;
        int* visited = new int[totalVertices];
        for (int i = 0; i < totalVertices; i++) {
            scc[i] = new int[totalVertices];
            in[i] = -1;
            out[i] = -1;
            intersection[i] = -1;
            visited[i] = -1;
        }

        for (int i = 0; i < totalVertices; i++) {
            for (int j = 0; j < totalVertices; j++) {
                scc[i][j] = -1;
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (!isPresent(visited, arr[i].getId())) {
                in = getIn(arr[i].getId());
                out = bfs_getvertices(arr[i].getId());
                intersection = getIntersection(in, out);
                for (int k = 0; k < totalVertices; k++) {
                    if (intersection[k] != -1) {
                        for (int o = 0; o < totalVertices; o++) {
                            if (visited[o] == intersection[k]) {
                                break;
                            }
                            if (visited[o] == -1) {
                                visited[o] = intersection[k];
                                break;
                            }
                        }
                    }
                }
                if (intersection[0] != -1) {
                    scc[count][0] = arr[i].getId();
                    for (int k = 0; k < totalVertices; k++) {
                        if (visited[k] == arr[i].getId()) {
                            break;
                        }
                        if (visited[k] == -1) {
                            visited[k] = arr[i].getId();
                            break;
                        }
                    }

                }
                for (int j = 1; j < totalVertices; j++) {
                    if (intersection[j - 1] == -1) {
                        break;
                    }
                    scc[count][j] = intersection[j - 1];
                }
                count++;

                for (int i = 0; i < totalVertices; i++) {
                    intersection[i] = -1;
                }
            }
        }



        for (int i = 0; i < totalVertices; i++) {
            if (scc[i][0] == -1) {
                count = i;
                break;
            }
        }

        for (int i = 0; i < totalVertices; i++) {
            if (!isPresent(visited, arr[i].getId())) {
                scc[count][0] = arr[i].getId();
                count++;

                for (int k = 0; k < totalVertices; k++) {
                    if (visited[k] == arr[i].getId()) {
                        break;
                    }
                    if (visited[k] == -1) {
                        visited[k] = arr[i].getId();
                        break;
                    }
                }
            }
        }

        return scc;
    }

    void addVisited(int*& visited, int id) {
        for (int i = 0; i < totalVertices; i++) {
            if (visited[i] = id) {
                return;
            }
            if (visited[i] = -1) {
                visited[i] = id;
                return;
            }
        }
    }


    void sccdistribution() {
        int** scc = SCC();
        int count = 0;
        int* sizes = new int[totalVertices];
        int* sizesCount = new int[totalVertices];
        int max = 0;
        int t = 0;
        for (int i = 0; i < totalVertices; i++) {
            sizes[i] = -1;
            sizesCount[i] = 0;
            ;
        }
        for (int i = 0; i < totalVertices; i++) {
            if (scc[i][0] == -1) {
                break;
            }
            for (int j = 0; j < totalVertices; j++) {
                if (scc[i][j] == -1) {
                    break;
                }
                else {
                    count++;
                }
            }
            if (count > max) {
                max = count;
            }
            sizes[i] = count;
            count = 0;
        }

        //sizes= sizes of all scc's

        for (int i = 0; i < totalVertices; i++) {
            if (sizes[i] == -1) {
                break;
            }
            t = sizes[i];
            for (int j = 0; j < totalVertices; j++) {
                if (sizes[j] == t) {
                    sizesCount[i] = sizesCount[i] + 1;
                }
            }
        }
        cout << "Size of max SCC is : " << max << endl;
        cout << "SCC SIZE DISTRIBUTION" << endl;
        cout << "SCC SIZE       Count" << endl;
        int ct = 0;
        for (int i = 0; i < totalVertices; i++) {
            ct = 0;
            if (i > 0) {
                if (sizesCount[i - 1] == sizesCount[i] && sizes[i - 1] == sizes[i]) {
                    break;
                }
            }
            if (sizesCount[i] == 0 && sizes[i] == -1) {
                break;
            }
            int b = sizes[i];
            int a = sizesCount[i];
            cout << sizes[i];
            while (a > 9) {
                a = a / 10;
                ct++;
            }
            while (b > 9) {
                b = b / 10;
                ct++;
            }
            ct = 18 - ct;
            for (int i = 0; i < ct; i++) {
                cout << " ";
            }
            cout << sizesCount[i];
            cout << endl;
        }
        cout << endl;
    }

    void WCC() {
        //creating undirected graph
        ifstream file;
        int vertices, edges;
        int src, dest;
        int a;
        file.open("test.txt");
        if (!file) {
            cout << "File not opened" << endl;
        }
        else {
            file >> vertices;
            file >> edges;
            Graph g(vertices, edges);
            while (!file.eof()) {
                file >> src;
                file >> dest;
                g.addEdge_undir(src, dest);
            }
            int* visited = new int[totalVertices];
            int* wcc = new int[totalVertices];
            int* bfsvertices = new int[totalVertices];
            int count = 0;
            int index1 = 0;
            int index = 0;
            int* sizes = new int[totalVertices];
            int* unique = new int[totalVertices];
            int* uniqueCount = new int[totalVertices];
            int t = 0;
            for (int i = 0; i < totalVertices; i++) {
                visited[i] = -1;
                wcc[i] = -1;
                sizes[i] = 0;
                unique[i] = -1;
                uniqueCount[i] = 0;
            }
            int max = 0;
            for (int i = 0; i < totalVertices; i++) {
                count = 0;
                if (!isPresent(visited, g.arr[i].getId())) {
                    addId(visited, g.arr[i].getId());
                    count++;
                    bfsvertices = bfs_getvertices(g.arr[i].getId());
                    for (int j = 0; j < totalVertices; j++) {
                        if (bfsvertices[j] == -1) {
                            break;
                        }
                        addId(visited, bfsvertices[j]);
                        count++;
                    }
                    /*if (count == 1) {
                        cout << arr[i].getId();
                        cout << endl;
                    }*/
                    if (count > max) {
                        max = count;
                    }
                    sizes[index1] = count;
                    index1++;
                }
            }


            for (int i = 0; i < totalVertices; i++) {
                if (!isPresent(unique, sizes[i])) {
                    unique[index] = sizes[i];
                    index++;
                }
            }

            for (int i = 0; i < totalVertices; i++) {
                t = unique[i];
                for (int j = 0; j < totalVertices; j++) {
                    if (sizes[j] == t) {
                        uniqueCount[i] = uniqueCount[i] + 1;
                    }
                }
            }

            for (int i = 0; i < totalVertices; i++) {
                if (unique[i] == 0) {
                    uniqueCount[i] = 0;
                }
            }

            cout << "Size of max WCC is : " << max << endl;
            cout << "WCC SIZE DISTRIBUTION" << endl;
            cout << "WCC SIZE       Count" << endl;
            int ct = 0;
            for (int i = 0; i < totalVertices; i++) {
                ct = 0;
                if (uniqueCount[i] == 0 && unique[i] == 0) {
                    break;
                }
                int b = unique[i];
                int a = uniqueCount[i];
                cout << unique[i];
                while (a > 9) {
                    a = a / 10;
                    ct++;
                }
                while (b > 9) {
                    b = b / 10;
                    ct++;
                }
                ct = 18 - ct;
                for (int i = 0; i < ct; i++) {
                    cout << " ";
                }
                cout << uniqueCount[i];
                cout << endl;
            }
            cout << endl;
        }
    }

    void printGraph() {
        Node* temp;
        int id;
        for (int i = 0; i < totalVertices; i++) {
            id = arr[i].getId();
            temp = arr[i].getHead();
            cout << id << " : ";
            while (temp != NULL) {
                cout << temp->getData();
                if (temp->getNext() != NULL) {
                    cout << " -> ";
                }
                temp = temp->getNext();
            }
            cout << endl;
        }
        cout << endl;
    }
};