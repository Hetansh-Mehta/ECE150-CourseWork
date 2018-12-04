#include <iostream>

// function declaration

#ifndef MARMOSET_TESTING
int main();
#endif

float rolling_average(float num1, float num2, float num3);

// function definition

#ifndef MARMOSET_TESTING
int main()
{
    float input_number{0.0}, average{0};
    float num1{0.0}, num2{0.0}, num3{0.0};
    int num_inputs{0};
    
    while (input_number >= 0)
    {
        std :: cout << "Enter a number." << std :: endl;
        std :: cin >> input_number;
        
        num_inputs++;
        
        num1 = num2;
        num2 = num3;
        num3 = input_number;
        
        if (num_inputs >= 3 && input_number >= 0.0)
        {
            average = rolling_average(num1, num2, num3);
            std :: cout << "rolling average is: " << average << std :: endl;
        }
    }
    return 0;
}
#endif

float rolling_average ( float num1, float num2, float num3)
{
    return ((num1+num2+num3)/3.0);
}
