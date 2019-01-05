// Classes and Objects
// Author: Hetansh Mehta
// References: Computer Science with C++ by Sumita Arora
// The theory and the examples have been taken from the above mentioned source. This file is meant for study and 
// understanding purposes only. 

// A class represents a group of similar objects.
// A class is a way to bind data describing an entity and its associate functions together - encapsulation.

// Classes are needed to represent real-world entities that not only have data type properties (their characteristics)
// but also have associated operations (their behaviour)

// Declaration of a class
// 1) Data Members: the data-type properties that descirbe the characteristics of a class.
// 2) Member Functions: the set of operations that may be applied to objects of that class.
// 3) Program Access Levels: control access to members from within the program. These acccess levels are private, public, or protected.
// 4) Class Tagname: serves as a type identifier for the class using which objects of this class type can be created.

// The class definition:

// class class-name
// {
//    private:
//          [variable declarations..]               // By default (if no access specifier), the members of the class are considered private
//    public:
//          [variable declaration..]
// };
//
// The keyword class specifies that it is a class; class-name is the tagname of the class that acts as a type specifier using which objects
// of this type class can be declared.
// Access Specifier: Private Members can only be acccessed within the class. Public Members can be accessed from outside the class also.

// Declare a class salesman with the characteristics like salesman number, salesman name, product no, target, and sales made.
// The operations that can be performed on this data are: addd monthly sales, calculate commission, and print commission.

#include <iostream>
#include <cmath>
#include <string>

class Salesman
{
private:
    int salesman_no;
    char salesman_name[26];
    int product_no;
    float target, sales_made, commission;
    void calc_comm()
    {
        float comn = 0;
        if (target <= sales_made)
        {
            comn = sales_made*0.20;
        }
        commission = comn;
    }
    
public:
    void readData();
    float add_mon_sale(float sales);
    void printData();
};

// defining functions outside the class definition
// Syntax is classname:: function-name
// class-name indicates that the function specified by function-name is a member of the class specified by class-name.
// the symbol ::, call the scope resolution operator, specifies that the scope of the function is restricted to the class class-name.

// General form of the function definition outside the class:
// return-type Class-name:: function-name(parameters)
// {
//      function body
// }

void Salesman:: readData()
{
    std :: cout << "Enter salesman no: " << std :: endl;
    std :: cin >> salesman_no;
    std :: cout << "Enter Salesman name: " << std :: endl;
    std :: cin >> salesman_name;
    std :: cout << "Enter product no: " << std :: endl;
    std :: cin >> product_no;
    std :: cout << "Enter target: " << std :: endl;
    std :: cin >> target;
    std :: cout << "Enter sales made: " << std :: endl;
    std :: cin >> sales_made;
}
float Salesman:: add_mon_sale(float sales)
{
    sales_made += sales;
    return sales_made;
}

void Salesman:: printData()
{
    std :: cout << "Salesman no: " << salesman_no << std :: endl;
    std :: cout << "Salesman name: " << salesman_name << std :: endl;
    std :: cout << "Commission: " << commission << std :: endl;
}

// We can also define the member functions inside the class
// The function definition is just similar to the function definitions we are familiar with.
// Normally, only small functions are definied inside the class definition. A function defined inside a class is an inline function.
// When a function is called inside a program, it is loaded and then executed when the program is running. However, if a function
// is declared inline, its code is included in the program (the way header files are included) and compiled along with the program.
// Thus, no call is made to it during run time and it saves the execution time spent in calling the function.
// We can define the above class salesman as:

class Salesman1
{
private:
    int salesman1_no;
    char salesman1_name[26];
    int product1_no;
    float target1, sales1_made, commission1;
    
    void calc1_comm(void)
    {
        float comn1 = 0;
        if (target1 <= sales1_made)
        {
            comn1 = sales1_made*0.20;
        }
        commission1 = comn1;
    }
    
public:
    void readData1()
    {
        std :: cout << "Enter salesman1 no: " << std :: endl;
        std :: cin >> salesman1_no;
        std :: cout << "Enter salesman1 name: " << std :: endl;
        std :: cin >> salesman1_name;
        std :: cout << "Enter product1 no: " << std :: endl;
        std :: cin >> product1_no;
        std :: cout << "Enter target and sales made: " << std :: endl;
        std :: cin >> target1 >> sales1_made;
    }
    float add_mon_sale(float sales1)
    {
        sales1_made += sales1;
        return sales1_made;
    }
    void printData(void)
    {
        std :: cout << "Salesman1 no: " << salesman1_no << std :: endl;
        std :: cout << "Salesman1 name: " << salesman1_name << std :: endl;
        std :: cout << "Commission1: " << commission1 << std :: endl;
    }
};

// Referencing Class Members
// DECLARATION OF OBJECTS MUST BE IN THE MAIN FUNCTION.
// A class specification does not define any objects of its type, rather it just defines the properties of a class.
// In C++, a class variable is known as an object.
// The declaration of an object is similar to that of a variable of any basic type. The members of a class are referenced using object of the class.

class ABC
{
private:
    int x,y;
public:
    int z;
    int add (int a, int b);
    int sub (int a, int b);
};
 // member functions
 int ABC:: add(int a, int b)
 {
 int sum = 0;
 sum = a+b;
 return sum;
 }
 int ABC:: sub(int a, int b)
 {
 int diff = 0;
 diff = a-b;
 return diff;
 }

// The public data can be accessed by the non-member functions through the objects of the class.
// The public member functions of a class are called by non-member functions using the objects.
// General Syntax is -  object-name.function-name(actual-parameters);
/*
int main()
{
    // CREATING OBJECT OF CLASS ABC
    ABC obj1;
    obj1.add(4,7);
    
}
 */


// Arrays within a Class
// An array in a class can be a private or public data member of the class.
// If it happens to be private, only the member functions of the class can access it.

// class Exarray
// {
// private:
//     int arr[10];            // private data mmember
// public:
//     int largest(void);
//     int sum(void);
// };

// The following program stores price list of 5 items in an array and can print the largest price and the sum of all the item prices.
class ITEM
{
private:
    int itemcode[5];
    float item_price[5];
public:
    void initialize();
    float largest();
    float sum();
    void display_items();
};

void ITEM:: initialize()
{
    for (int i=0; i<5; i++)
    {
        std :: cout << "Item number " << i+1 << std :: endl;
        std :: cout << "Enter item code: " << std :: endl;
        std :: cin >> itemcode[i];
        std :: cout << "Enter item price " << std :: endl;
        std :: cin >> item_price[i];
    }
}

float ITEM:: largest()
{
    float max = 0;
    for (int i=0; i<5; i++)
    {
        if (item_price[i] > max)
        {
            max = item_price[i];
        }
    }
    return max;
}

float ITEM:: sum()
{
    float sum=0;
    for (int i=0; i<5; i++)
    {
        sum += item_price[i];
    }
    return sum;
}

void ITEM:: display_items()
{
    std :: cout << "Item Code \t Item Price" << std :: endl;
    for (int i=0; i<5; i++)
    {
        std :: cout << itemcode[i] << "\t \t" << item_price[i] << std :: endl;
    }
}
/*
int main()
{
    ITEM order;
    order.initialize();     // initialize array
    float total,big;
    int ch = 0;
    do
    {
        std :: cout << "Menu" << std :: endl;
        std :: cout << "1) Display largest price" << std :: endl;
        std :: cout << "2) Display sum of prices" << std :: endl;
        std :: cout << "3) Display item list" << std :: endl;
        std :: cout << "4) Exit" << std :: endl;
        std :: cout << "Enter your choice: " << std :: endl;
        std :: cin >> ch;
        switch (ch)
        {
            case 1:
                big = order.largest();
                std :: cout << "The largest price is: " << big << std :: endl;
                std :: cout << std :: endl;
                std :: cout << "-----------------------------------" << std :: endl;
                break;
            case 2:
                total = order.sum();
                std :: cout << "The sum of prices is: " << total << std :: endl;
                std :: cout << std :: endl;
                std :: cout << "-----------------------------------" << std :: endl;
                break;
            case 3:
                order.display_items();
                std :: cout << std :: endl;
                std :: cout << "-----------------------------------" << std :: endl;
                break;
            case 4:
                break;
        }
    }
    while (ch >=1 && ch <= 3);
    return 0;
}
*/


// Scope of Class Members
// Public members can be directly accessed by any function.
// Private members are hidden from the outside world. The private members implement the OOP concepts of data hiding.

// Example of nesting of member function, i.e., calling a member function using another member function
class X
{
private:
    int a;
    int sqr(int a)
    {
        return a*a;
    }
public:
    int b;
    int twice(int i)
    {
        return 2*i;
    }
    int tsq(int i)              // tsq() calls a private member function sqrt()
    {                           // private members can only be accessed by member functions
        int p = sqr(i);
        int q = twice(p);
        return q;
    }
};
/*
int main()
{
    X obj1;
    obj1.b = 5;
    obj1.twice(10);
    obj1.tsq(10);       // tsq() evokes sqr() and twice() functions. sqr() can only be evoked using member functions.
}
*/

// Global Class: A class is said to be global class if its definition occurs outside the bodies of all functions in a program,
// which means that object of this class type can be declared anywhere in the program.
// Local Class: A class is said to be local class if its definition occurs inside a function body, which means that objects of this class
// can be declared only within the function that defines this class type.
// Global Object: An object is said to be a global object if it is declared outside all the function bodies and it means that this object
// is globally available to all functions in the program, i.e., this object can be used anywhere in the program.
// Local Object: An object is said to be a local object if it is declared within a function, which means that this object is locally available
// to the function that declares it and it cannot be used outside the function declaring it.

// Program to hold details of 10 students and provide the facility of viewing details of the topper as well as of
// specific student by providing his/her roll number.

class Student
{
private:
    int rollno;
    char name[25];
    float marks;
    char grade;
    void calc_grade()
    {
        if (marks >= 75)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }
    
public:
    void readStudent();
    void dispStudent();
    int getRollno();
    float getMarks();
};

void Student:: readStudent()
{
    std :: cout << "Enter rollno: " << std :: endl;
    std :: cin >> rollno;
    std :: cout << "Enter name: " << std :: endl;
    std :: cin >> name;
    std :: cout << "Enter marks: " << std :: endl;
    std :: cin >> marks;
    calc_grade();
}

void Student:: dispStudent()
{
    std :: cout << "Roll no.: " << rollno << std :: endl;
    std :: cout << "Name: " << name << std :: endl;
    std :: cout << "Marks: " << marks << std :: endl;
    std :: cout << "Grade: " << grade << std :: endl;
}

int Student:: getRollno()
{
    return rollno;
}

float Student:: getMarks()
{
    return marks;
}

/*
int main()
{
    // Creating object that can hold data of 10 students. (array of class objects)
    Student XIIA[10];
    // Reading data for each student
    for (int i=0; i<10; i++)
    {
        std :: cout << "Enter the details of student " << i+1 << std :: endl;
        XIIA[i].readStudent();
    }
    
    int choice, rno, pos = -1;
    float highmarks=0;
    bool key = true;
    while (key)
    {
        std :: cout << "Menu" << std :: endl;
        std :: cout << "1) Specific Student" << std :: endl;
        std :: cout << "2) Topper" << std :: endl;
        std :: cout << "3) Exit" << std :: endl;
        std :: cout << "Enter your choice: " << std :: endl;
        std :: cin >> choice;
        
        switch (choice)
        {
            case 1:
                std :: cout << "Enter the rollno of student whose details you want to see: " << std :: endl;
                std :: cin >> rno;
                for (int i=0; i<10; i++)
                {
                    if (XIIA[i].getRollno() == rno)             // we dont write XIIA[i].rollno because rollno is a private data,
                    {                                           // hence we need to access using member functions, i.e., getRollno()
                        XIIA[i].dispStudent();
                        break;
                    }
                    if (i==10)
                    {
                        std :: cout << "Invalid Rollno" << std :: endl;
                    }
                }
                break;
           
            case 2:
                for (int i=0; i<10; i++)
                {
                    if (XIIA[i].getMarks() > highmarks)
                    {
                        pos = i;
                        highmarks = XIIA[i].getMarks();
                    }
                }
                XIIA[pos].dispStudent();
                break;
            
            case 3:
                key = false;
                break;
                
            default:
                std :: cout << "Wrong input." << std :: endl;
                break;
        }
    }
    return 0;
}
*/

// Few more examples of classes

// Dimensions of a Box and it's Area
class BOX
{
private:
    int BoxNumber;
    float Side;
    float Area;
    void ExecArea()
    {
        Area = Side*Side;
    }
    
public:
    void GetBox();
    void ShowBox();
};

void BOX:: GetBox()
{
    std :: cout << "Enter the BoxNumber: " << std :: endl;
    std :: cin >> BoxNumber;
    std :: cout << "Enter the Side: " << std :: endl;
    std :: cin >> Side;
    void ExecArea();
}

void BOX:: ShowBox()
{
    std :: cout << "BoxNumber: " << BoxNumber << std :: endl;
    std :: cout << "Side: " << Side << std :: endl;
    std :: cout << "Area: " << Area << std :: endl;
}

// Stock of an Item and Discount Offered
class STOCK
{
private:
    int ICode;
    char Item[20];
    float Price;
    int Qty;
    float Discount;
    void FindDisc()
    {
        if (Qty <= 50)
        {
            Discount = 0;
        }
        else if (Qty <= 100)
        {
            Discount = 5;
        }
        else
        {
            Discount = 10;
        }
    }
    
public:
    void Buy();     // Read function
    void ShowAll();
};

void STOCK:: Buy()
{
    std :: cout << "Enter Item Code: " << std :: endl;
    std :: cin >> ICode;
    std :: cout << "Enter Item Name: " << std :: endl;
    std :: cin >> Item;
    std :: cout << "Enter Item Price: " << std :: endl;
    std :: cin >> Price;
    std :: cout << "Enter Quantity: " << std :: endl;
    std :: cin >> Qty;
    FindDisc();
}

void STOCK:: ShowAll()
{
    std :: cout << "Item Code: " << ICode << std :: endl;
    std :: cout << "Item Name: " << Item << std :: endl;
    std :: cout << "Item Price: " << Price << std :: endl;
    std :: cout << "Quantity: " << Qty << std :: endl;
    std :: cout << "Discount: " << Discount << std :: endl;
}

// Class METROPOLIS in C++

class METROPOLIS
{
private:
    int MCode;          // Code
    char MName[20];     // Name
    long int MPop;      // Populatrion
    float Area;         // Area Coverage
    float PopDens;      // Population Density
    float CalDen()      // A member function to calculate density as MPop/Area
    {
        PopDens = MPop/Area;
        return PopDens;
    }
    
public:
    void Enter();       // A function to read the data
    void ViewAll();     // A function to show all data (print "Highly Populated Area" if density > 12000;
};

void METROPOLIS:: Enter()
{
    std :: cout << "Enter MCode: " << std :: endl;
    std :: cin >> MCode;
    std :: cout << "Enter MName: " << std :: endl;
    std :: cin >> MName;
    std :: cout << "Enter MPop: " << std :: endl;
    std :: cin >> MPop;
    std :: cout << "Enter Area: " << std :: endl;
    std :: cin >> Area;
    CalDen();
}

void METROPOLIS:: ViewAll()
{
    std :: cout << "MCode: " << MCode << std :: endl;
    std :: cout << "MName: " << MName << std :: endl;
    std :: cout << "MPop: " << MPop << std :: endl;
    std :: cout << "Area: " << Area << std :: endl;
    std :: cout << "PopDens: " << PopDens << std :: endl;
    if (PopDens > 12000)
    {
        std :: cout << "Highly Populated Area" << std :: endl;
    }
}

// Nested Classes

class Outer
{
private:
    int a;
    class Inner
    {
    private:
        int b;
    public:
        int c;
        void prn()
        {
            std :: cout << "Inner::prn()" << std :: endl;
            std :: cout << b << "\t" << c << std :: endl;
        }
        Inner()         // constructor
        {
            b = 5;
            c = 10;
        }
    };
    Inner ob1;
    
public:
    Inner ob2;
    void second()
    {
        std :: cout << "Outer::second()" << std :: endl;
        std :: cout << ob2.c << std :: endl;
        std :: cout << "A= " << a << std :: endl;
        ob1.prn();
    }
    Outer()         // constructor
    {
        a = 25;
    }
};
/*
int main()
{
    Outer ab;
    ab.second();
    ab.ob2.prn();
    return 0;
}
*/

// Program to Illustrate the use of object arrays by storing details of 10 items in an array of objects
class Item
{
private:
    int itemno;
    float price;
public:
    void getdata();
    void putdata();
};
const int size = 10;
Item order[size];       // An object array namely order of item class type has been created

void Item:: getdata()
{
    std :: cout << "Enter ItemNo: " << std :: endl;
    std :: cin >> itemno;
    std :: cout << "Enter price: " << std :: endl;
    std :: cin >> price;
}

void Item:: putdata()
{
    std :: cout << "ItemNo: " << itemno << std :: endl;
    std :: cout << "Price: " << price << std :: endl;
}

/*
int main()
{
    // Input of data for 10 objects
    for (int i=0; i<10; i++)
    {
        std :: cout << "Details for Item " << i+1 << std :: endl;
        order[i].getdata();
    }
    // Output of Data for 10 objects
    for (int i=0; i<10; i++)
    {
        std :: cout << "Data for Item " << i+1 << std :: endl;
        order[i].putdata();
    }
}
*/

//  Program to illustrate the use of objects as arguments to member, and nonmember functions using Call by Value mechanism

class Time
{
private:
    int hrs, mins, secs;
public:
    int tot_secs;
    void gettime(int h, int m, int s)
    {
        hrs = h;
        mins = m;
        secs = s;
        tot_secs = (hrs*60) + (mins*60) + secs;
    }
    void puttime(void)
    {
        std :: cout << "Time is: " << hrs << ":" << mins << ":" << secs << std :: endl;
    }
    void convert(Time t, char ch);
    void sum(Time ti, Time t2);
    int gethrs(){return hrs;}
    int getmins(){return mins;}
    int getsecs(){return secs;}
};

void Time::convert(Time t, char ch)
{
    switch (ch)
    {
        case 'h':
            std :: cout << "Time in hours is: " << t.hrs << ":" << t.mins << ":" << t.secs << " hrs" << std :: endl;
            break;
        case 'p':
            std :: cout << "Time in am/pm is: " << ((t.hrs>12) ? (t.hrs-12) : t.hrs) << ":" << t.mins << ":" << t.secs;
            std :: cout << ((t.hrs >12)? "pm" : "am") << std :: endl;
            break;
        default:
            std :: cout << "Wrong choice" << std :: endl;
            break;
    }
}

void Time:: sum(Time t1, Time t2)
{
    int h, m, s, sq, mq;
    sq = (t1.secs + t2.secs)/60;
    s = (t1.secs + t2.secs)%60;
    mq = (sq + t1.mins + t2.mins)/60;
    m = (sq + t1.mins + t2.mins)%60;
    h = mq + t1.hrs + t2.hrs;
    if (h==24)
    {
        h=0;
    }
    std :: cout << "Total time is: " << h << ":" << m << ":" << s << std :: endl;
}

void prnvalues(Time t1)         // non member function
{
    std :: cout << "Total secs: " << t1.tot_secs << std :: endl;
    // t1.hrs is invalid as it is private
    // t1. mins & t1.secs are invalid aswell
}
/*
int main()
{
    Time tm1, tm2;
    char ch;
    tm1.gettime(5,13,27);
    tm2.gettime(7,48,38);
    std :: cout << "Enter h to convert in hours format, p for am/pm format: " << std :: endl;
    std :: cin >> ch;
    tm1.convert(tm2,ch);
    tm1.sum(tm1,tm2);
    prnvalues(tm2);
    return 0;
}
*/
// In the above program, after declaring class Time, two objects tm1 and tm2 of type Time are created.
// The data members of tm1 and tm2 are given values using gettime().
// Then tm2 is converted to hours format or am/pm format based upon user's unput
// Sum of the two times tm1 and tm2 is displayed by evoking sum() and passing tm1 and tm2 to it.
// A nonmember function prnvalues() is invoked to print data values to tm2.
// The functions convert() and sum() will give the desired performance as they can access all the data members of tm1 and tm2.




// CONSTRUCTORS AND DESTRUCTORS

// Constructor: A member function with the same name as its class is called Constructor and it is used to initialize the objects
//              of that class type with a legal initial value for the class.
//              It is automatically called, when an object is created of that class.
// If a class has a constructor, each of the objects of that class will be initialized before any use is made of the object.
// A class cannot be initialized at the time of their declaration because the class members have their associated access specifiers.
// The private data cannot be initialized as it is not available to the outside world.
// A constructor for a class is needed so that the compiler automatically initializes an object as soon as it is created.
// A class constructor, if defined, is called whenever a program creates an object of that class.

// Declaration and Definition of a Constructor
// We are basically defining a member function of the class with the same name as that of its class name.
// It can be defined either inside or outside the class definition.

// Defining the constructor inside the class definition
class Y
{
private:
    int i;
public:
    int j,k;
    Y()
    {
        i=j=k=0;        // constructor defined inside
    }
    // Other members..
};

// Defining the constructor outside the class definition
class Z
{
private:
    int i;
public:
    int j,k;
    Z();        // declaration of constructor
    // Other members.. .
};

Z :: Z()        // constructor defined outside
{
    i=j=k=0;
}
// A constructor taking no parameter is called the default constructor.
// When a user defined class does not contain any constructor, the compiler automatically supplies a default constructor, having no arguments.
// The default constructor provided by the compiler does not do anything specific. It simply allocates memory to data members of object.

// A constructor can be defined under private access section also. It would then be accessed only by the member functions of the class.

// Passing arguments to the constructor
class XYZ
{
private:
    int i;
public:
    float j;
    XYZ(int a, float b);
    // other members
};
XYZ :: XYZ(int a, float b)      // Constructor takes two values, an int and a float to construct values for newly created object.
{
    i = a;
    j = b;
}
/*
int main()
{
    XYZ obj1(2, 13.5);          // Obj1 is created with initial values 2 and 12.5
    XYZ obj2(4, 19.22);         // Obj2 is created with initial values 4 and 19.22
//  XYZ obj3;                   // Error as no default constructor available and no argument is passed.
    return 0;
}
*/

// Parameterized Constructors
// Constructors can also accept parameters and such constructors are called parameterized constructors.
// Once we declare a constructor with arguments, the default constructor becomes hidden. After this, we cannot invoke the defaul constructor.
class Test
{
private:
    int ant;
public:
    Test(int i);        // constructor with argument
    // other members
};
Test :: Test(int i)     // constructor definition
{
    ant = i;
}
/*
int main()
{
    Test obj1(45);      // Argument value provided
//  Test obj2;          // Invalid, no default constructor available as no argument is provided.
}
*/
// A parameterized constructor can also have default arguments.
class A
{
private:
    int i;
    float j;
public:
    A(int a = 0, float b=100.0);        // constructor with default arguments
    // other members
};
A :: A (int a, float b)
{
    i =a;
    j = b;
}
/*
int main()
{
    A obj1(23, 24.123);         // ok, argument values passed for obj1
    A obj2;                     // obj2 takes the default arguments that have been passed.
}
*/

// With a parameterized constructor for a class, one must provide initial values as arguments, otherwise, the compiler will report an error.
// Therefore, with a parameterized constructor, the initial values must be passed at the time of object creation.
// This can be done in two manners:
// 1) by calling the constructor implicitly
// 2) by calling the constructor explicitly

// To understand implicit and explicit call, consider the example:
class DEF
{
private:
    int i;
public:
    float j;
    char k;
    DEF(int a, float b, char c);        // constructor declaration with arguments
    // other members
};
DEF :: DEF (int a, float b, char c)
{
    i = a;
    j = b;
    k = c;
}
// Implicit call to the constructor
DEF obj1(13, 3.14, 'p');      // the constructor is called even when its name has not been mentioned in the statement
// Ecplicit call to the constructor
DEF obj2 = DEF (14, 6.28, 'q');     // the constructor name is explicitely provided to invoke it to initialize obj2


// DESTRUCTORS
// A destructor is also a member function whose name is the same as the class name but is preceded by tilde ('~').
// For example, the destructor for the class Sample will bear the name: ~Sample()
// A destructor takes no arguments, and no return types can be specified for it.
// It is called automatically by the compiler when an object is destroyed. It cleans up the storage (memory area of the object) that is no longer accessible.
class sample
{
private:
    int i,j;
public:
    sample(int a, int b);       // Constructor
    ~sample()
    {
        std :: cout << "Destructor at work" << std :: endl;
    }
    // other members
};
sample :: sample (int a, int b)
{
    i = a ;
    j = b;
}
/*
int main()
{
    sample s1(3,4); // local object s1 constructed with values 3,4 using sample()
    // ..
    // ..
    // ..
    // automatically s1 is destructed at the end of the block using destructor ~sample
}
*/

// During construction of ab object by the constructor, resources may be allocated for use. (Memory may be allocated)
// These allocated resources must be deallocated before the object is destroyed.
// The destructor performs all clean-up tasks automatically. It is usually invoked when the scope of the object gets over.

// example
class Travel
{
private:
    std :: string T_Code;
    int No_of_Adults;
    int No_of_Children;
    int Distance;
    float TotalFare;
public:
    Travel();           // constructor declareation
    ~Travel();          // destructor declaration
    
    void AssignFare()
    {
        float fare =0;
        if (Distance >= 1000)
        {
            fare = ((No_of_Adults*500) + (No_of_Children*250));
        }
        else if ((Distance < 1000) && (Distance >= 500))
        {
            fare = ((No_of_Adults*300)+(No_of_Children*150));
        }
        else
        {
            fare = ((No_of_Adults*200) + (No_of_Children*100));
        }
        TotalFare = fare;
    }
    // other member functions
    void EnterTravel();
    void ShowTravel();
};
// constructor definition
Travel :: Travel()
{
    T_Code = "NULL";
    No_of_Adults = 0;
    No_of_Children = 0;
    Distance = 0;
    TotalFare = 0.0;
}
void Travel:: EnterTravel()
{
    std :: cout << "Enter travel code: " << std :: endl;
    std :: cin >> T_Code;
    std :: cout << "Enter No of Adults: " << std :: endl;
    std :: cin >> No_of_Adults;
    std :: cout << "Enter No of Children: " << std :: endl;
    std :: cin >> No_of_Children;
    std :: cout << "Enter Distance: " << std :: endl;
    std :: cin >> Distance;
    AssignFare();       // calling the function to calculate the total fare
}
void Travel:: ShowTravel()
{
    std :: cout << "Travel Code: " << T_Code << std :: endl;
    std :: cout << "No of adults: " << No_of_Adults << std :: endl;
    std :: cout << "No of children: " << No_of_Children << std :: endl;
    std :: cout << "Distance: " << Distance << std :: endl;
    std :: cout << "Total Fare: " << TotalFare << std :: endl;
}

