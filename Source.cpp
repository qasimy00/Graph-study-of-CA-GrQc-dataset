#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void clrscr() {
	system("cls");
}

int main() {
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
			g.addEdge(src, dest);
		}
		cout << "Welcome!" << endl;
		int srcinput;
		int destinput;
		int choice;
		char cont;
		while (1) {
			cout << "Enter your choice!" << endl;
			cout << "Enter 1 for number of nodes & edges" << endl;
			cout << "Enter 2 for number of source nodes" << endl;
			cout << "Enter 3 for number of sink nodes" << endl;
			cout << "Enter 4 for number of isolated nodes" << endl;
			cout << "Enter 5 for number of bridge edges" << endl;
			cout << "Enter 6 for number of articulation nodes" << endl;
			cout << "Enter 7 for shortest path length between any 2 nodes" << endl;
			cout << "Enter 8 for shortest path length distribution of any node" << endl;
			cout << "Enter 9 for the diameter of the graph" << endl;
			cout << "Enter 10 for in-degree distribution table" << endl;
			cout << "Enter 11 for out-degree distribution table" << endl;
			cout << "Enter 12 for Max SCC and SCC size distribution table" << endl;
			cout << "Enter 13 for Max WCC and WCC size distribution table" << endl;
			cout << "Enter 14 to exit" << endl;
			cin >> choice;
			if (choice == 14) {
				cout << "Goodbye!:D" << endl;
				return 0;
			}
			if (choice > 14 || choice < 1) {
				clrscr();
				cout << "Invalid input ! " << endl;
				continue;
			}
			if (choice == 8) {
				cout << "From Node - ID : ";
				cin >> srcinput;
				g.shortestPathLengthDist(srcinput);
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 1) {
				g.getVerticesEdges();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 2) {
				g.sourceNodes();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 3) {
				g.sinkNodes();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 4) {
				g.getIsolatedNodes();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 5) {
				g.bridgeEdge();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 6) {
				g.articulationNodes();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 7) {
				cout << "From Node-ID : ";
				cin >> srcinput;
				cout << endl;
				cout << "To Node-ID : ";
				cin >> destinput;
				cout << endl;
				g.displayshortestpathlength(srcinput, destinput);
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 9) {
				g.diameter();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 10) {
				g.indegree();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 11) {
				g.outDegree();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 12) {
				g.sccdistribution();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
			if (choice == 13) {
				g.WCC();
				cout << "Do you want to continue? (y/n)" << endl;
				while (1) {
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						clrscr();
						break;
					}
					else if (cont == 'N' || cont == 'n') {
						cout << "Goodbye! :D" << endl;
						return 0;
					}
					else {
						cout << "Invalid input!" << endl;
					}
				}
			}
		}
	}

	return 0;
}