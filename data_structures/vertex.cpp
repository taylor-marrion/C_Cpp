#include "vertex.h"
#include "stack.h" // Added for depth first traversal
#include "queue.h" // Added for breadth first traversal
#include <iostream>
#include <climits> // for INT_MAX
#include <string>
using namespace std;

void addVertex(Vertex*& vHead, char label)
{
	Vertex* newVertex = new Vertex;
	newVertex->data = label;
	newVertex->vNext = nullptr;
	newVertex->aHead = nullptr;
	
	if(vHead == nullptr)
	{
		vHead = newVertex;
		return;
	}
	
	if(vHead->data > label)
	{
		newVertex->vNext = vHead;
		vHead = newVertex;
		return;
	}
	
	Vertex* curVer = vHead;
	
	while(curVer->vNext != nullptr && curVer->vNext->data < label)
	{
		curVer = curVer->vNext;
	}
	
	// Determine if curVer is null or not
	if(curVer->vNext == nullptr)
		curVer->vNext = newVertex;
	
	else
	{
		newVertex->vNext = curVer->vNext;
		curVer->vNext = newVertex;
	}
}


void remVertex(Vertex* vHead, char label)
{
	// Do for your homework assignment.
	// Remove all incoming arcs as well as
	// the vertex itself and its outgoing arcs

	// check if list is empty
    if (vHead == nullptr) {
        cout << "This list is empty!" << endl;
        return;
    }

    // find Vertex to be removed
    Vertex* deleteMe = findVertex(vHead, label);    /* EXTRA CREDIT */
    if (deleteMe == nullptr) {
        cout << "Vertex <" << label << "> is not on the list and cannot be deleted." << endl;
        return;
    }

    // remove all Arcs from deleteMe
    while (deleteMe->aHead != nullptr) {
        remArc(deleteMe, deleteMe->data, deleteMe->aHead->dest->data);
    }

    // check if vHead is to be deleted
    if (vHead == deleteMe) {
        vHead = vHead->vNext;
    }  // vHead cannot be deleteMe now

    // loop through all Vertecies
    Vertex* curVer = vHead; // cannot be deleteMe after above check
    while (curVer != nullptr) {
        // remove deleteMe from list
        if (curVer->vNext == deleteMe) {
            curVer->vNext = curVer->vNext->vNext;
        }

        // remove Arc going from curVer to deleteMe
        remArc(curVer, curVer->data, label);

        curVer = curVer->vNext;
    }

    // free Vertex
    free(deleteMe);
    deleteMe = nullptr;
}

void addArc(Vertex* vHead, char from, char to, int wgt) // Added weight
{
	// 1st Step: Traverse to "from" Vertex
	Vertex* fromVer = vHead;
	while(fromVer != nullptr && fromVer->data < from)
	{
		fromVer = fromVer->vNext;
	}
	
	if(fromVer == nullptr || fromVer->data > from)
	{
		cout << "Starting vertex is not in the list.\n";
		return;
	}
	
	Vertex* toVer = vHead;
	while(toVer != nullptr && toVer->data < to)
	{
		toVer = toVer->vNext;
	}
	
	if(toVer == nullptr || toVer->data > to)
	{
		cout << "Destination vertex is not in the list.\n";
		return;
	}
	
	Arc* newArc = new Arc;
	newArc->dest = toVer;
	newArc->aNext = nullptr;
	newArc->weight = wgt;    // adding weight to the arc
	
	if(fromVer->aHead == nullptr)
	{
		fromVer->aHead = newArc;
		return;
	}
	
	if(fromVer->aHead->dest->data > to)
	{
		newArc->aNext = fromVer->aHead;
		fromVer->aHead = newArc;
		return;
	}
	
	Arc* curArc = fromVer->aHead;
	
	while(curArc->aNext != nullptr && curArc->aNext->dest->data < to)
	{
		curArc = curArc->aNext;
	}
	
	// Determine if curArc is null or not
	if(curArc->aNext == nullptr)
		curArc->aNext = newArc;
	
	else
	{
		newArc->aNext = curArc->aNext;
		curArc->aNext = newArc;
	}
}

void remArc(Vertex* vHead, char from, char to)
{
	// First step: Find the "from vertex"
	Vertex* fromVer = vHead;
	while(fromVer != nullptr && fromVer->data < from)
	{
		fromVer = fromVer->vNext;
	}
	
	if(fromVer == nullptr || fromVer->data > from)
	{
		cout << "Starting vertex is not in the list.\n";
		return;
	}
	
	Arc* curArc = fromVer->aHead;
	if(curArc == nullptr)
	{
		cout << "Arc head is null. There is no connection between these vertices\n.";
		return;
	}
	
	if(curArc->dest->data == to)
	{
		Arc* dltPtr = curArc;
		fromVer->aHead = curArc->aNext;
		delete dltPtr;
		return;
	}
	
	while(curArc->aNext != nullptr && curArc->aNext->dest->data < to)
	{
		curArc = curArc->aNext;
	}
	
	if(curArc->aNext == nullptr || curArc->aNext->dest->data > to)
	{
		cout << "There is no connection between these vertices.\n";
		return;
	}
	
	else
	{
		Arc* dltPtr = curArc->aNext;
		curArc->aNext = curArc->aNext->aNext;
		delete dltPtr;
	}
	
}

Vertex* findVertex(Vertex* vHead, char key)
{
	while(vHead != nullptr)
	{
		if(vHead->data == key)
			return vHead;
		else
			vHead = vHead->vNext;
	}
	
	cout << key << " was not found.\n";
	return nullptr; // Temporary
}

void printGraph(Vertex* vHead)
{
	Vertex* curVer = vHead;
	Arc* curArc;
	// Just implement vertex LL to start with
	while(curVer != nullptr)
	{
		cout << curVer->data;
		if(curVer->aHead != nullptr)
			cout << " -> ";
		
		curArc = curVer->aHead;
		while(curArc != nullptr)
		{
			cout << curArc->dest->data;
			
			if(curArc->aNext != nullptr)
				cout << " -> ";
			
			curArc = curArc->aNext;
		}
		
		curVer = curVer->vNext;
		cout << endl;
	}
	cout << endl;
}

void breadthFirst(Vertex* vHead)
{
	Vertex* vWalkPtr;
	Vertex* vPtr;
	Vertex* vToPtr;
	Arc* aWalkPtr;
	Queue queue;
	initQueue(queue);
	
	// If graph is empty, get on out.
	if(vHead == nullptr)
		return;
	
	// Reset all previous "processed" attributes to 0
	vWalkPtr = vHead;
	while(vWalkPtr != nullptr)
	{
		vWalkPtr->processed = 0;
		vWalkPtr = vWalkPtr->vNext;
	}
	
	// Begin processing the list
	vWalkPtr = vHead;
	while(vWalkPtr != nullptr)
	{
		if(vWalkPtr->processed == 0) // If vertex is unprocessed
		{
			enqueue(queue, vWalkPtr); // Place vertex in queue
			vWalkPtr->processed = 1;  // Update that vertex is in queue
		}
		
		// process descendants of vertex at queue front
		while(queue.front != nullptr)
		{
			// Retrieve vertex from queue, output its data, and update processed attribute
			dequeue(queue, vPtr);
			cout << vPtr->data << '\t';
			vPtr->processed = 2;
			
			// Enqueue all adjacent vertices that haven't been processed yet
			aWalkPtr = vPtr->aHead;
			while(aWalkPtr != nullptr)
			{
				vToPtr = aWalkPtr->dest;
				if(vToPtr->processed == 0)
				{
					enqueue(queue, vToPtr);
					vToPtr->processed = 1;
				}
				aWalkPtr = aWalkPtr->aNext;
			}
		}
		vWalkPtr = vWalkPtr->vNext;
	}
}


void depthFirst(Vertex* vHead)
{
	Vertex* vWalkPtr;
	Vertex* vPtr;
	Vertex* vToPtr;
	Stack stack;
	initStack(stack);
	Arc* aWalkPtr;
	
	// If graph is empty, get on out.
	if(vHead == nullptr)
		return;
	
	// Reset all previous "processed" attributes to 0
	vWalkPtr = vHead;
	while(vWalkPtr != nullptr)
	{
		vWalkPtr->processed = 0;
		vWalkPtr = vWalkPtr->vNext;
	}
	
	// Begin processing the list
	vWalkPtr = vHead;
	while(vWalkPtr != nullptr)
	{
		if(vWalkPtr->processed == 0) // If vertex is unprocessed
		{
			pushStack(stack, vWalkPtr); // Place vertex in stack
			vWalkPtr->processed = 1;  // Update that vertex is in stack
		}
		
		// process descendants of vertex at stack front
		while(stack.top != nullptr)
		{
			// Retrieve vertex from stack, output its data, and update processed attribute
			popStack(stack, vPtr);
			cout << vPtr->data << '\t';
			vPtr->processed = 2;
			
			// Push all adjacent vertices that haven't been processed yet to stack
			aWalkPtr = vPtr->aHead;
			while(aWalkPtr != nullptr)
			{
				vToPtr = aWalkPtr->dest;
				if(vToPtr->processed == 0)
				{
					pushStack(stack, vToPtr);
					vToPtr->processed = 1;
				}
				aWalkPtr = aWalkPtr->aNext;
			}
		}
		vWalkPtr = vWalkPtr->vNext;
	}
}


void createMST(Vertex* vHead)
{
	if(vHead == nullptr)
		return;
	
	Vertex* vPtr = vHead;
	Arc* aPtr;
	
	// Set all vertices and arcs to not in MST
	while(vPtr != nullptr)
	{
		vPtr->inTree = false;
		aPtr = vPtr->aHead;
		while(aPtr != nullptr)
		{
			aPtr->inTree = false;
			aPtr = aPtr->aNext;
		}
		vPtr = vPtr->vNext;
	}
	
	// Create MST
	bool treeComplete = false;
	Arc* minAPtr;
	int minArc;
	
	vPtr = vHead;
	vPtr->inTree = true;
	
	while(treeComplete == false)
	{
		treeComplete = true; // Switch to false if we add a new arc/vertex
		vPtr = vHead;
		minArc = INT_MAX; // Be sure to #include <climits>
		minAPtr = nullptr;
		
		while(vPtr != nullptr)
		{
			if(vPtr->inTree == true && vPtr->aHead != nullptr)
			{
				aPtr = vPtr->aHead;
				while(aPtr != nullptr)
				{
					if(aPtr->dest->inTree == false)
					{
						treeComplete = false;
						if(aPtr->weight < minArc)
						{
							minArc = aPtr->weight;
							minAPtr = aPtr;
						}
					}
					aPtr = aPtr->aNext;
				}
			}
			vPtr = vPtr->vNext;
		}
		
		if(minAPtr != nullptr)
		{
			minAPtr->inTree = true;
			minAPtr->dest->inTree = true;
		}
	}
	
	printMST(vHead);
}


void printMST(Vertex* vHead)
{
	Vertex* vPtr = vHead;
	Arc* aPtr = nullptr;
	
	while(vPtr != nullptr)
	{
		cout << vPtr->data;
		aPtr = vPtr->aHead;
		
		while(aPtr != NULL)
		{
			if(aPtr->inTree)
				cout << " -> " << aPtr->dest->data << ':' << aPtr->weight;
			
			aPtr = aPtr->aNext;
		}
		
		cout << endl;
		vPtr = vPtr->vNext;
	}
}

void createShortestPath(Vertex* vHead, char from, char to)
{
	if(vHead == nullptr)
		return;
	
	Vertex* vPtr = vHead;
	Arc* aPtr;
	
	// Set all vertices and arcs to not in MST
	while(vPtr != nullptr)
	{
		vPtr->inTree = false;
		vPtr->pathLength = 10000; // Be sure to #include <climits>
		aPtr = vPtr->aHead;
		while(aPtr != nullptr)
		{
			aPtr->inTree = false;
			aPtr = aPtr->aNext;
		}
		vPtr = vPtr->vNext;
	}
	
	// Create shortest path
	bool treeComplete = false, destFound = false;
	Arc* minAPtr, *pathPtr;
	int minArc, minPath, newPathLength;
	
	vPtr = findVertex(vHead, from);
	vPtr->inTree = true;
	vPtr->pathLength = 0;
	
	while(treeComplete == false)
	{
		treeComplete = true; // Switch to false if we add a new arc/vertex
		vPtr = vHead;
		minAPtr = nullptr;
		newPathLength = 10000;
		pathPtr = nullptr;
		
		while(vPtr != nullptr)
		{
			if(vPtr->inTree == true && vPtr->aHead != nullptr)
			{
				aPtr = vPtr->aHead;
				minPath = vPtr->pathLength;
				minArc = 10000;
				while(aPtr != nullptr)
				{
					if(aPtr->dest->inTree == false)
					{
						treeComplete = false;
						if(aPtr->weight < minArc)
						{
							minArc = aPtr->weight;
							minAPtr = aPtr;
						}
					}
					aPtr = aPtr->aNext;
				}
				
				// Test for shortest pathLength
				if(minPath + minArc < newPathLength)
				{
					newPathLength = minPath + minArc;
					pathPtr = minAPtr;
				}
			}
			vPtr = vPtr->vNext;
		}
		
		if(pathPtr != nullptr)
		{
			pathPtr->inTree = true;
			pathPtr->dest->inTree = true;
			pathPtr->dest->pathLength = newPathLength;
			
			// Optional if we want to stop at a specific destination
			if(pathPtr->dest->data == to)
			{
				destFound = true;
				treeComplete = true;
			}
		}
	}
	
	if(destFound == true)
	{
		cout << "\nShortest path from " << from << " to " << to << " found. Prepare to print\n";
		
		printShortestPath(findVertex(vHead, 'A'), to, "");
	}
	else
		cout << "\nNo path from " << from << " to " << to << " exists.\n";
}

// Implement memoization someday
void printShortestPath(Vertex* vPtr, char to, string path)
{
	if(vPtr->data == to)
	{
		path = path + to;
		cout << path;
	}
	else
	{
		path = path + vPtr->data;
		Arc* aPtr = vPtr->aHead;
		while(aPtr != nullptr)
		{
			if(aPtr->inTree == true)
				printShortestPath(aPtr->dest, to, path);
			
			aPtr = aPtr->aNext;
		}
	}
}





























