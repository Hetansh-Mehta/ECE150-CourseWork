//
#include<iostream>

// function declaration

#ifndef MARMOSET_TESTING
int main();
#endif


bool is_leap_year(int input_year);

// function definition

#ifndef MARMOSET_TESTING
int main()
{

    int input_year = 0;
    std::cout << "Plaese enter a year." << std :: endl;
    std::cin >> input_year;
    
    //calling function
    if(is_leap_year(input_year)) {
        std :: cout <<input_year<<" is a leap year!" << std :: endl;
    }
    else
    {
        std :: cout <<input_year << " is not a leap year!" << std :: endl;
    }
    
    return 0;
}
#endif

bool is_leap_year(int input_year)
{
    if (input_year < 1582)
        return false;
    else if (input_year % 4 == 0  || input_year % 400 == 0 )
        //std :: cout << input_year << " is a leap year!";
        return true;
    else
        //std :: cout << input_year << " is not a leap year!";
        return false;
    
}
