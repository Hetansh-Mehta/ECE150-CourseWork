//
//  SearchAndSort.cpp
//  Searching and Sorting Algorithms
//
//  Created by Hetansh Mehta on 12/13/18.
//  Copyright © 2018 Hetansh Mehta. All rights reserved.
//  References: Computer Science with C++ by Sumita Arora
//  ---------------------------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <string>

// function declarations
void f1();
int linear_search(int Array[], int size, int n);
void f2();
int binary_search(int Array[], int size, int n);
void f3();
void selection_sort(int L[], int size);
void f4();
void insertion_sort(int L[], int size);

int main()
{
    //f1();
    //f2();
    //f3();
    f4();
}
// The data needs to be aggregated and summarized in various meaningful ways to form information. It must be represented, stored, organized, processed, and managed so as to support the user environment.


// ELEMENTARY DATA REPRESENTATION
// Raw Data: are raw facts. These are simply values or set of values.
// Data Item: represents single unit of values of certain type.

// Data Type: a named group of data which share similar properties or characteristics and which have common behaviour among them. Data types can be fundamental or user defined. Exmples are: int, char, class, struct, str etc.
// Data Structure: is a named group of data of different data types which can be processed as a single unit. It has well defined operations, behaviour and properties. Examples: stacks, linked lists, tree, array, struct

// OPERATIONS ON DATA STRUCTURES
// 1) Insertion: addition of a new data element in a data structure.
// 2) Deletion: removal of a data element from a data structure. The data element is searched for before its removal.
// 3) Searching: searching for the specified data element in a data structure.
// 4) Traversal: processing all the data elements of a data structure.
// 5) Sorting: Arranging the data elements of a data structure in a specified order is called sorting
// 6) Merging: Combining elements of two similar data structures to form a new data structure of the same type

// ARRAYS
// Arrays store a list of finite number of homogeneous data elements (ie, data elements of the same type). It has a specific length.
// One dimensional array: a group of elements having same data type and same name. Individual elements are referred to using common name and unique index of the element.
// Syntax: Arrayname[size];         where size specifies the number of elements in the array.

// In memory, one dimensional arrays are implemented by allocating a sequence of addressed locations so as to accommodate all its elements. The starting address of the very first element of the array is called base address of the array. The elements of the array are given contiguous memory locations.

// LINEAR SEARCH
// Basic Idea: Each element of the array is compared with the given Item to be searched for, one by one sequentially. This process is also called sequential search (or) linear search.
// If the required item is at the end of the list, this process is time consuming as each element would be compared.

void f1()
{
    int Array[50], size, n, index;
    std :: cout << "Enter the size of the array (max 50): " << std :: endl;
    std :: cin >> size;
    std :: cout << "Enter array elements :" << std :: endl;
    for (int i=0; i<size; i++)
    {
        std :: cin >> Array[i];
    }
    std :: cout << "Enter the number to be searched for: " << std :: endl;
    std :: cin >> n;
    index = linear_search(Array, size, n);
    
    if (index == -1)
    {
        std :: cout << "Element not found" << std :: endl;
    }
    else
    {
        std :: cout << "Element found at index: " << index << " and position: " << index + 1 << std :: endl;
    }
}

int linear_search(int Array[], int size, int n)
{
    // Searching for the entered element inside the array
    for (int i=0; i<size; i++)
    {
        if (Array[i] == n)
        {
            return i;
        }
    }
    return -1;
    
}

// BINARY SEARCH
// The item is searched for in smaller segment (nearly half the previous segment) after every stage. This reduces the number of comparisions and hence saves time.
// NOTE: The array must be sorted in ascending/descending order in order to perform binary search.

void f2()
{
    int Array[50], size, n, index;
    std :: cout << "Enter the size of the array (max 50): " << std :: endl;
    std :: cin >> size;
    std :: cout << "Please enter the elements in ascending order" << std :: endl;
    for (int i=0; i<size; i++)
    {
        std :: cin >> Array[i];
    }
    std :: cout << "Enter the element to be searched for: " << std :: endl;
    std :: cin >> n;
    
    index = binary_search(Array, size, n);
    
    if (index == -1)
    {
        std :: cout << "Element not found" << std :: endl;
    }
    else
    {
        std :: cout << "Element found at index " << index << " position " << index + 1 << std :: endl;
    }
}

int binary_search(int Array[], int size, int n)
{
    int low,high,mid;
    low = 0;
    high = size - 1;
    
    while (low <= high)
    {
        mid = (low+high)/2;
        
        if (n == Array[mid])
        {
            return mid;
        }
        else if (n >= Array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


// SORTING ARRAYS
// Sorting an array means arranging the array elements in a specified order, ie, either ascending or descending order. There are several sorting techniques available, eg, shell sort, bubble sort, selection sort, quick sort, heap sort etc.
// We will be covering Selection sort, Insertion sort only.

// SELECTION SORT
// Key: Repeatedly select the smallest key in the remaining unsorted array (and swap it with the first element of the unsorted part of the array)

void f3()
{
    int L[50], size;
    std :: cout << "Enter the size of the array: " << std :: endl;
    std :: cin >> size;
    
    std :: cout << "Enter the elements" << std :: endl;
    for (int i=0; i<size; i++)
    {
        std :: cin >> L[i];
    }
    
    std :: cout << "Unsorted Array: " << L << std :: endl;
    selection_sort(L,size);
}

void selection_sort(int L[], int size)
{
    int min, temp;
    for (int i=0; i<size-1; i++)
    {
        min = i;
        for (int j=i+1; j<size; j++)
        {
            if (L[j] < L[min])
            {
                min = j;
            }
            temp = L[i];
            L[i] = L[j];
            L[j] = temp;
        }

    }
}


// Insertion Sort
// Key: It selects the next element to the right of what is already sorted. Then it slides up larger element until it gets to the correct location to insert into the sorted part of the array.

void f4()
{
    int L[50], size;
    std :: cout << "Enter size of array: " << std :: endl;
    std :: cin >> size;
    std :: cout << "Enter elements: " << std :: endl;
    for (int i=0; i<size; i++)
    {
        std :: cin >> L[i];
    }
    
    insertion_sort(L, size);
}

void insertion_sort(int L[], int size)
{
    int temp, ptr;
    for (int k=1; k<size; k++)
    {
        temp = L[k];
        ptr = k-1;
        while ((ptr>=0) and (L[ptr] > L[temp]))
        {
            L[ptr+1] = L[ptr];
            ptr --;
        }
        L[ptr+1] = temp;
    }
}

