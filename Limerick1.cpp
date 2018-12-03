// This example code is an exercise in the mechanics of C++ classes.
// It demonstrates the use of multiple constructors, a destructor, and
// use of the implicit parameter (this).

#include <iostream>

class Limerick {
public :
    Limerick ();
    Limerick (std::string init_string);
    ~Limerick ();
    void output ();
    void set_line (std::string const & set_line);
    void copy_line (Limerick const & copy_limerick);
private :
    std::string line;
};

int main();

int main()
{
    Limerick first_limerick{};
    Limerick * p_second_limerick{new Limerick{"He was banned from the train,"}};

    first_limerick.output();
    p_second_limerick->output();
    p_second_limerick->set_line("And now travels only by bus.");
    first_limerick.copy_line(*p_second_limerick);
    p_second_limerick->set_line("Not allowed on a plane,");

    delete p_second_limerick;
    p_second_limerick = nullptr;

    return 0;
}

Limerick::Limerick()
{
    std::cout << "There was an odd fellow named Gus," << std::endl;

    // use of implicit parameter. equivalent to this->line
    line = "When travelling he made such a fuss.";
}

Limerick::Limerick(std::string init_string)
{
    // use of implicit parameter. equivalent to this->line
    line = init_string;
}

Limerick::~Limerick()
{
    // use of implicit parameter. equivalent to this->line
    std::cout << line << std::endl;
}

void Limerick::output ()
{
    // use of implicit parameter. equivalent to this->line
    std::cout << line << std::endl;
}

void Limerick::set_line (std::string const & set_line)
{
    // use of implicit parameter. equivalent to this->line
    line = set_line;
}

void Limerick::copy_line (Limerick const & copy_limerick)
{
    // can access the private member variable because copy_limerick
    // is of the same class that we are currently within
    line = copy_limerick.line;
}


// p_second_limerick -> output(); means (*p_second_limerick).output();


// 23 : Declaring instance of limerick
// 40 : std :: cout << "There was an ..."
// 43 : set the line of first_limerick
// 24 : declaring a dynamic instance of limerick
// 49 : set the line of p_second_limerick
// 26 : calls the output function for first_limerick
// 61 : std :: cout << "When travelling ..... " line 43
// 27 : calls the output function for p_second_limerick
// 61 : std :: cout << "He was banned ...." line 49
// 28 : call to set_line function for p_second_limerick
// 67 : set the line of p_second_loimerick
// 29 : call to copy_line function for first_limerick
// 74 : line = copy_limerick.line; // The line refers to the private member variable within the object first_limerick and the copy_limerick refers to the parameter passed to the function on line 70. So copy_limerick is *p_second_limerick. Therefor the end effect is: "And now travels...." Overwrites "When travelling....."
//    : copy from p_second_limerick to first_limerick
// 30 : call to set_line for p_second_limerick which will jump to line 67
// 67 : set the line of p_seond_limerick to "Not allowed on .. "
// 32 : deallocate dynamic Limerick as it will automatically call the deconstructor and goto line 52
// 52 : std :: cout << "Not allowed ..... "
// 33 : nullptr
// 35 : return 0 ; but the first_limerick is about to go out of scope so we jump again to line 52 so destructor is called for first_limerick
// 52 : std :: cout << "And now travels ... "   This is the local variable going out of scope.


// first_limerick (line):
// "When travelling ... " line 43
// after line 74, it gets overwritten by "And now travels......" line 79

// *p_second_limerick(linr):
// "He was banned ...." line 49 // crossed out after line 67 and set as : (after line 28)
// "And now travels .... " line 67 // crossed after line 67 and set as : (after line 30)
// "NOt allowed .... " line 67

// output:
// There was an odd fellow named Gus
// When travellign he made such as fus
// He was banned from the train
// Not allowed on a plane,
// And now travels only by bus

