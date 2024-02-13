#include "vertex.h"
#include <iostream>
using namespace std;

int main()
{
	Vertex* gHead = nullptr; // The first vertex in the graph defaults
	
	addVertex(gHead, 'A');
	addVertex(gHead, 'B');
	addVertex(gHead, 'C');
	addVertex(gHead, 'D');
	addVertex(gHead, 'E');
	addVertex(gHead, 'F');
	
	addArc(gHead, 'A', 'B', 5); // Added weights to all arcs
	addArc(gHead, 'B', 'A', 5);
	
	addArc(gHead, 'B', 'C', 2);
	addArc(gHead, 'C', 'B', 2);
	
	addArc(gHead, 'B', 'E', 3);
	addArc(gHead, 'E', 'B', 3);
	
	addArc(gHead, 'C', 'E', 1);
	addArc(gHead, 'E', 'C', 1);
	
	addArc(gHead, 'C', 'D', 8);
	addArc(gHead, 'D', 'C', 8);
	
	addArc(gHead, 'E', 'D', 7);
	addArc(gHead, 'D', 'E', 7);
	
	addArc(gHead, 'E', 'F', 6);
	addArc(gHead, 'F', 'E', 6);
	
	printGraph(gHead);
	
	cout << "\nBreadth First Traversal\n";
	breadthFirst(gHead);
	
	cout << "\nDepth First Traversal\n";
	depthFirst(gHead);
	
	cout << "\nMST is\n";
	createMST(gHead);
	
	createShortestPath(gHead, 'A', 'F');
	
	return 0;
}