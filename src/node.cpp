// Laura Mendes de Carvalho
// CSC 498 - Senior Project I

//******************************************************************************

#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

//******************************************************************************
Node::Node() {


}

//******************************************************************************
Node::Node(int capacity, int rank) {

    array = new int[capacity];
    node.rank = rank;
    node.aCapacity = capacity;

}

//******************************************************************************
Node::~Node() {
    delete[] array;


}

//******************************************************************************
bool Node::expand(unsigned int expandSize) {

    bool rc = false;

    int *newArray = new int[arrayCapacity + expandSize];

    if (newArray) {
        rc = true;

        // Copy elements to new array, starting at index 0
        for (unsigned int i = 0; i < listCount; i++) {
            newArray[i] = array[i];
        }

        delete [] array;

        array = newArray;
        listCapacity += expandSize;
    
    }
    
    return rc;
}

//******************************************************************************
bool Node::quickSort(int array[]) {
    bool rc = false;
    int pivot;

    //// Usar randomization pivot = array.size()/2;

    for (int i = 0; i < array.size(); i++) {
        if (pivot > )

    }


    return rc;

}