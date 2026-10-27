// Laura Mendes de Carvalho
// CSC 498 - Senior Project I
// Header for the node 
//******************************************************************************
#include <iostream>
#include <cstring>

//******************************************************************************

class Node {
    private: 
        unsigned int arrayCapacity;
        unsigned int arrayCount;
        int *array;
        int rank;
        const unsigned int expandSize = 5;

    public:
        Node();
        Node(int capacity, int rank);
        ~Node();
        bool expand(int expandSize); 
        bool quickSort(int array[]);

};


