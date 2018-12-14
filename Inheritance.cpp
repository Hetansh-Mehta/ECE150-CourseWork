//
//  Inheritance.cpp
//  Inheritance-Extending Classes
//
//  Created by Hetansh Mehta on 12/13/18.
//  Copyright © 2018 Hetansh Mehta. All rights reserved.
//  References: Computer Science with C++ by Sumita Arora

#include <iostream>
#include <cmath>
#include <string>

// function declarations
void f1();
void f2();
void f3();
void f4();

int main()
{
//  f1();   Do not call f1()
    //f2();
    //f3();
    f4();
}

// Inheritance is basically the capability of one class to inherit properties from another class. Class inheritance lets us derive new classes (called the derived classes) from the old ones, with the derived classes inheriting the properties, including the methods (member functions) of the old class, known as the base class.
// Inheritance ensures code reusability. Once a base class is written and debugged, it can be used in various situations without having to redefine or rewrite it.

// ADVANTAGES OF INHERITANCE
// 1) Represents real-world relationships well
// 2) Provides reusability
// 3) Supports transitivity

// DIFFERENT FORMS OF INHERITANCE
// 1) Single Inheritance: When a subclass inherits only from one base class, it is known as single inheritance.
// 2) Multiple Inheritance: When a sub class inherits from multiple base classes, it is known as multiple inheritance.
// 3) Multilevel Inheritance: The transitive nature of inheritance is reflected by this form of inheritance. When a subclass inherits from a class that itself inherits from another class, it is known as multilevel inheritance.
// 4) Hybrid Inheritance: It combines two or more forms of inheritance, eg, when a sub class inherits from multiple base classes and all of its base class inherit from a single base class, this form of inheritance is known as hybrid inheritance.


// DERIVED AND BASE CLASSES

// A derived class has to identify the class from which it is derived, ie, its base class. The syntax is :

// Syntax: class derived-class-name : visibility-mode base-class-name1, visibility-mode base-class-name2 [,visibility-mode base-class-name3...]
//         { ..... // members of derived class
//         };

// Example: class Sub : private Super, public SuperB { ... // derived class members };

// The base-class name(s) follows the colon (:). The names of all the base classes of a derived class follow : and are separated by a comma.
// The visibility-mode may be either private, public or protected. If no visibility-mode is specified, then by default the visibility-mode is considered as private.

// Actually a derived class inherits all the members of a base class; however, the derived class has access privilege only to the nonprivate members of the base class. The derived class can access the members of the base class directly. Although private members of the base class cannot be accessed directly, the objects of the derived class are able to access them through the non-private inherited members.

// NOTE: Access specifiers control access of members within a class whereas visibility-modes control access of inherited members within the subclass.

// VISIBILITY-MODE
// 1) public            2) Protected            3) Private

// 1) The public Visibility-Mode
// THe public derivation means that the derived class can access the public and the protected members of the base class but not the private members of the base class. The public members of the base class become the public members of the derived class. Public derivation does not change the access specifiers for inherited members in the derived class.

// 2) The private Visibility-Mode
// The private derivation means the derived class can access the public and protected members of the base class privately. With privately derived class, the public and protected members of the base class become private members of the derive class. That means the inherited members can be accessed only through member functions of derived class.
// If the inherited members become private in the derived class, they cannot be inherited further if the derived class happens to be the base class  of any other class.

// 3) The protected Visibility-Mode
// The protected derivation means that the derived class can access the public and protected members of the base class protectedly. With protectedly derived class, the public and protected members of the base class become protected members of the derived class. This means the inherited members are now not available to the outside world and can be accessed only through the member functions of the derived class and the classes based upon derived class. These members can be inherited further.

// Summary
// 1) Members intended to be inherited and at the same time intended to be available to every function, even to non-members, should be declared as public members in the base class.
// 2) Members intended to be inherited but not intended to be public, should be declared protected.
// 3) Members not intended to be inherited should be declared as private


// INHERITANCE AND CONSTRUCTORS AND DESTRUCTORS
// When an object of a derived class is created, first the base class constructor is invoked, followed by the derived class constructors. When an object of a derived class expires, first the derived class destructor is invoked, followed by the base class destructor.
// In a derived class, new data members can be added and hence, a constructor definition is required.

// Passing arguments through a Base Class Constructor
// Syntax: Derived :: Derived(type1 x, typ2 y) : Base(x,y) {...// ...}

// Program to illustrate passing of parameters in the constructor

void f1()
{
    class Base
    {
    private:
        int a;
        float b;
    public:
        Base(int i, float j)     // base class constructor with 2 arguments
        {
            a = i;
            b = j;
        }
    };

    class Derived : public Base
    {
    private:
        int x;
        float y;
    public:
        Derived(int i, float j, int p, float q) : Base (p, q)
        {
            x = i;
            y = j;
        }
    };
            // the derived constructor is accepting parameters for itself (i,j) aswell as for its base constructor (p,q). Then it invokes its base constructor with appropritate parameters and uses rest of the parameters for initializing its own members
}


// INHERITANCE AND ACCESS CONTROL

// Access-Control in Publicly Derived Class
// A class is publicly derived when the keyword public precedes the base class name in the class definition.
// Syntax:  class Manager: public Employee{/../.};
// The keyword public specifies that objects of the derived class are able to access public members of the base class as if they were the public members of their own class.

// Program to illustrate access control in public derivation of a class
void f2()
{
    class Employee
    {
    private:
        char name[25];
        unsigned long enumb;
        
    protected:
        float basic;
        void getbasic()
        {
            std :: cout << "Enter Basic: " << std :: endl;
            std :: cin >> basic;
        }
        
    public:
        void getdata()
        {
            std :: cout << "Enter Name: " << std :: endl;
            gets(name);
            std :: cout << "Enter Employee Number: " << std :: endl;
            std :: cin >> enumb;
        }
        void putdata()
        {
            std :: cout << "Name: " << name << std :: endl;
            std :: cout << "Emp. Number: " << enumb << std :: endl;
            std :: cout << "Basic Salary: " << basic << std :: endl;;
        }
    };
    
    class Manager : public Employee
    {
    private:
        char title[25];
    public:
        void getdata()
        {
            Employee :: getdata();
            getbasic();
            std :: cout << "Enter Title: " << std :: endl;
            gets(title);
        }
        void putdata()
        {
            Employee :: putdata();
            std :: cout << "Title: " << title << std :: endl;
        }
    };
    
    Manager m1, m2;
    std :: cout << "Manager1" << std :: endl;
    m1.getdata();
    std :: cout << "Manager2" << std :: endl;
    m2.getdata();
    
    std :: cout << "Manager1 Details: " << std :: endl;
    m1.putdata();
    std :: cout << "Manager2 Details: " << std :: endl;
    m2.putdata();
}

// Access Control in Privately Derived Class
// A class is privately derived when the keyword private precedes the base class name in the class definition.
// Syntax: class Manager: private Employee {..///....};
// They keyword private specifies that the public and protected members of the base class are directly accessible by the member functions of the derived class as if they were the private members of the derived class. The public and protected members of the base clsas become the private members of the derived class.

// Program to illustrate the privately derived class

void f3()
{
    class Employee
    {
    private:
        char name[25];
        unsigned long enumb;
        
    protected:
        float basic;
        void getbasic()
        {
            std :: cout << "Enter Basic Salary: " << std :: endl;
            std :: cin >> basic;
        }
        
    public:
        void getdata()
        {
            std :: cout << "Enter Name: " << std :: endl;
            gets(name);
            std :: cout << std :: endl;
            std :: cout << "Enter Employee Number : " << std :: endl;
            std :: cin >> enumb;
        }
        void putdata()
        {
            std :: cout << "Name: " << name << std :: endl;
            std :: cout << "Emp. Number: " << enumb << std :: endl;
            std :: cout << "Basic Salary: " << basic << std :: endl;
            
        }
    };
    
    class Manager : private Employee
    {
    private:
        char title[25];
        
    public:
        void getdata()
        {
            Employee :: getdata();
            getbasic();
            std :: cout << "Enter Title: " << std :: endl;
            gets(title);
            std :: cout << std :: endl;
        }
        void putdata()
        {
            Employee :: putdata();
            std :: cout << "Title: " << title <<  std :: endl;
        }
    };
    
    Manager m1, m2;
    std :: cout << "Manager1" << std :: endl;
    m1.getdata();
    std :: cout << "Manager2" << std :: endl;
    m2.getdata();
    
    std :: cout << "Manager1 Details: " << std :: endl;
    m1.putdata();
    std :: cout << "Manager2 Details: " << std :: endl;
    m2.putdata();
}

// A derived class inherits all the members of the base class; however, the derived class has the direct access privilege only to the non-private members of the base class.

// Also note in the above two examples, the member functions - getdata() and putdata() were redefined in the derived class. If this is the case, the member function of the derived class gets called. The derived class' member function shadows/hides the base class's inherited function and this situation is known as function overriding.

