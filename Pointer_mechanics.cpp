#include <iostream>

int main();
void pointer_mechanics_1();
void pointer_mechanics_2();
void pointer_mechanics_3();
double * create_double(double const initial_value);
void print_double(double *p_double);
void dealloc_double(double *&p_double);

int main()
{
    pointer_mechanics_1();
    pointer_mechanics_2();
    pointer_mechanics_3();
    
    return 0;
}

void pointer_mechanics_1()
{
    // TODO - declare a pointer to an int and initialize it to nullptr
    int * p_quantity{nullptr};
    
    // TODO - allocate memory to store an int and use the declared pointer to reference
    // this newly allocated memory location.
    // Initialize the value in this memory location to 25
    p_quantity = new int{25};
    
    // TODO - modify the following statememnt to output
    // the address of the dynamic int variable
    std :: cout << "address of the dynamic int variable: " << p_quantity << std :: endl;
    
    // TODO - modify the following statement to output
    // the address of the pointer
    std :: cout << "address of the pointer: " << &p_quantity << std :: endl;
    
    // TODO - modify the following statement to output
    // the value stored in the dynamic int variable
    std :: cout << "value stored in the dynamic int variable: " << *p_quantity << std :: endl;
    
    // TODO - modify the following statement to output
    // the value stored in the dynamic int variable // the value stored in the pointer is the adderess
    std :: cout << "value stored in the pointer: " << p_quantity << std :: endl;
    
    // TODO -  draw and label a diagram illustrating the state of memory
    
    //      0x1E2C | 0x7fb3 | p_quantity
    //
    //
    //      0x7fb3 | 25     |
    
    // TODO - deallocate the dynamic int variable
    // TODO - set the pointer to nullptr
    delete p_quantity;
    p_quantity = nullptr ;
    
    // TODO - modify the following statement to output
    // the value stored in the pointer
    std :: cout << std :: endl;
    std :: cout << "after de-allocation and setting to nullptr" << std :: endl;
    std :: cout << "value stored in the pointer: " << p_quantity << std :: endl;

}

void pointer_mechanics_2()
{
    // TODO - declare an int variable and initialize its value to 99
    // TODO - declare a pointer to an int and initialize it to nullptr
    int data{99};
    int * p_data{nullptr};
    
    // TODO - assign the pointer to the address of the local int variable
    p_data = &data;
    
    // TDO - dereference the pointer and change its value to 43
    *p_data = 43;
    
    // TODO - modify the follopwing two statements to output the value
    // of the local int variable and the value of the de-referenced pointers
    std :: cout << "value of local int variable: " << data << std :: endl;
    std :: cout << "value of dereferenced pointer: " << *p_data << std :: endl;
    
    // TODO - using the local int variable, assign it a new value of 77
    data = 77;
    
    // TODO - modifu the follopwing two statements to output the value
    // of the local int variable and the value of the de-referenced pointers
    std :: cout << "value of local int variable: " << data << std :: endl;
    std :: cout << "value of dereferenced pointer: " << *p_data << std :: endl;
    
    // TODO - draw and label a diagram illustrating the state of memory
    
    //
    //  |nullptr| p_data          |0x1F22|p_data                    |ox1F22|p_data
    //  | 99    | data      0x1F22| 99 | data               0x1F122| 43 | data
}

// part 3

// TODO - complete the following function definition to do the following:
//      - dynamically allocate memory to store a double
//      - initializes the values stored in the double to the passed initial_value
//      - returns a pointer to this newly allocated memory location

double * create_double(double const initial_value)
{
    double * p_handle = new double{initial_value};
    return p_handle;
}

// TODO - complete the following function definition to do the following
//      - if p_double is pointing to nullptr
//          - output a message indicating it is pointing to nullptr
//      - else
//          - dereferebce the pointer and output the value
void print_double(double *p_double)
{
    if (p_double != nullptr)
    {
        std :: cout << "value of p_double: " << *p_double << std :: endl;
    }
    else
    {
        std :: cout << "p_double is nullptr" << std :: endl;
    }
    
}

// TODO - complete the following function definition to do the following:
//      - deallocate the memory location where p_double is pointing
//      - assign p_double to point to nullptr
void dealloc_double(double *&p_double)
{
    delete p_double;
    p_double = nullptr;
}


void pointer_mechanics_3()
{
    double * p_1{create_double(7.13)};
    
    print_double(p_1);
    
    dealloc_double(p_1);
    
    print_double(p_1);
    
}

//
// 0x2211 |initial_value|       0x2211|7.13|
//
//
//        |0x2211|p_handle
//
//        |0z2211|p_1           |0x2211|p_1             

