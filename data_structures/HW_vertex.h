#ifndef VERTEX_H
#define VERTEX_H

/*
 * covered in class
 */
struct Vertex;
struct Arc;

struct Vertex
{
    char data;
    Vertex* vNext;
    Arc* aHead;
};

struct Arc
{
    Vertex* dest;   // destination
    Arc* aNext;
};

void addVertex(Vertex*& vHead, char label);
//void remVertex(Vertex*& vHead, char label);
void addArc(Vertex* vHead, char from, char to);
void remArc(Vertex* vHead, char from, char to);
Vertex* findVertex(Vertex* vHead, char key);
void printGraph(Vertex* vHead);

/*
 * homework
 */
void remVertex(Vertex*& vHead, char label);

/*
 * utility functions
 */


#endif