#include <iostream>
#include <cmath>


struct poly_t
{
    double *a_coeffs;           // array of coefficients
    unsigned int degree;         // the degree of the polynomial
};


// declarations
// Polynomial initialization
void init_poly(poly_t &p, double const init_coeffs[],unsigned int const init_degree );
// polynomial destructor
void destroy_poly(poly_t &p);
// polynomial degree
unsigned int poly_degree(poly_t const &p);
// polynomial coefficient
double poly_coeff(poly_t const &p, unsigned int n);
// polynomial evaluation
double poly_val(poly_t const &p, double const x);
// polynomial addition
void poly_add(poly_t &p, poly_t const &q);
// polynomial subtraction
void poly_subtract (poly_t &p, poly_t const &q);
// polynomial multiplication
void poly_multiply(poly_t &p, poly_t const &q);
// polynomial division
double poly_divide(poly_t &p, double r);
// polynomial differentiation
void poly_diff(poly_t &p);
// polynomial integral approximantion
double poly_approx_int(poly_t const &p, double a, double b, unsigned int n);

#ifndef MARMOSET_TESTING
int main();
#endif

// function definitions

#ifndef MARMOSET_TESTING
int main()
{
    double coef1 [8] = {1,2,3,4,5,6,7,8};
    // 9.47375x^8+14.8999x^7+19.4857x^6+1.96222x^5+132.083x^4+1.65549x^3+9.32747x^2+72.0851x^1+0.0499036x^0
    // 11.7395
    double coef2 [1] = {12};
    poly_t p{nullptr, 7};
    poly_t q{nullptr, 0};
    init_poly(p, coef1 , 7);
    init_poly(q, coef2, 0);
    //poly_add(p,q);
    //poly_subtract(p,q);
    //poly_multiply(p,q);
    //poly_divide(p,2);
    //poly_divide(q,2);
    //poly_diff(p);
    std :: cout << poly_approx_int(p, 0, 7, 10) << std:: endl;
    //p = 9.407331x^4 + 7.350023x^3 + -1.708769x^2 + -0.045244x + 5.802352     n = 1    a = -0.71129    b = 42.1376
    
    std::cout << p.degree << std::endl;
    for(int i=0; i<p.degree+1; i++)
    {
        std::cout << "coffeficiant " << i << " :" << p.a_coeffs[i] << std::endl;
    }
    
    /*
    std :: cout << q.degree << std :: endl;
    for (int i=0; i <= q.degree; i++)
    {
        std :: cout << "coeff " << i << ": " <<  q.a_coeffs[i] << std :: endl;
    }
     */
}
#endif

void print_poly(poly_t &p)
{
    for (int i=0; i < p.degree; i++)
    {
        std :: cout << p.a_coeffs[i];
    }
}

void check_poly(poly_t const &p)
{
    if (p.a_coeffs == nullptr)
    {
        throw 0;
    }
        
}

//**********************************************************************************************
// polynomial initialization
void init_poly(poly_t &p, double const init_coeffs[],unsigned int const init_degree )
{
    destroy_poly(p);
    p.degree = init_degree;
    // a_coeffs is a pointer
    p.a_coeffs = new double [init_degree + 1]{};   // a_coeffs points to the new memory location of size[init_degree + 1]
    for (int i=0; i <= init_degree; i++)
    {
        //std::cout << "init coeffs at " << i << " : " << init_coeffs[i] << std::endl;
        p.a_coeffs[i] = init_coeffs[i];
    }
}

//**********************************************************************************************
// Polynomial destructor
void destroy_poly(poly_t &p)
{
    delete [] p.a_coeffs;
    p.a_coeffs = nullptr;
    p.degree = 0;
}

//**********************************************************************************************
// Polynomial degree
unsigned int poly_degree(poly_t const &p, unsigned int n)
{
    check_poly(p);
    
    return p.degree;
    
    
}

//**********************************************************************************************
// polynomial coefficient
double poly_coeff(poly_t const &p, unsigned int n)
{
    // asking for leading coeff
    check_poly(p);
    
    if (n > p.degree)
    {
        return 0;
    }
    else
    {
        return p.a_coeffs [n];
    }
    
}

//**********************************************************************************************
// polynomial evaluation
double poly_val(poly_t const &p, double const x)
{
    check_poly(p);
    double sum = 0;
    for (int i=0; i <= p.degree; i++)
    {
        sum += p.a_coeffs[i] * std :: pow(x,i);
    }
    return sum;
}

//**********************************************************************************************
// Polynomial addition
void poly_add(poly_t &p, poly_t const &q)
{
    check_poly(p);
    check_poly(q);
    
    unsigned int a = std :: max(p.degree , q.degree) ;
    double * sum_array = new double [a+1];
    for (int i=0; i <= a ; i++)
    {
        if (i > p.degree)
        {
            sum_array[i] = q.a_coeffs[i];
        }
        else if (i > q.degree)
        {
            sum_array[i] = p.a_coeffs[i];
        }
        else
        {
            sum_array[i] = p.a_coeffs[i] + q.a_coeffs[i];
        }
        
    }
    destroy_poly(p);
    
    /*
    int index = a;
    for ( int i = a -1 ; i >= 0 ; i-- )
    {
        if (sum_array[i] == 0)
        {
            index = i;
        }
        else
        {
            break;
        }
    }
    //p.degree = index;
    */
    init_poly(p,sum_array,a);               // initializing the polynomial
    delete [] sum_array;
}

//**********************************************************************************************
// polynomial subtraction
void poly_subtract(poly_t &p, poly_t const &q)
{
    check_poly(p);
    check_poly(q);
    
    unsigned int a = std :: max(p.degree , q.degree) ;
    double * diff_array = new double [a+1];
    for (int i=0; i <= a ; i++)
    {
        if (i > p.degree)
        {
            diff_array[i] = -q.a_coeffs[i];
        }
        else if (i > q.degree)
        {
            diff_array[i] = p.a_coeffs[i];
        }
        else
        {
            diff_array[i] = p.a_coeffs[i] - q.a_coeffs[i];
        }
        
    }
    destroy_poly(p);
    
    /*
    int index = a;
    for ( int i = a -1 ; i >= 0 ; i-- )
    {
        if (diff_array[i] == 0)
        {
            index = i;
        }
        else
        {
            break;
        }
    }
     */
    //p.degree = index;
    init_poly(p,diff_array,a);               // initializing the polynomial
    delete [] diff_array;
}

//**********************************************************************************************
// polynomial multiplication
void poly_multiply (poly_t &p, poly_t const &q)
{
    check_poly(p);
    check_poly(q);
    
    unsigned int sum_degree = p.degree + q.degree;
    double * mult_array = new double [sum_degree + 1]{};
    for (int i=0; i < p.degree + 1 ; i++)
    {
        for (int j=0; j < q.degree + 1 ; j++)
        {
            mult_array[i+j] += (p.a_coeffs[i] * q.a_coeffs[j]);
        }
    }
    
    init_poly(p, mult_array, sum_degree);
    delete [] mult_array;
}

//**********************************************************************************************
// polynomial division
double poly_divide(poly_t &p, double r)
{
    check_poly(p);
    
    double return_value = 0;
    
    
    if (p.degree == 0)
    {
        double * zero_array = new double [1];
        return_value = poly_val(p,0);
        //p.a_coeffs[0] = 0;
        destroy_poly(p);
        //delete [] p.a_coeffs;
        init_poly(p, zero_array, 0);
        delete [] zero_array;
        zero_array = nullptr;
    }
    else
    {
        unsigned int div_degree = p.degree -1;
        double * div_array = new double [p.degree]{};
        return_value = poly_val(p,r);
        for (int i = p.degree; i > 0; i--)
        {
            if ( i == p.degree )
            {
                div_array[i-1] = p.a_coeffs[i];
            }
            else
            {
                div_array [i-1] = (div_array[i] * r) + p.a_coeffs[i];
            }
        }
        delete[] p.a_coeffs;
        p.a_coeffs = nullptr;
        init_poly(p, div_array, div_degree);
        delete [] div_array;
    }
    //std::cout <<"hello "<< return_value << std:: endl;
    return return_value;
    
    
    //p.a_coeffs = div_array;
    //p.degree -= 1;
    
    
}

//**********************************************************************************************
// polynomial differentiation
void poly_diff(poly_t &p)
{
    check_poly(p);
    
    unsigned int new_degree = p.degree - 1;                         // new degreee = 3
    double * diff_array = new double [new_degree + 1];              // size = 4
    for (int i=0; i < p.degree ; i++)                               // i < 4
    {
        diff_array[i] = p.a_coeffs[i+1] * (i+1);
    }
    //delete [] p.a_coeffs;
    init_poly(p, diff_array, new_degree);
    delete [] diff_array;
}

//**********************************************************************************************
// polynomial integration
double poly_approx_int (poly_t const &p, double a, double b, unsigned int n)
{
    check_poly(p);
    
    double h = (b-a)/n;
    double xk = 0.0;
    double sum = 0.0;
    double integral = 0.0;

    sum+=poly_val(p, a)+poly_val(p, b);
    for (int i=1; i < n; i++)
    {
        xk = (a + (i*h));
        
        /*if ((xk == a) || (xk == b))
        {
            sum += poly_val(p, xk);
        }
        else
        {*/
            sum += (2*poly_val(p, xk));
        //}
        
    }
    integral = (h/2) *(sum);
    
    return integral;
}

//**********************************************************************************************



