//
//  LinkedList.cpp
//
//  Created by Hetansh Mehta on 12/3/18.
//  Copyright © 2018 Hetansh Mehta. All rights reserved.
//  References: Computer Science with C++ by Sumita Arora
//  The theory and the examples have been taken from the above mentioned source. This file is meant for study and 
//  understanding purposes only. 

#include <iostream>
#include <string>
#include <cmath>

// function declarations
void f1();

// function definitions
int main()
{
    f1();
}

// LINKED LISTS
// The term list refers to a linear collection of data.
// A list can also be stored as having data elements pointing to the next in the sequence (i.e., linked allocation) - a linked list.
// A linked list is a linear collection of data elements, called nodes pointing to the next nodes by means of pointers.

// Each node is divided into two parts: the first part containing information of the element, and the second part called the link or next pointer containing the address of the next node in the list.

// NEED FOR LINKED LIST
// An array can be used only when its number of elements along with the element sizes are predetermined, since the memory is reserved before processing. For this reason arrays are also called static data structures.
// Linked lists overcome the drawbacks of arrays as in a linked lists number of elements need not be predetermined, more memory can be allocated or released during the processing as and when required, making insertions and deletions much easier and simpler.
// Each element in a linked list stores the address of the following element.

// A singly linked list contains a node with single pointer pointing to the next node in sequence whereas a doubly linked list contains two pointers, one pointing to previous node and the other to the next node in sequence.

// MEMORY ALLOCATION - DYNAMIC vs STATIC
// Each data element which is stored has been allocated some memory. The memory allocation is either static or dynamic.

// Static Memory Allocation: reserves fixed amoint of memory before actual processing takes place, therefore, the number of elements to be stored must be predetermined. Arrays are allocated memory using this technique.
// Dynamic Memory Allocation: facilitates allocation of memory during the program execution itself. It also facilitates release of memory, if memory is not required anymore. Data structures like linked lists use this technique.

// SINGLY LINKED LIST
// In C++, every program is provided with a pool of unallocated memory that it may utilize during execution. This memory is knows as free storage memory (heap). Free store memory is allocated by applying operator new to a type specifier and which returns a pointer pointing tp the allocated memory.

// To allocate memory for a node of a linked list the following statements are given:
void f1()
{
    struct Node
    {
        char info[15];          // declare variable forming the info part
        Node *nextptr;             // pointer that will point to the next node
    };
    
    Node *ptr;                  // pointer that will point to the newly allocated memory
    ptr = new Node;             // allocate memory to hold a node and make ptr point to it.
    // Here, ptr is pointing to the first node (As we have dynamically allocated it)
    // nextptr can be used to point towards the next node
    
    // To refer to the info part:
    std :: cout << ptr ->info << std :: endl;
    // To refer to the next pointer:
    std :: cout << ptr ->nextptr << std :: endl;
    
    // Deleting is required to avoid memory leaks
    delete ptr;                 // delets the dynamically allocated node
}

// BASIC OPERATION ON SINGLY LINKED LISTS
// Operations like searching, insertion, deletion, traversal, reversal, splitting and concatenation can be performed on a linked list.
// We shall discuss insertion (in the beginning and in the end), deletion (from the beginning), and traversal.

// INSERSTION
// 1) In the beginning of the list
// Let us assume the pointer START is pointing towards the first ITEM of the list.
// TO insert a new item at the beginning, START is modified to point to the new node of ITEM and the next pointer of new node (ie, new ITEM's node) is made to point to the previous first node. (Better to draw it on paper and visualize)

// 2) At the end of the list
// The next pointer of the last node is made to point to the new ITEM's node and the next pointer of new ITEM's node is made nullptr.
// Again, it is better to draw it on paper and visualize.

// It's only when we are inserting in a sorted list, we have to determine the right position for insertion, which may be beginning, end or middle. This is obtained by comparing the dereferenced value of the two pointers in a list and then adding the new ITEM at the appropriate place. We can imagine that if the new ITEM is supposed to be added at the 3rd index, the dereferenecd values of the 2nd and the 4th indeces can be compared. At the same time, we need to modify the next pointer of the 2nd index to point towards the new ITEM and the ITEM's next pointer point to the 4th index's pointer. (Visualize by drawing it on a paper)


class List
{
private:
    struct node
    {
        int data;
        node* next;
    };
    node* head;
    node* current;
    node* temp;
    
public:     // This is where the functions go
    List();
    ~List();
    void AddNodeAtEND(int addData);
    void AddNodeAtBEGINNING(int addData);
    void DeleteNode(int delData);
    void PrintList();
};

List :: List()              // constructor
{
    head = nullptr;
    current = nullptr;
    temp = nullptr;
}

void List:: AddNodeAtEND(int addData)
{
    node* n = new node;                             // creating a new node and making n point the new node
    n ->next = nullptr;
    n ->data = addData;
    
    if (head == nullptr)                    // If list is empty
    {
        head = n;
    }
    else                                    // If list != empty
    {
        current = head;
        while (current -> next != nullptr)
        {
            current = current ->next;
        }
        current ->next = n;
    }
    
}

void List:: AddNodeAtBEGINNING(int addData)
{
    node* n = new node;
    n-> data = addData;
    n-> next = head;
    head = n;
}

void List:: DeleteNode(int delData)             // find a node which contains the value passed by the delData and delete it
{
    node* delptr = nullptr;                 // new pointer named delptr
    temp = head;
    current = head;
    // Loop to advance the two pointers
    while ((current != nullptr)&&(current ->data != delData))          // this will happen when it has traversed through the entire list
                                                                       // the while loop basically breaks when either of the condition is false... i.e, current becomes nullptr or delData matches the required data in the node
    {
        temp = current;
        current = current ->next;
    }
    if (current == nullptr)
    {
        std :: cout << delData << " was not in the list!" << std :: endl;
        delete delptr;
    }
    else                                                    // when we find the node
    {
        delptr = current;
        current = current ->next;
        temp -> next = current;
        delete delptr;
        std :: cout << "The value " << delData << " was deleted" << std :: endl;
    }
}

void List:: PrintList()
{
    current = head;
    while (current != nullptr)
    {
        std :: cout << "Data: " << current -> data << std :: endl;
        current = current ->next;
    }
}

List :: ~ List()
{
    current = head = temp = nullptr;
    delete current;
    delete head;
    delete temp;
}
