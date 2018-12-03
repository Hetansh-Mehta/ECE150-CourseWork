/*
 Implement a C++ function called int pascal_triangle( int n) that prints to the console Pascal’s triangle for n rows of the triangle, and returns the number of integers in the triangle.Use an iterative method to implement this function (no recursion).
 */

#include <iostream>

// function declaration

#ifndef MARMOSET_TESTING
int main();
#endif

int pascal_triangle(int n);
int pascal_triangle_recursive(int n);
int choose(int i, int j);

// function definition

#ifndef MARMOSET_TESTING
int main()
{
    int n ;
    std :: cout << "Enter the number of rows: " << std :: endl;
    std :: cin >> n;
    pascal_triangle(n);                 //  calling the function
    pascal_triangle_recursive(n);
    return 0;
}
#endif

int pascal_triangle(int n)
{
    int i,j,x,sum=0;
    for (i=0; i<=n; ++i)
    {
        x=1;
        for (j=0; j<=i; ++j)
        {
            std :: cout << x << " " ; // std :: endl;
            x = x * (i-j) / (j + 1);
            sum += 1;
        }
        std :: cout << std :: endl;
    }
    //std :: cout << "No of integers in the triagnle are: " << sum << std :: endl;
    return sum;
}

int choose (int i, int j)
{
    if (i==0 || j==0)
    {
        return 1;
    }
    else if (i==j)
    {
        return 1;
    }
    else
        return choose( i -1, j - 1) + choose ( i - 1, j);
}


int pascal_triangle_recursive(int n)
{
    int sum=0;
    for (int i=0; i<=n; ++i)
    {
        for (int j=0; j<=i; ++j)
        {
            std :: cout << choose(i,j) << " " ;
            sum += 1;
        }
        std :: cout << std :: endl;
    }
    //std :: cout << "Sum is: " << sum << std :: endl;
    return sum;
}

