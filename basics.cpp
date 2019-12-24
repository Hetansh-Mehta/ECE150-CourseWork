/*
 
 Introduction:
 C++ is an extended language of C. It has new features like OOP.
 
 C++ Basics:
 - Token: The smallest individual unit in a program
 C++ Tokens include: Keywords, Identifiers, Literals, Punctuators and Operators.
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 1) Keywords: are the words that convey special meaning to the language compiler and perform special computation
 examples are: bool, break, return, new, delete, void, unsigned, continue ...
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 2) Identifiers: is a user defined name for a unit of program. It can contain letters and digits. The first character must be a letter; the underscore _ counts as a letter. Upper and lower case letters are different and all characters are significant. It CANNOT contain special characters and keywords cannot be identifiers. It cannot start with a digit.
 examples are: MyFile, Date9_7_18
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 3) Literals: (often referred to as constants) are data items that never change their value during a program run.
        (i) Integer-constants
        (ii) Charatrer-constants
        (iii) Floating-constant
        (iv) String-literal
 
 (i) Integer constants are whole numbers without any fractional part. An integer constant must have at least one digit and must not contain any decimal point. It may contain + or - sign.
    a. Decimal Integer constant
        An integer constant consisting of a sequence of digits is taken to be decimal integer constant unless it begins with digit zero (0).
    b. Octal Integer constants
        A sequence of digits starting with digit zero (0) is taken to be an octal integer. Octal numbers recognize digits 0-7 only
    c. Hexadecimal Integer Constants
        A sequence of digits preceded by 0x or 0X is taken to be an hexadecimal integer.
 
 (ii) Character Constant is single character enclosed in single quotes, as in 'p'. A character constant in C++ must contain one character enclosed in    single quotation marks.
 
 (iii) Floating Constants / Real Constants are numbers having gractional parts. These may be written in one of the two forms called fractional form or the exponent form.
    A real constant in fractional form must have at least one digit before a decimal point and at least one digit after the decimal point. It may also have + or - sign preceding it.
 A real constant in exponent form has two parts: a mantissa and an exponent. The mantissa must be either an integer or a proper real constant. The mantissa is followed by a letter E or e and the exponent. The exponent must be an integer.
 
 (iv) Sting Literals are basically multiple character constants and can be dealt with in two ways in C++.
    If enclosed in single quotes, these are treated as character constants and if enclosed in double quotes, these are treated as string-literals.
    Each string literal is automatically added with a terminating character '\0'. Thus, the string "abc" will actually be represented as "abc\0" in the memory and its size is not 3 but 4 characters (inclusive of terminator character).
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 4) Punctuators are used to enhance a program's readibility and give proper meaning to statements, expressions etc. as per syntax
 Examples: [], (), {}, ;, :, *, =, # ....etc
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 5) Operators are token that trigger some computation or action when applied to variables and other objects in an expression.
 I/O Operators ( << and >> ), Arithmetic Operators (+,-,*,/,%), Increment/Decrement Operators (++,--), Relatonal Operators (==, <, >, <=, >=, !=), Logical Operators (&&,||,!).

 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 Data Types: are the means to identify the type of data and associated operations for handling it.
    (i) Fundamental Types
    (ii) Derived Types
 
 (i) Fundamental Data Types in C++: int, char, float, double, void
 
 int: integers are whole numbers and have no fractional parts. int represent the integers in C++. An identifier declared as int becomes an integer variable and can hold integer values only.
      Example: int a;, int Roll_Number; ...
 
 char: If a character is stored in a character variable, its value is equivalent to the ASCII integer code of that character. An identifier declared as char becomes a character variable.
       Char type is often said to be an integer type. It is said so because letters, symbols etc. are represented in memory by associated number codes which are integers.
    example: char a = "@"; Here, variable a stores the ASCII integer number for @.
 
 float: An identifier declared as float becomes a floating - point variable and can hold floating point numbers only (fractional numbers)
        Can also be written in exponent notation.
    Example: 147.9101 can also be written as 1.479101E02
 
 double: The data type double is used for handling double precision floating point numbers. It occupies twice as much memory as type float and stores floating point numbers with much larger range and precision.
 
 void: type specifies an empty set of values. It is used as the return type for functions that do not return a value.
 
 (ii) Derived Data types: array, functions, pointers, references, constants, classes, structures, unions and enumerations.
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 Data Type Modifiers: the basic data types may have various modifiers preceding them. Modifiers are used to alter the meaning of the base type to fit various situations more precisely.
    signed, unsigned, long, short are a few modifiers.
 
 Integer Types:
 - short int has 2 bytes
 - unsigned short / signed short int has 2 bytes
 - long / unsigned long/ signed long int has 4 bytes
 
 Character Types:                                                                                                           1 Byte = 8 bits
 A single byte can represent the whole range of 256 known characters
 - char/ unsigned char / signed char has 1 byte
 
 Floating point Types:
 - float has 4 bytes
 - double has 8 bytes
 - long double has 10 bytes
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 Variables: represent named storage locations whose values can be manipulated during program run.
 Syntax: type name; where type is any C++ data type and name is the variable name.
 example: int age = 10;
          double area;
 
 A variable can also be initialised dynamically, i.e., an expression is given at the place of its declaration which is evaluated at runtime and the variable actually gets its first value at runtime after the evaluation of the expression.
 example: float avg = sum/count;
 
 A variable can also be declared constant using keyword const so that its value can never be changed during program run.
 example: const int a=50;
 **Note** A constant variable must be initialised at the time of its declaration.
 
 --------------------------------------------------------------------------------------------------------------------------------------------------
 
 ARRAYS:
 Arrays are a way to group a number of items into a larger unit. Arrays can have data items of simple types like int or float, or even user defined data types like structures and objects. Syntax: type array-name [size]; where type declares the base type of the array, which is the type of each element in the array.
    Arrays can be indexed by using array-name[0] to array-name[n-1] where n = size of array.
    Example: int marks [50]; declares an array named marks of size 50 where all the elements inside are integers.
 
 C++ does not have string data type rather it implements strings as single-dimension character arrays. A string is defined as a character array that is terminated by a null charcter '\0'. For this reason, character arrays are declared one character longer than the largest string they can hold.
 --------------------------------------------------------------------------------------------------------------------------------------------------
 REMEMBER: A return statement can return only one value from a function at a time.
 --------------------------------------------------------------------------------------------------------------------------------------------------
*/

// pre-processor directives
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main();

// basic programs
void circle();
void distance();
float SUMFUN(float x, int N);

// conditional statements ( if, else )
void temp_conversion();
void week_day();

//loops ( for, while )
void factorial();
void rectangle();

// strings
void char_case_change();
void str_length();
void char_count();

// arrays
void student_array();
void str_palindrome();
void largest_element();

// call by value and reference
void call_by_value(int orig);
void call_by_reference(int &orig); // notice the difference in the parameters

// structure basics
void structure1();
// passing structures to functions through call by value and call by reference
struct Emp
{
    int empno;
    char name[26];
    double salary;
};
Emp e1;
void ReadEmp(Emp &e);
void ShowEmp(Emp e);


int main()
{
 

    circle();
    distance();
    
    float x;
    int N;
    std :: cout << "Enter x: " << std :: endl;
    std :: cin >> x;
    N = x;
    SUMFUN(x,N);
    
    temp_conversion();
    week_day();
    
    factorial();
    rectangle();
    
    char_case_change();
    str_length();
    char_count();
    
    student_array();
    str_palindrome();
    largest_element();
    
    int orig = 10;
    std :: cout << "The original value is: " << orig << std :: endl;
    call_by_value(orig);
    call_by_reference(orig);
    std :: cout << "The value after \"call_by_function\" is : " << orig << std :: endl;
    
    structure1();
    // passing structures to functions through call by value and call by reference
    ReadEmp(e1);
    ShowEmp(e1);
    


}


void circle()
{

    float r;
    std :: cout << "Enter the radius of circle: " << std :: endl;
    std :: cin >> r;
    float area,perimeter;
    area = M_PI*r*r;
    perimeter = 2*M_PI*r;
    std :: cout << "The area is: " << area << " sq units" << std :: endl;
    std :: cout << "The perimeter is: " << perimeter << " units" << std :: endl;
}

void distance()
{
    float x1, y1, x2, y2;
    float dist = 0;
    std :: cout << "Enter the first (x1,y1) coordinates: " << std :: endl;
    std :: cin >> x1 >> y1;
    std :: cout << "Enter the second (x2,y2) coordinates: " << std :: endl;
    std :: cin >> x2 >> y2;
    dist = std :: sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    std :: cout << "The distance between the two given points is: " << dist << " units" << std :: endl;
}

float SUMFUN(float x, int N)
{
    float sum = 0, sign = +1, term = 0;
    sum += 1;
    for (int i=2; i<=N; i++)
    {
        sign *= -1;
        term = ((sign * std :: pow(x,i))/i);
        sum += term;
    }
    std :: cout << "The sum is: " << sum << std :: endl;
    return sum;
}

void temp_conversion()
{
    int choice;
    float temp1, ftemp;
    std :: cout << "Temp converison menu: " << std :: endl;
    std :: cout << "1) Fahrenheit to Celsius" << std :: endl;
    std :: cout << "2) Celsius to Fahrenheit" << std :: endl;
    std :: cout << "Enter your choice: " << std :: endl;
    std :: cin >> choice;
    
    if (choice == 1)
    {
        std :: cout << "Enter the temperature in Fahrenheit: " << std :: endl;
        std :: cin >> temp1;
        ftemp = (temp1 - 32) / 1.8;
        std :: cout << "The temperature in Celsius is: " << ftemp << " C" << std :: endl;
    }
    else
    {
        std :: cout << "Enter the temperature in Celsius: " << std :: endl;
        std :: cin >> temp1;
        ftemp = (1.8*temp1)+32;
        std :: cout << "The temperature in Fahrenheit is: " << ftemp << " F" << std :: endl;
    }
}

void week_day()
{
    int d;
    std :: cout << "Enter number of week's day (1-7):" << std :: endl;
    std :: cin >> d;
    switch (d)
    {
        case 1 : std :: cout << "Sunday" << std :: endl;
            break;
        case 2 : std :: cout << "Monday" << std :: endl;
            break;
        case 3 : std :: cout << "Tuesday" << std :: endl;
            break;
        case 4 : std :: cout << "Wednesday" << std :: endl;
            break;
        case 5 : std :: cout << "Thursday" << std :: endl;
            break;
        case 6 : std :: cout << "Friday" << std :: endl;
            break;
        case 7 : std :: cout << "Saturday" << std :: endl;
            break;
    }
}

void factorial()
{
    int i, num, fact = 1;
    std :: cout << "Enter the number: " << std :: endl;
    std :: cin >> num;
    i = num;
    while (num)
    {
        fact *= num;
        --num ;
    }
    std :: cout << "The factorial is: " << fact << std :: endl;
}

void rectangle()
{
    int ch;
    float l, b, pm, ar, diag;
    std :: cout << "Enter the length of the rectangle: " << std :: endl;
    std :: cin >> l;
    std :: cout << "Enter the breadth of the rectangle: " << std :: endl;
    std :: cin >> b;
    bool rec = true;
    while (rec)
    {
        std :: cout << "Rectangle Menu: " << std :: endl;
        std :: cout << "1) Area " << std :: endl;
        std :: cout << "2) Perimeter " << std :: endl;
        std :: cout << "3) Diagonal " << std :: endl;
        std :: cout << "4) Exit " << std :: endl;
        std :: cout << "Enter your choice: " << std :: endl;
        std :: cin >> ch;
        if (ch==1)
        {
            ar = 0.5*b*l;
            std :: cout << "The area of the rectangle is: " << ar << " sq. units" << std :: endl;
        }
        else if (ch==2)
        {
            pm = 2*(l+b);
            std :: cout << "The perimeter of the rectangle is: " << pm << " units" << std :: endl;
        }
        else if (ch==3)
        {
            diag = std :: sqrt((l*l)+(b*b));
            std :: cout << "The diagonal of the rectangle is: " << diag << " units" << std :: endl;
        }
        else if (ch==4)
        {
            std :: cout << "Thank you for using the rectangle calculator." << std :: endl;
            rec = false;
        }
        else
        {
            std :: cout << "Wrong input! Please enter again!" << std :: endl;
        }
    }
}

void char_case_change()
{
    char ch;
    std :: cout << "Enter a character to change its case: " << std :: endl;
    std :: cin >> ch;
    if (ch >= 65 && ch <= 90)                           // upper case
    {
        ch = ch + 32;                                   // change to lower case
        std :: cout << "The lower case character is: " << ch << std :: endl;
    }
    if (ch >= 97 && ch <= 122)                      // if lower case
    {
        ch = ch - 32;                               // change to upper case
        std :: cout << "The upper case character is: " << ch << std :: endl;
    }
}

void str_length()
{
    char str[51];              // string of size 50
    long len;                  // declare according to the size of string; int len will result in error
    std :: cout << "Enter a string (max 50 characters / no space): " << std :: endl;
    std :: cin >> str;
    len = std :: strlen(str);
    std :: cout << "The length of the string is: " << len << std :: endl;
}

void char_count()
{
    char ch;
    int chcount = 0;
    const char eol = '\n';
    std :: cout << "Enter a character: " << std :: endl;
    std :: cin >> ch;
    while (ch != eol)
    {
        chcount ++ ;
        std :: cout.put(ch) << std :: endl;
        std :: cin.get(ch);                 // The difference between cin>>ch and cin.get(ch) is that when >> operator is used, the white spaces (tabs), spaces etc.
                                            // and new line characters are ignored whereas it is not so with cin.get(ch);
    }
    std :: cout << "The number of characters entered (including space): " << chcount << std :: endl;
}

void student_array()
{
    float marks[5];             // initialization of array
    // loop to read 5 marks
    for (int i=0; i<5; i++)
    {
        std :: cout << "Enter the mark of " << i+1 << " student: " << std :: endl;
        std :: cin >> marks[i];
    }
    std :: cout << std :: endl;
    
    // loop to print 5 marks
    for (int i=0; i<5; i++)             // a way to index through the array
    {
        std :: cout << "The mark of student: " << i+1 << " is: " << marks[i] << std :: endl;
    }
}

/*
void str_palindrome()
{
    char str[80];
 
    std :: cout << "Enter a string (max 79 char): " << std :: endl;
    std :: cin.getline(str,80);
 
    long len;
    const char ch = '\0';
    while (str[len] != ch)
    {
        len++;
    }
    int i,j, flag = 1;
    for (i = 0, j = len[str]-1; i < len/2; ++i, --j)
        {
            if (str[i] != str[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            std :: cout << "It is palindrome." << std :: endl;
        }
        else
        {
            std :: cout << "It is not a palindrome." << std :: endl;
        }
}
 */

void largest_element()
{
    int n=0;
    std :: cout << "Enter the size of array: " << std :: endl;
    std :: cin >> n;
    float arr[n];
    
    std :: cout << "Enter the elements" << std :: endl;
    for (int i=0; i<n; i++)
    {
        std :: cout << "Enter " << i+1 << " element: " << std :: endl;
        std :: cin >> arr[i];
    }
    // checking for max element
    int max = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    std :: cout << "The maximum element of the array is: " << max << std :: endl;
    
}

void call_by_value(int orig)
{
    // The call by value method copies the values of actual parameters into the formal parameters, i.e.
    // the function creates its own copy of argument values and then uses them.
    // We cannot alter the variables that are used to call the function because any change that occurs inside
    // the function is on the funtion's copy of the argument value. The original copy of the argument remains intact.
    orig = 20;
    std :: cout << "Value of orig in function call_by_value() is: " << orig << std :: endl;
}

void call_by_reference(int &a)
{
    // calling by reference makes an alias for the original variables, i.e., a reference to the
    // original variable is passed. Now, the variable's name can be accessed by any of the two names.
    // Formal parameters become references (aliases) to the actual parameters, and the function does not
    // create a copy of original variables, rather, works with the original data and any change in the values
    // gets reflected to the data.
    a = 20;
    //orig += a;
    std :: cout << "The value of orig in function call_by_reference() is: " << a << std :: endl;
}

// A structure is a collection of data while a class is a collection of data and functions.
// Basically, a structure is a class declared with keyword struct and by default, all memebers are public in a structure.
void structure1()
{
    struct addr
    {
        int houseno;
        char area[26];
        char city[26];
        char state[26];
        int marks[5];       // array of size 5
    };
    addr address1;          // address1 is a variable of type addr
    
    // accessing arrays within structures
    std :: cout << "Enter the marks: " << std :: endl;
    for (int i=0; i<5; i++)
    {
        std :: cout << "Enter mark for " << i+1 << " : " << std :: endl;
        std :: cin >> address1.marks[i];
    }
    std :: cout << "Printing array of marks: " <<  std :: endl;
    for (int i=0; i<5; i++)
    {
        std :: cout << address1.marks[i] << std :: endl;
    }
    // we can also access individual elements of array by: address1.marks[1] (changing the index number)
    
    struct emp
    {
        int empno;
        char name[26];
        char desig[26];
        addr address;       // address is a variable of type addr  (nesting of structures)
        float basic;
    };
    emp worker1;            // worker1 is a variable of type emp
    std :: cout << "Enter the emp number: " << std :: endl;
    std :: cin >> worker1.empno;
    std :: cout << "Enter worker name: " << std :: endl;
    std :: cin >> worker1.name;
    std :: cout << "Enter worker designation: " << std :: endl;
    std :: cin >> worker1.desig;
    std :: cout << "Enter worker basic salary: " << std :: endl;
    std :: cin >> worker1.basic;
    
    std :: cout << "///// Accessing struct addr from struc emp /////" << std :: endl;
    std :: cout << "Enter worker houseno: " << std :: endl;
    std :: cin >> worker1.address.houseno;
    std :: cout << "Enter worker area: " << std :: endl;
    std :: cin >> worker1.address.area;
    std :: cout << "Enter worker city: " << std :: endl;
    std :: cin >> worker1.address.city;
    std :: cout << "Enter worker state: " << std :: endl;
    std :: cin >> worker1.address.state;
    
    std :: cout << std :: endl;
    std :: cout << "Printing Worker1 Details" << std :: endl;
    std :: cout << "Empno: " << worker1.empno << std :: endl;
    std :: cout << "Name: " << worker1.name << std :: endl;
    std :: cout << "Desig: " << worker1.desig << std :: endl;
    std :: cout << "Houseno: " << worker1.address.houseno << std :: endl;
    std :: cout << "Area: " << worker1.address.area << std :: endl;
    std :: cout << "City: " << worker1.address.city << std :: endl;
    std :: cout << "State: " << worker1.address.state << std :: endl;
    
}


void ReadEmp(Emp &e)
{
    // pass by reference
    std :: cout << "Enter employee no: " << std :: endl;
    std :: cin >> e.empno;
    std :: cout << "Enter emplotee name: " << std :: endl;
    std :: cin >> e.name;
    std :: cout << "Enter employee salary: " << std :: endl;
    std :: cin >> e.salary;
    
}

void ShowEmp(Emp e)
{
    std :: cout << "Employee Details" << std :: endl;
    std :: cout << "Empno: " << e.empno << std :: endl;
    std :: cout << "Name: " << e.name << std :: endl;
    std :: cout << "Salary: " << e.salary << std :: endl;
}


// Arrays of Structures
// To declare an array of structures, you must first define a structure and then declare an array variable of that type.
// E.g: To store addresses of 100 members, we need an array
// Now, we declare a struct addr

//    struct addr
//  {
//        int houseno;
//        char area[26];
//        char city[26];
//        char state[26];
//
//  };
// Now to declare a 100 element array of the above structure, we will write
//      addr mem_addr[100];
// This creates 100 sets of variables that are organised as defined in the struct addr
// To access a specific struct, index the structure name. For instance, print the houseno of struct at position 8,
//      std :: cout << mem_addr[7].houseno << std :: endl;

