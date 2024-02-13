#include <iostream>
#include "vertex.h"
using namespace std;

void addVertex(Vertex*& vHead, char label)
{
    // prevent duplicate Vertices
    // this works, but checking in the loop below would be more efficient
    /*Vertex* dupe = findVertex(vHead, label);
    if (dupe != nullptr) {
        cout << "Vertex <" << label << "> already exists." << endl;
        return;
    }*/

    Vertex* newVertex = new Vertex; // identical to LinkedList
    newVertex->data = label;
    newVertex->vNext = nullptr;
    newVertex->aHead = nullptr;

    if (vHead == nullptr) {
        vHead = newVertex;
        return;
    }

    if (vHead->data > label) {
        newVertex->vNext = vHead;
        vHead = newVertex;
        return;
    }

    Vertex* curVer = vHead;

    // modified to prevent duplicate Vertices ( < to <= )
    while (curVer->vNext != nullptr && curVer->vNext->data <= label) {
        curVer = curVer->vNext;
    }

    // prevent duplicate Vertices
    if (curVer->data == label) {
        cout << "Vertex <" << label << "> already exists." << endl;
        return;
    }

    // determine if curVer is null or not
    if (curVer->vNext == nullptr) {
        curVer->vNext = newVertex;
    } 
    else 
    {
        newVertex->vNext = curVer->vNext;
        curVer->vNext = newVertex;
    }
}   // end addVertex

void remVertex(Vertex*& vHead, char label)
{
    // Remove all incoming arcs as well as the vertex itself and its outgoing arcs

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

}   // end remVertex

void addArc(Vertex* vHead, char from, char to)
{
    // 1st step: Traverse to "from" Vertex

    Vertex* fromVer = findVertex(vHead, from);  /* EXTRA CREDIT */
    if (fromVer == nullptr) {
        cout << "Starting vertex <" << from << "> is not on the list" << endl;
        return;
    }

    Vertex* toVer = findVertex(vHead, to);  /* EXTRA CREDIT */
    if (toVer == nullptr) {
        cout << "Destination vertex <" << to << "> is not on the list" << endl;
        return;
    }

    Arc* newArc = new Arc;
    newArc->dest = toVer;
    newArc->aNext = nullptr;

    //
    if (fromVer->aHead == nullptr)
    {
        fromVer->aHead = newArc;
        return;
    }

    if (fromVer->aHead->dest->data > to)
    {
        newArc->aNext = fromVer->aHead;
        fromVer->aHead = newArc;
        return;
    }

    // Taverse down Arc list, insert in alphabetical order
    Arc* curArc = fromVer->aHead;

    while (curArc->aNext != nullptr && curArc->aNext->dest->data < to)
    {
        curArc = curArc->aNext;
    }

    // determine if curArc is null or not
    if (curArc->aNext == nullptr)
    {
        curArc->aNext = newArc;
    } 
    else
    {
        newArc->aNext = curArc->aNext;
        curArc->aNext = newArc;
    }

}   // end addArc

void remArc(Vertex* vHead, char from, char to)
{
    // First step: Find the "from vertex"

    Vertex* fromVer = findVertex(vHead, from);  /* EXTRA CREDIT */
    if (fromVer == nullptr) {
        cout << "Starting vertex <" << from << "> is not on the list" << endl;
        return;
    }

    Arc* curArc = fromVer->aHead;

    if (curArc == nullptr)
    {
        cout << "Arc head is null. There is no connection from " << from << " to " << to << endl;
        return;
    }

    if (curArc->dest->data == to)
    {
        Arc* deleteMe = curArc;
        fromVer->aHead = curArc->aNext;
        free(deleteMe);
        deleteMe = nullptr;
        return;
    }

    while (curArc->aNext != nullptr && curArc->aNext->dest->data < to)
    {
        curArc = curArc->aNext;
    }

    if (curArc->aNext == nullptr || curArc->aNext->dest->data > to)
    {
        cout << "There is no connection from " << from << " to " << to << endl;
        return;
    }
    else 
    {
        Arc* deleteMe = curArc->aNext;
        curArc->aNext = curArc->aNext->aNext;
        free(deleteMe);
        deleteMe = nullptr;
    }
}   // end remArc

Vertex* findVertex(Vertex* vHead, char key)
{
    Vertex* fromVer = vHead;
    while (fromVer != nullptr && fromVer->data < key)
    {
        fromVer = fromVer->vNext;
    }

    if (fromVer == nullptr || fromVer->data > key)
    {
        fromVer = nullptr;
    }

    return fromVer;

}   // end findVertex

void printGraph(Vertex* vHead)
{
    // Just implement vertex LL to start with
    Vertex* curVer = vHead;
    Arc* curArc;
    while (curVer != nullptr)
    {
        // always print "from" Vertex
        cout << curVer->data;

        // print "to" Arcs
        curArc = curVer->aHead;
        while (curArc != nullptr)
        {
            // save a few lines of code and checks
            cout << " -> " << curArc->dest->data ;

            curArc = curArc->aNext;
        }

        curVer = curVer->vNext;
        cout << endl;
    }
    cout << endl;
}   // end printGraph
