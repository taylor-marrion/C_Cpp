#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using std::string;

struct Vertex;
struct Arc;
struct Node; // For stack and queue

struct Vertex
{
	char data;
	Vertex* vNext;
	Arc* aHead;
	
	// New attributes for traversals and network algorithms
	// For Traversals.
	short processed; // 0 = Unvisited, 1 = in stack/queue, 2 = fully processed
	bool inTree; // For MST and shortest path
	int pathLength; // For shortest path
};

struct Arc
{
	Vertex* dest; // short for destination
	Arc* aNext;
	
	// New attributes for MST and shortest path
	int weight;
	bool inTree;
};

// For stack and queue used in traversals
struct Node
{
	Vertex* data;
	Node* next;
};

// Graph maintenance
void addVertex(Vertex*& vHead, char label);
void remVertex(Vertex*& vHead, char label);
void addArc(Vertex* vHead, char from, char to, int wgt); // added weight
void remArc(Vertex* vHead, char from, char to);
Vertex* findVertex(Vertex* vHead, char key);
void printGraph(Vertex* vHead);

// Traversals
void breadthFirst(Vertex* vHead);
void depthFirst(Vertex* vHead);

// Minimum Spanning Trees
void createMST(Vertex* vHead);
void printMST(Vertex* vHead);

// Shortest Path
void createShortestPath(Vertex* vHead, char from, char to);
void printShortestPath(Vertex* vPtr, char to, string path);

#endif