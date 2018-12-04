//     Author: Hetansh Mehta
//      Date: December 3, 2018.
// References: Sumita Arora - Computer Science with C++ for Class 12
// Copyright - All Rights Reserved.

#include <iostream>
#include <string>
#include <cmath>
 
// function declaration
int main();
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
void f9();
void f10();
void f11();
void f12();
void f13();
void f14();
void f15();
void f16();
void f17();
void f18();
void f19();
void f20();

// POINTERS in C++

// A pointer is a variable that holds a memory address, usually the location of another variable in memory.
// Uses :
// 1) Pointers provide the means through which the memory location of a variable can be directly accessed and hence can be manipulated in the way as required
// 2) Pointers support C++'s dynamic memory allocation routines
// 3) Pointers can improve the efficiency of certain routines

// Every byte (8bits) in the computer's memory has an address.
// A variable storing a memory address is called a pointer as it points to a specific memory location whose address it is storing under its name.

// C++ memory map
// After compiling a program, C++ creates four logically distinct regions of memory that are used for four distinct specific functions.
// - One region in the memory holds the compiled code of the program. Every instruction and every function of the program starts at a particular address
// - The next region is the memory area where the global variables of the program are stored. Global variables remain in the memory as long as program continues.
// - The third region known as STACK, is used for holding the return addresses at function calls, arguments passed to functions, and local variables for the functions. The local variables remain in memory as long as the function continues and after that they are erased from the memory. The stack also stores the current state of the CPU.
// - The HEAP memory area is the region of free memory from which chunks of memory are allocated via C++'s dynamic memory allocation functions.

// Free Store
// It is a pool of unallocated heap memory given to a program that it may utilize during ececution.
// Free store memory is dynamically allocated during run time and static memory allocation takes place during compile-time.
// Objects allocated on the free store are manipulated indirectly through pointers.
// Dynamically allocated objects do not have any predefined scope. They remain in memory until explicitly removed using delete.

// Static Memory Allocation
// When the amount of memory to be allocated is known beforehand and the memory is allocated during compilation itself, it is referred to as static memory allocation.
//  int i;      computer knows that we need 4 bytes to store an int, so the compiler allocates memory for variable i during compile time itself

// Dynamic Memory Allocation
// When the amount of memory to be allocated is not known beforehand rather it is required to allocate (main) memory as and when the program runs (runtime) is called dynamic memory allocation.
// Operators for dynamically allocating memory- new and delete.

// new: allocates the memory dynamically and returns a pointer storing the memory address of the allocated memory
// delete: deallocates the memory pointed by the given pointer

// Declaration and Initialization of Pointers
// Syntax: datatype *variable-name;
// example:
int *iptr = nullptr;      // creates an integer pointer iptr
char *cptr = nullptr;     // creates a character pointer cptr
float *fptr = nullptr;    // creates a float pointer fptr
// When we say that iptr is an integer pointer, it means that the memory location being pointed to by iptr can hold only integer values. So, iptr is a pointer to integer.
// Similarly, in the above declarations, cptr is a pointer to a character and fptr is a pointer to a floating-point value.

// Two special operators * and & are used with pointers.
// The & is a unary operator that returns the memory address of its operand. For example,

int i = 25;
int *ptr = &i;  // stores the memory address of i into ptr.
// The expression &i returns an pointer to the integer value because i is an integer.

// The * operator returns the value of the variable located at the address following it(*-). Using * operator, changing/accessing value being pointed to by pointer (its state) is called dereferencing.
// Dereferencing refers to changing/acessing state of the pointer.

int main()
{
    std :: cout << *ptr << std :: endl;         //dereferencing of pointer
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    f7();
    f8();
//  f9();        Do not call f9()
//  f10();       Do not call f10()
//  f11();       Do not call f11()
    f12();
    f13();
    f14();
    f15();
    f16();
    f17();
    f18();
    f19();
    f20();
    return 0;
}


// Making an int point (2bytes) point towards a floating point value (4bytes) might lead to loss of data. Thus, we must ensure that the pointer points towards the correct type of data to prevent loss of information.
// Pointer variables must not remain uninitialized since uninitialized pointers causes the system to crash. Therefore, we must always initialize it with nullptr.
int a = 10;
int *aptr = nullptr;    // aptr gets initialized but does not point to a legal address

void f1()
{
    if (aptr != nullptr)    // we can use the pointer to a legal address
    {
        aptr = &a;          // assigning the memory address of the integer a
    }
}


// Exercise.
int *p{nullptr}, *q{nullptr};     // declaring two int pointers
int z;                            // integer

void f2()
{
    p = &z;
    *p = 63;
//  *q = 33;                                    // THIS CRASHES as q is not legally pointing anywhere
    std :: cout << "p: " << p << std :: endl;   // returns the memory address of 63
    std :: cout << "*p: " << *p << std :: endl; // returns the variable that the pointer is pointing to, i.e., prints 63
    q = p ;                                     // legally initializing q
    std :: cout << "q: " << q << std :: endl;   // returns the memory address of 63 ( same as p )
    std :: cout << "*q: " << *q << std :: endl; // prints the value stored at the address, i.e., prints 63
    *q = 33;
    std :: cout << "change *q: " << *q << std :: endl; // prints 33
    std :: cout << "change *p: " << *p << std :: endl; // pritns 33
}

// POINTER ARITHMETIC
// Only addition and subtraction mau be performed on pointers. When we add 1 to a pointer, we are actually adding the size of whatever the pointer is pointing at. That is, each time a pointer is incremented by 1, it points to the memory location of the next element of its base type.

// Let iptr be an integer pointer pointing to a memory address of 1000
// iptr+1 will be pointing to the memory address of 1002. (size of int = 2 bytes)
// iptr+2 will be pointing to the memory address of 1004. (size of 2int = 4 bytes)

// Let cptr be a character pointer pointing to a memory address of 20
// cptr+1 will be pointing towards the address 21 (size of char = 1 byte)
// cptr+4 will be pointing towards the address 24 (size of 4char = 4 bytes)

// A pointer holds the address of the very first byte of the memory location where it is pointing to. The address of the first byte is knows as Base Address.
// Consider the example:

// 200    2001    2002    2003    2004  is the memory
// float f = 17.32;     (size of float = 4bytes, Therefore, it occupies the above four bytes)
// float *fptr = &f;
// The pointer fptr will contain the base address of f, i.e., 200. It will not contain the other addresses.

// DYNAMIC ALLOCATION OPERATORS
// Dynamic allocation is the means by which a program can obtain memory during runtime. It obtains memory for allocation from the free store, the pool of unallocated heap memory provided to the program.

// USING OPERATOR NEW
// Syntax: pointer-variable = new data-type;
int *intptr = nullptr;      // declaring new int pointer
int *newptr = new int (33); // Newly allocated memory initialized at the time of allocation itself.
void f3()
{
   intptr = new int;       // The new operator allocates new memory of size equal to size of specified data type
                          // and return a pointer pointing to the base address of the newly allocated area.
    *intptr = 21;          // storing 21 to the newly allocated area.
    
    // Alternatively,
    //int ab = 33;
    std :: cout << "intptr: " << intptr << std :: endl;         // prints the new memory address of 21
    std :: cout << "&intptr: " << &intptr << std :: endl;       // prints the address of the pointer intptr / prints the value stored in the pointer
    std :: cout << "*intptr: " << *intptr << std :: endl;       // prints the value stored in the new address, dereferencing gives the value
    std :: cout << "newptr: " << newptr << std :: endl;         // prints the new memory address of 21
    std :: cout << "&newptr: " << &newptr << std :: endl;       // prints the address of the pointer newptr / prints the value stored in the pointer
    std :: cout << "*newptr: " << *newptr << std :: endl;       // prints the value stored in the new address, dereferencing gives the value
    delete newptr;
    delete intptr;
}

// CREATING DYNAMIC ARRAY
// The operator new can also allocate memory for user-defined types like structures, arrays, and classes.
// To allocate memory for one dimensional array:
// Syntax: pointer-variable = new data-type[size];      where size is the size of the 1D array.
// All array sizes must be supplied in square brackets [] when new is used for array creation.
// Example:
int *value = new int [5];                        // It will create memory space from the free store for an array of 5 integers
int *nvalue = new int [5] {11,12,13,14,15};     // Initialize dynamic arrays with an initialize list
void f4()
{
    delete [] value;
    delete [] nvalue;
}

// DELETE OPERATOR
// When an object, created through new, is no longer needed, it must be destroyed so that the memory space occupied by it may be resealsed for reuse. This can be done with the help of the delete operator.

// Syntax: delete pointer-variable;
//                                      where pointer-variable is the pointer that points to a data object created with new.
// The arrays allocated through new are freed using the following form:
// Syntax: delete [size] pointer-variable;
//                                      where size is the number of elements in the array being pointer to by the pointer-variable
// Syntax: delete [] array-pointer-variable;        is also used in recent C++ versions
// check the above few functions to see how we've deleted the newly allocated memory :) .
// REMEMBER: The lifetime of an object created by new is not restricted to the scope in which it is created. It lives in the memory until explicitly deleted using the delete operator.

// Program to create two arrays to store roll numbers and marks of some students, whose number would be known at runtime.
void f5()
{
    int size;
    std :: cout << "Enter the number of students: " << std :: endl;
    std :: cin >> size;
    int *rollno = new int [size];        // dynamic memory allocation of an array rollno of size [size]
    int *marks = new int [size];         // dynamic memory allocation of an array marks of size [size]
    
    for (int i=0; i<size; i++)           // input
    {
        std :: cout << "Enter rollno of student " << i+1 << " :" << std :: endl;
        std :: cin >> rollno[i];
        std :: cout << "Enter marks of student " << i+1 << " :" << std :: endl;
        std :: cin >> marks[i];
    }
    
    std :: cout << "RollNO" << "\t \t" << "Marks" << std :: endl;
    for (int i=0; i<size; i++)
    {
        std :: cout << rollno[i] << "\t \t \t" << marks[i] << std :: endl;
    }
    delete [] rollno;       // deleting array rollno[]
    delete [] marks;        // deleting array marks[]
}

// MEMORY LEAKS
// Improper use of new and delete may lead to memory leaks. Make sure the memory allocated through new must be properly deleted through delete.
// A certain function that dynamically allocates memory to some object but forgets to deallocate the reserved memory, consumes some amount of memory every time it is executed. Thus, a part of the memory disappears with its every run, and eventually the amount of memory consumed has an adverse effect on the system. This situation is known as a memory leak.

// POINTERS AND ARRAYS
// Arrays and pointers are closely linked. In most contexts, C++ treats the name of an array as if it were a pointer, i.e., memory address of some element. C++ interprets an array name as the address of its first element.
// Illustration
void f6()
{
    int *a{nullptr};        // a is a pointer to an integer
    int age [10];           // age is an array holding 10 integers
    std :: cout << "Enter values of the array " << std :: endl;
    for (int i=0; i<10; i++)
    {
        std :: cin >> age[i];
    }
    a = age;        // making pointer a point towards the location where age points to
                    // age is a pointer pointing to age[0]
    std :: cout << std :: endl;
    std :: cout << "Checking the values of the pointers" << std :: endl;
    // The below 2 should be the same
    std :: cout << "*a: " << *a << std :: endl;                 // prints the value that a points to        dereferencing gives the value
    std :: cout << "*age: " << *age << std :: endl;             // prints the value that age points to      dereferencing gives the value
    // The below  2 should be the same
    std :: cout << std :: endl;
    std :: cout << "a: " << a << std :: endl;                   // prints the address a points to
    std :: cout << "age: " << age << std :: endl;               // prints the address that age points to
    // The below 2 should be different
    std :: cout << std :: endl;
    std :: cout << "&a: " << &a << std :: endl;                 // prints the address of pointer a in memory
    std :: cout << "&age: " << &age << std :: endl;             // prints the address of pointer age in memory
    // Both pointers a and age point to the first element of the array
}

// Therefore, the name of the array is actually a pointer pointing to the first element of the array.
// Since name of an array is a pointer to its first element, the arrayname+1 gives the address of the second element of the array,
//                                                               arrayname+2 gives the address of the third element of the array, and so forth
// Thus, to print the data value of the arrays, we dereference the arrayname
//      std :: cout << age[3];
//      std :: cout << *(age+3)         both prints the data value of the fourth element of the array age

// ARRAYS OF POINTERS
// Pointers also can be arrayed like any other data type.
// Syntax: data-type *array-name[size];
// Remember, array elements are allocated contiguous memory locations

void f7()
{
    int a=1, b=2, c=3, d=4;
    int *ip[4];             // array of 10 int pointers
    ip[0] = &a;
    ip[1] = &b;
    ip[2] = &c;
    ip[3] = &d;
    for (int i=0; i<4; i++)
    {
        std :: cout << "ip ["<< i <<"]: " << ip[i] << std :: endl;       // print the addresses of the integers at each indexes
        std :: cout << "*ip ["<< i <<"]: " << *ip[i] << std :: endl;     // prints the values of integers at each indexes by dereferencing it
        std :: cout << "&ip ["<< i <<"]: " << &ip[i] << std :: endl;     // prints the addresses of the indexes itself
        std :: cout << std :: endl;
    }
    
    // We are also aware that the name of the array itself is a pointer which points towards the address of the first element of the array
    // This holds true for a pointer array aswell
    // We shall up our game a little
    
    // Here, ip is a pointer pointing towards ip[0]
    // Therefore,
    std :: cout << ip << std :: endl;           // prints the address of ip[0], i.e., address of the first index
    std :: cout << *ip << std :: endl;          // prints the address of the integer at the index
    std :: cout << **ip << std :: endl;         // prints the value of the integer at the index
    // **(ip+1) , **(ip+2), **(ip+3) will print the values of the integers of the whole array.
}

// Program to print different values being pointed to by an array of pointers (concept of array of pointers)
void f8()
{
    int *ip[5];                             // array of 5 integer pointers
    int f=65, s=67, t=69, fo=70, fi=75;     // 5 int variables
    // Initialize array of pointers by making them point to 5 different integers
    ip[0] = &f;
    ip[1] = &s;
    ip[2] = &t;
    ip[3] = &fo;
    ip[4] = &fi;
    // printing the values being pointed to
    for (int i=0; i<5; i++)
    {
        std :: cout << "The pointer ip [" <<i<< "] points to: " << *ip[i] << std :: endl;       // print the value as it is dereferenced
        std :: cout << "The address stored in ip [" << i << "] is: " << ip[i] << std :: endl;   // prints the address of the integer
    }
    std :: cout << "The base address of array ip of pointers is: " << ip << std :: endl;
}

// Program to set all elements of an array to 0

void f9()
{
    const int LEN = 20;
    int inarr[LEN];
    for (int i=0; i<LEN; i++)
    {
        inarr[i] = 0;
    }
    
    // OR WE COULD ..
    
    int *arr{nullptr};      // initialize a nullpointer
    for (arr = inarr; arr < &inarr[LEN]; arr++)
    {
        *arr = 0;
    }
    // Both give us the same result, but it is faster and efficient to use an element pointer rather than an index when scanning arrays.
}

// POINTERS AND STRINGS
// C++ treats a string as an array of characters so we discuss strings under arrays.
// A string is one dimensional array of characters terminated by a null ('\0') character.

// Small example: Write a program to print a string with "..." in between adjacent letters

void f10()
{
    char name[] = "POINTER";        // declaring a string
    for (int i=0; name[i] != '\0'; i++)
    {
        std :: cout << "..." << name[i];
    }
    std :: cout << std :: endl;
    
    // Alternatively, the same can be achieved using a character pointer.
    
    char *cptr{nullptr};        // declaring a char pointer cptr
    for (cptr = name; *cptr != '\0'; cptr++)
    {
        std :: cout << "..." << *cptr;
    }
    std :: cout << std :: endl;
}


// An array of char pointers is very popularly used for storing several strings in memory.
// The array of char pointers is generally preferred over two dimensional array of characters. There are two reasons behind this,
// 1) An array of pointers makes more efficient use of available memory by consuming lesser number of bytes to store the strings
// 2) An array of pointers makes the manipulation of the strings much easier. One can easily exchange the positions of strings in the array using pointers without actually touching their memory locations.

// POINTERS AND CONSTANTS
// We can declare constant pointers or pointers to constants
// 1) A constant pointer means that the pointer in consideration will always point to the same address. Its address (to which it is pointing to) cannot be modified.
// 2) A pointer to a constant refers to a pointer which is pointing to a symbolic constant. Using a pointer to a constant, the constant value (to which this pointer is pointing to) cannot be modified, however, the pointer can be made to point to another location.

void f11()
{
    int n = 44;
    int *ptr = &n;                  // a pointer to an integer n
    ++(*ptr);                       // ok: increments int *ptr, i.e., the contents as it is dereferenced
    ++ptr;                          // ok: increments pointer ptr
    
    int *const cptr = &n;           // a const pointer to an int
    ++(*cptr);                      // ok: increments int *cptr, i.e., the contents as it is dereferenced
//  ++ cptr;                        // ILLEGAL: pointer cptr is const because address can't be modified
    
    const int k = 88;               // constant int k with value 88
    const int *ptrC = &k;           // a pointer to a constant int
//  ++(*ptrC);                      // ILLEGAL: int *ptrC is a constant, i.e., the values cannot be modified
    ++ptrC;                         // ok: increments pointer ptrC
    
// const int *const cptrC = &k;     // a const pointer to a const int
// ++(*cptrC);                      // ILLEGAL: int *cptrC is const
// ++cptrC;                         // ILLEGAL: pointer cptrC is a const
}


// POINTERS AND FUNCTIONS
// A function may be invoked in one of the two ways: call by value and call by reference
// The call by referenec itself can be used in two ways:
// 1) by passing the references             2) by passing the pointers

// A reference is an alias name for a variable.
float values = 17.234;
float &amt = values;         // amt reference of values
// The above code declares amt as an alias name for the variable values. No spearate memory is allocated for amt; rather the variable value can now be accessed by two names value and amt.

// Whereas,
float *fp = &values;        // pointer fp stores the memory address of values
// Now, using fp, we can directly access the memory area storing the data value of the variable.

// Variable values can now be printed in the following ways:
// std :: cout << values;
// std :: cout << amt;
// std :: cout << *fp;              // prints the data value as the pointer is dereferenced

// Invoking functions by passing the references
// Program to swap values of two variables using pass by reference method.
void f12()
{
    void swap1(int &, int &);                    // function declaration
    int a = 7, b = 10;
    std :: cout << "Original values" << std :: endl;
    std :: cout << "a: " << a << "\t" << "b: " << b << std :: endl;
    swap1 (a,b);                                  // function call remains the same as in call by value
    std :: cout << "Swapped values" << std :: endl;
    std :: cout << "a: " << a << "\t" << "b: " << b << std :: endl;
}
void swap1(int &x, int &y)                       // function definition
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Invoking function by passing pointers
// When pointers are passed to the function, the addresses of actual arguments in the calling function are copied into formal arguments of the called function. Using the formal arguments (the addresses of original values) in the called function, we can make changes in the actual arguments of the calling function. Therefore, here also, the called function does not create own copy of original values, rather, it refers to the original values by the addresses (passed through pointers) it receives.

// Program to swap values of two variables by passing references
void f13()
{
    void swap2 (int *x, int *y);
    int a = 7, b = 10;
    std :: cout << "Original values" << std :: endl;
    std :: cout << "a: " << a << "\t" << "b: " << b << std :: endl;
    swap2 (&a, &b);             // The addresses of a and b are passed to function swap2
    std :: cout << "Swapped values" << std :: endl;
    std :: cout << "a: " << a << "\t" << "b: " << b << std :: endl;
}
void swap2 (int *x, int *y)     // The function definition receives the incoming addresses in corresponding pointer x and y
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Functions Returning Pointers
// The way a function can return an int, float, double or any other data type, it can even return a pointer (memory address). It should explicitly be mentioned in the function's declaration.
// Syntax: type *function-name(arguments);
//                                      where type specifies the pointer type (int, float, double) beign returned by the function-name

// Program to illustrate a function returning a pointer
void f14()
{
    int *big(int &, int &);         // function declaration     // returns a pointer who points towards an int
    int a,b, *c;                                                // c is an int pointer
    std :: cout << "Enter two integers: " << std :: endl;
    std :: cin >> a >> b;
    c = big(a,b);                   // gets the memory address of the greater of a and b using the big function
    std :: cout << "The bigger value is: " << *c << std :: endl;        // dereferenced c prints the value that it points to.
}
int *big(int &x, int &y)                                       // returns the address of the greater int of the two
{
    if (x>y)
        return &x;
    else
        return &y;
}
// The program passes two integers by reference to the function big() that compares the two integers passed to it and returns the memory address of the bigger value. Since the return value of big() is int* i.e., an int pointer, it is received in an int pointer c. Then the value being pointer to by pointer c is printed on the screen.

// POINTERS AND STRUCTURES
// Declaration and use of Structure Pointers
// Syntax: struct-name *struct-pointer;
//                              where struct-name is the name of an already defined structure and struct-pointer is the pointer to the structure.
// Using the structure pointers, the members of structures are accessed using attow operator ->.
// Syntax: struct-pointer -> structure-member;

// Program to illustrate the use of structure pointers
void f15(){
    struct date
    {
        short int dd, mm, yy;
    };
    date join_dt;            // object of type date
    date *dtptr;            // pointer of type date
    
    dtptr = &join_dt;       // pointer points to the address of the object
    join_dt.dd = 19;
    join_dt.mm = 12;
    join_dt.yy = 18;
    
    std :: cout << "Printing structure elements using structure variables" << std :: endl;
    std :: cout << "Join Date: " << join_dt.dd << std :: endl;
    std :: cout << "Join Month: " << join_dt.mm << std :: endl;
    std :: cout << "Join Year: " << join_dt.yy << std :: endl;
    
    std :: cout << "Printing structure elements using structure pointer" << std :: endl;
    std :: cout << "Join Date: " << dtptr -> dd << std :: endl;
    std :: cout << "Join Month: " << dtptr -> mm << std :: endl;
    std :: cout << "Join Year: " << dtptr -> yy << std :: endl;
}
// Remember: The dot (.) operator requires a structure variable (object) on its left and the arrow (->) operator requires a structure pointer on its left.

// Program that invokes a function to increase the basic salary of an employee if the employee has experience of 10 years or more.
struct Employee
{
    int empno;
    char name[25];
    float basic;
    float experience;
};
void display (Employee *emp);                   // takes in a pointer (address) as a parameter
void increase (Employee *emp);

void f16()
{
    Employee mgr, *eptr;
    eptr = &mgr;                                    // eptr now stores the address of object mgr of type Employee.
    std :: cout << "Enter employee number: " << std :: endl;
    std :: cin >> eptr -> empno;                // std :: cin >> mgr.empno;
    std :: cout << "Enter emoloyee name: " << std :: endl;
    std :: cin >> eptr -> name;                 // std :: cin >> mgr.name;
    std :: cout << "Enter basic salary: " << std :: endl;
    std :: cin >> eptr -> basic;                // std :: cin >> mgr.basic;
    std :: cout << "Enter experience: " << std :: endl;
    std :: cin >> eptr -> experience;           // std :: cin >> mgr.experience;
    display(eptr);                              // address of mgr is passed as a parameter
    increase(eptr);                             // address of mgr is passed as a parameter
}

void display (Employee *emp)
{
    long len = std :: strlen(emp ->name);
    std :: cout << "Employee number: " << emp -> empno;
    std :: cout << "Name: " ; std :: cout.write(emp -> name,len);
    std :: cout << "Basic: " << emp -> basic;
    std :: cout << "Experience: " << emp -> experience << " years" << std :: endl;
}

void increase (Employee *emp)
{
    if (emp -> experience > 10)
    {
        emp -> basic += 200;
    }
}

// Self Referencial Structures
// A dybamuc linear list in C++ is called a linked-list. One major use of linked lists is to create arrays of unknown size in memory.
// A linked list requires that each item of information contain a link to the next element in the list.
// Each data item usually consists of a structure that includes information fields and a link pointer.
// Conceptually, a linked list is a structure having an additional pointer as its data-element that points to a structure of the same type.
// Implementation:

struct emp
{
    int employeeno;
    char employeename[25];
    float basicsalary;
    float totalexperience;
    emp *next;                  // pointer to the same structure type
};
// The structure contains an element that refers to the structure itself. Such structures are called self-referencial structures.

// Dynamic Structures
// The new operator can be used to create dynamic structures also, i.e., the structures for which the memory is dynamically allocated.
// Syntax: struct-type *pointer-name = new struct-type;
//                      struct type is the predefined structure type for which the memory is being allocated and pointer-name is the new pointer

emp *empptr = new emp;      // dybamically allocating a structure of type emp and making empptr point towards it's address

// It is also important to delete whenever we dynamically assign memory.
// Syntax: delete pointer-name;
void f(){
delete empptr;
};


// OBJECTS AS FUNCTIONS ARGUMENTS
// Passing objects to function by value

class Sample
{
private:
    int x;
public:
    Sample(int i);      // constructor declaration
    ~Sample();          // destructor declaration
    void put_x(int i);
    int get_x();
};
Sample :: Sample (int i)    // constructor definition
{
    x = i;
    std :: cout << "Constructing object with: " << i << std :: endl;
}
Sample :: ~Sample()
{
    std :: cout << "Destructing Object having: " << x << std :: endl;
}
void Sample:: put_x(int i)
{
    x = i;
}
int Sample:: get_x()
{
    return x;
}

void afunc(Sample S1)
{
    S1.put_x(2);            // change value of x in the object
    std :: cout << "This is x local to afunc()" << std :: endl;
    std :: cout << "x: " << S1.get_x() << std :: endl;
}

void f17()
{
    Sample S(1);        // create object with value 1
    std :: cout << "This is x in main()" << std :: endl;
    std :: cout << "x: " << S.get_x() << std :: endl;
    afunc(S);      // passing S by value to afunc();
    std :: cout << "Back in main()" << std :: endl;
    std :: cout << "x: " << S.get_x() << std :: endl;
}
// A called function receiving an object as a parameter creates the copy of the object without invoking the constructor. However, when the function terminates, it destroys this copy of the object by invoking its destructor function.

// Passing Objects through Reference
// When we want the called function to work with the original object so that there is no need to create and destroy the copy of it, we may pass the reference to the object. Then the called function refers to the original object using its reference or alias.

// Program to illustrate the passing of objects by references
class sample
{
private:
    int x;
public:
    sample (int i);     // constructor
    ~sample ();         // destructor
    void put_x(int i);
    int get_x();
};
sample :: sample(int i)
{
    x = i;
    std :: cout << "Constructing object with: " << i << std :: endl;
}
sample :: ~sample()
{
    std :: cout << "Destroying object having: " << x << std :: endl;
}
void sample:: put_x(int i)
{
    x = i;
}
int sample:: get_x()
{
    return x;
}
void bfunc(sample &S1)
{
    S1.put_x(2);
    std :: cout << "This is x local to bfunc()" << std :: endl;
    std :: cout << "x: " << S1.get_x() << std :: endl;
}
void f18()
{
    sample S(1);
    std :: cout << "This is the x in main()" << std :: endl;
    std :: cout << "x: " << S.get_x() << std :: endl;
    bfunc(S);
    std :: cout << "Back in main()" << std :: endl;
    std :: cout << "x: " << S.get_x() << std :: endl;
}

// POINTERS AND OBJECTS
// Syntax: class-name *object-pointer;
//              where class-name is the name of an already defined class and object-pointer is the pointer to an object of type class
// The arrow operator (->) is used instead of the dot operator

// Program to illustrate the use of object pointers
class Time
{
private:
    short int hh, mm, ss;
public:
    Time();
    void getdata(int i, int j, int k);
    void prndata();
};
Time :: Time()
{
    hh = mm = ss = 0;
}
void Time:: getdata(int i, int j, int k)
{
    hh = i;
    mm = j;
    ss = k;
}
void f19()
{
    Time T1, *tptr;
    tptr = & T1;
    std :: cout << "Initializing data members using the pointer" << std :: endl;
    tptr -> getdata(10,2,41);                                       // T1.getdata(10,2,41);
    std :: cout << "Printing members using the pointer" << std :: endl;
    tptr -> prndata();                                              // T1.prndata();
}

// POINTERS TO ARRAY OF OBJECTS
// When a pointer is incremented, it points to the next element of its type. The same is true of pointers to objects. If we make a pointer point to the first object in an array of objects, incrementing the pointer would make it point to the next object in sequence.

Time tarr[5], *tp;
void f20()
{
    tp = tarr;                   // tp points to the first element tarr[0], i.e., it holds the address of the first object in the tarr array
    tp++;                       // points to the second object tarr[1]
    tp += 2;                   // points to the fourth object tarr[3]
};

// Remember:
// 1) A pointer can point to only public members of the class
// 2) The data type of the pointer must be the same as that of the data member it points to


// THE "this" POINTER
// As soon as we define a class, the member functions are created and placed in the memory space only once.
// The space for data members is allocated separately for each object.
// When a member function is called, it is automatically passed an implicit (in built) argument that is a pointer to the object that invoked the function. This pointer is called this.
// If object1 is invoking member-function3, then an implicit argument is passed to member-function3 that points to object1, i.e., this pointer now points to object1.

// Program to illustrate functioning of this pointer
class Salesman
{
private:
    char name[25];
    float total_sales;
public:
    Salesman (char *s, float f);
    void prnobject();
};

Salesman :: Salesman(char *s, float f)
{
    std :: strcpy(name, "");
    std :: strcpy(name,s);
    total_sales = f;
}
void Salesman:: prnobject()
{
    std :: cout.write(this -> name, 26);
    std :: cout << "has invoked prnobject()" << std :: endl;
}


