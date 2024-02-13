#include <iostream>
#include "vertex.h"
using namespace std;

int main ()
{
    Vertex*  gHead = nullptr; // The first vertex in the graph

    cout << "Adding vertices" << endl;
    addVertex(gHead, 'A');
    addVertex(gHead, 'F');
    addVertex(gHead, 'C');
    addVertex(gHead, 'D');
    addVertex(gHead, 'E');
    addVertex(gHead, 'C');
    addVertex(gHead, 'B');

    printGraph(gHead);

    cout << "Adding arcs" << endl;
    addArc(gHead, 'A', 'B');
    addArc(gHead, 'B', 'C');
    addArc(gHead, 'B', 'E');
    addArc(gHead, 'C', 'E');
    addArc(gHead, 'C', 'D');
    addArc(gHead, 'E', 'D');
    addArc(gHead, 'E', 'F');
    addArc(gHead, 'A', 'Z');    // TEST
    addArc(gHead, 'Z', 'A');    // TEST

    printGraph(gHead);

    cout << "Removing arcs" << endl;
    remArc(gHead, 'C', 'D');
    remArc(gHead, 'E', 'F');
    remArc(gHead, 'A', 'F');
    remArc(gHead, 'F', 'Z');
    remArc(gHead, 'A', 'Z');
    remArc(gHead, 'Z', 'F');

    printGraph(gHead);

    cout << "Removing vertices" << endl;
    remVertex(gHead, 'E');
    remVertex(gHead, 'Z');

    printGraph(gHead);

    return 0;
}   // end main
