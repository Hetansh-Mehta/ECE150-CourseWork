// Pre-processor directives
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

// Function declaration
int main();
int interval_calculator();

// Function definition
// main function
int main()
{
    interval_calculator();
    return 0;
}

// interval_calculator function
int interval_calculator()
{
    // defined --> if the immediate interval is NOT defined, i.e (a>b)
    bool defined = false;
    bool defined2 = false; // checks if the memory is not defined
    double Immediate1 = 0.0,Immediate2 = 0.0, Modify=0.0; // Global Variables
    double Memory1=0.0, Memory2=0.0; // First used in MS Function
    
    //************ WHILE LOOP *******************************************************************************
    bool T=true;
    while (T)
    {
        std :: string cmd (" ");  // local variable = cmd
        double a = 0.0,b = 0.0;   // local variables a,b
        std :: cout << "input :> " ;
        std :: cin >> cmd;
        //******************************** ENTER  **********************************************************
        if (cmd == "enter")
        {
            std :: cin >> a >> b;
            
            if (a>b)
            {
                // nothing is initialized
                //std :: cout << c << d << std :: endl;
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                // something valid is initialized earlier
                else
                {
                    std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
            else
            {
                Immediate1=a;
                Immediate2=b;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                defined = true;
            }
            
        }
        //*********************************** END OF ENTER **************************************************

        
        //********************************** NEGATE **********************************************************
        else if (cmd == "negate")
        {
            if (defined == false)
            {
                //std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                std :: cout << "--" << std :: endl;
            }
            
            else
            // if the interval is defined .. i.e., a<b
            {
                //double e=0.0;
                Modify=-Immediate1;
                Immediate1=-Immediate2;
                Immediate2=Modify;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
        }
        //********************************** END OF NEGATE****************************************************
        
        //********************************** INVERT ***********************************************************
        
        else if (cmd=="invert")
        {
            if (defined == false)
            {
                //std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                std :: cout << "--" << std :: endl;
            }
            
            else if ((Immediate1 <= 0) && (Immediate2 >= 0))
            {
                std :: cout << "Error: division by zero" << std :: endl;
                std :: cout << "--" << std :: endl;
                defined = false;                                        // added this.w
            }
            
            else
            {
                Modify = (1/Immediate1);
                Immediate1 = (1/Immediate2);
                Immediate2 = Modify;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
        }
        //********************************** END OF INVERT **************************************************

        //********************************* MS: Immediate to Memory  *****************************************
        
        else if (cmd=="ms")
        {
            if (defined == false)
            {
                //std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                Memory1 = Immediate1;
                Memory2 = Immediate2;
                std :: cout << "[" << Memory1 << ", " << Memory2 << "]" << std :: endl;
                defined2 = true;
            }
        }
        //********************************** END OF MS  *****************************************************
        
        //*********************************** MR Memory to Immediate ****************************************
        else if (cmd=="mr")
        {
            if (defined2 == false)
            {
                //std :: cout << "Error: invalid interval as " << a << ">" << b << std :: endl;
                //std :: cout << "--" << std :: endl;
                
                if ( defined == false )
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                
            }
            
            else
            {
                Immediate1 = Memory1;
                Immediate2 = Memory2;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
        }
        //*********************************** END OF MR *****************************************************
        
        //************************************* MC: Clears The memory ( unitialized memory ) ****************
        else if (cmd == "mc")
        {
            defined2 = false;             // Making the memory not initialized
            if (defined == false)         // Checking if immediate is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            else
            {
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
        }
        //********************************** END OF MC ******************************************************
        
        //*********************************** M+ ******** ***************************************************
        else if (cmd == "m+")
        {
            if (( defined == true ) && ( defined2 == true ))
            {
                Memory1 += Immediate1;
                Memory2 += Immediate2;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
            else if (defined == false)
            {
                std :: cout << "--" << std :: endl;
            }
            else
            {
               std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
        }
        //********************************* END OF M+ ******************************************************
        
        //*************************************** M- ******** **********************************************
        else if (cmd == "m-")
        {
            if (( defined == true ) && ( defined2 == true ))
            {
                Memory1 -= Immediate1;
                Memory2 -= Immediate2;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
            else if ((defined == false) || (defined2 == false))
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
        }
        //******************** END OF M- *******************************************************************
        
        //******************** SCALAR_ADD_C ****************************************************************
        
        else if (cmd == "scalar_add")
        {
            double c;                                // local variable :- what the user inputs
            std :: cin >> c;
            
            if (defined == false)                    // Immediate interval is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                Immediate1 += c;
                Immediate2 += c;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
        }
        //************************ END Of SCALAR_ADD_C ******************************************************
        
        //*************************** SCALAR_SUBTRACT_C *****************************************************
       
        else if (cmd == "scalar_subtract")
        {
            double c;                                // local variable :- what the user inputs
            std :: cin >> c;
            
            if (defined == false)                    // Immediate interval is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                Immediate1 -= c;
                Immediate2 -= c;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
            
        }
        //**************************** END OF SCALAR_SUBTRACT_C ********************************************
        
        //***************************** SCALAR_MULTIPLY_C **************************************************
        
        else if (cmd == "scalar_multiply")
        {
            double c;                                // local variable :- what the user inputs
            std :: cin >> c;
            
            if (defined == false)                    // Immediate interval is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                if (c>0)
                {
                    Immediate1 *= c;
                    Immediate2 *= c;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                else if (c==0)
                {
                    std :: cout << "[0,0}" << std :: endl;

                }
                else                                // c < 0 ;
                {
                    Modify = Immediate1/c;
                    Immediate1 = Immediate2/c;
                    Immediate2 = Modify;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
        }
        //********************************** END OF SCALAR_MULTIPLY_C **************************************
        
        //********************************* SCALAR_DIVIDE_C ************************************************
        else if (cmd == "scalar_divide")
        {
            double c;                                // local variable :- what the user inputs
            std :: cin >> c;
            
            if (defined == false)                    // Immediate interval is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                if (c>0)
                {
                    Immediate1 /= c;
                    Immediate2 /= c;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                else if (c==0)
                {
                    std :: cout << "Error: division by zero" << std :: endl;
                    std :: cout << "--" << std :: endl;
                    defined = false;
                }
                else                                // c < 0 ;
                {
                    Modify = Immediate1/c;
                    Immediate1 = Immediate2/c;
                    Immediate2 = Modify;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                
            }
            
        }
        //********************************** END OF SCALAR_DIVIDE_C ****************************************
    

        //********************************** SCALAR_DIVIDED_BY_C *******************************************
        else if (cmd == "scalar_divided_by")
        {
            double c;                                // local variable :- what the user inputs
            std :: cin >> c;
            
            if (defined == false)                    // Immediate interval is not initialized
            {
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                if ((Immediate1 <= 0)&&(Immediate2 >= 0))
                {
                    std :: cout << "Error: division by zero" << std :: endl;
                    std :: cout << "--" << std :: endl;
                    defined = false;
                }
                else if (c>0)
                {
                    Immediate1 = c/Immediate1;
                    Immediate2 = c/Immediate2;
                    Modify = Immediate1;
                    Immediate1 = Immediate2;
                    Immediate2 = Modify;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                else                                // c < 0 ;
                {
                    
                    Immediate1 = c/Immediate1;
                    Immediate2 = c/Immediate2;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
                
            }
            
        }
        
        //********************************** END OF SCALAR_DIVIDED_BY_C ************************************
        
        //********************************** INTERVAL_ADD_C_D **********************************************
        else if (cmd == "interval_add")
        {
            double c,d;                                // local variables :- what the user inputs
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << ">" << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << ">" << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    Immediate1 += c;
                    Immediate2 +=d;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
        }
        //**************************** END OF INTERVAL_ADD_C_D *********************************************
        
        //**************************** INTERVAL_SUBTRACT_C_D ***********************************************
        else if (cmd == "interval_subtract")
        {
            double c,d;                                // local variables :- what the user inputs
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    Immediate1 -= d;
                    Immediate2 -=c;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
        }
        //**************************** END OF INTERVAL_SUBTRACT_C_D *****************************************
        
        //**************************** INTERVAL_MULTIPLY_C_D ************************************************
        else if (cmd == "interval_multiply")
        {
            double c,d,e,f,g,h,min,max;
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    e=Immediate1*c;
                    f=Immediate1*d;
                    g=Immediate2*c;
                    h=Immediate2*d;
                    min = std :: min ({e,f,g,h});                  // using algorithm pre processor
                    max = std :: max ({e,f,g,h});
                    Immediate1 = min;
                    Immediate2 = max;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
        }
        //********************************* END OF INTERVAL_MULTIPLY_C_D ***********************************
        
        //********************************* INTERVAL_DIVIDE_C_D ********************************************
        else if (cmd == "interval_divide")
        {
            double c,d,e,f,g,h,min,max;
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else if ((c<0)&&(d>0))
                {
                    std :: cout << "Error: division by zero" << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else                                                    // (c && d < 0) || (c &&d > 0 )
                {
                    e=Immediate1/c;
                    f=Immediate1/d;
                    g=Immediate2/c;
                    h=Immediate2/d;
                    min = std :: min ({e,f,g,h});                  // using algorithm pre processor
                    max = std :: max ({e,f,g,h});
                    Immediate1 = min;
                    Immediate2 = max;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            
        }
        
        //********************************* END OF INTERVAL_DIVIDE_C_D *************************************
        
        //********************************* INTERSECT_C_D **************************************************
        else if (cmd == "intersect")
        {
            double c,d;
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    if ((c>Immediate2) || (d<Immediate1))
                    {
                        std :: cout << "--" << std :: endl;
                        defined = false;
                    }
                    else
                    {
                        if ((c>Immediate1)&&(c<Immediate2))
                        {
                            Immediate1=c;
                        }
                        if ((d>Immediate1) && (d<Immediate2))
                        {
                            Immediate2=d;
                            
                        }
                        std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                    }
    
                }
            }
            
        }
        //********************************* END OF INTERSECT_C_D *******************************************
        
        //********************************* INTEGERS *******************************************************
        else if (cmd == "integers")
        {
            double j;               // local variables :- what the user inputs
            
            if (defined == false)
            {
                //std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                std :: cout << "--" << std :: endl;
            }
            
            else
            {
                for (j=std::ceil(Immediate1); j < std::floor(Immediate2);j++)
                {
                    std :: cout << j << ", " ;
                }
                std :: cout << std :: floor(Immediate2);
                std :: cout << std :: endl;
                std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
            }
        }
        //********************************* END OF INTEGERS ***********************************************
        
        //********************************* CARTESIAN_INTEGERS *********************************************
        else if (cmd == "cartesian_integers")
        {
            double c,d,i,j,k,l,m;
            std :: cin >> c >> d;
            
            if (c>d)
            {
                if (defined == false)
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    std :: cout << "Error: invalid interval as " << c << " > " << d << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
            else
            {
                if (defined == false)
                {
                    std :: cout << "--" << std :: endl;
                }
                else
                {
                    i = std :: ceil(c);
                    j = std :: floor(d);
                    k = std :: ceil(Immediate1);
                    l = std :: floor(Immediate2);
                    double temp = (l-k+1) * (j-i+1);
                    double count=0;
                    
                    for (double ktest{k}; ktest<=l; ktest++)
                    {
                        m=i;
                        for (double mtest{i}; mtest<=j; mtest++)
                        {
                            std :: cout << "(" << ktest << "," << mtest << ")";
                            count++;
                            if(count < temp)
                            {
                                std :: cout << ", ";
                            }
                        }
                    }
                    std :: cout << std :: endl;
                    std :: cout << "[" << Immediate1 << ", " << Immediate2 << "]" << std :: endl;
                }
            }
        }
        
        //********************************* END OF CARTESIAN_PRODUCT **************************************
        
        
        
        //********************************** EXIT **********************************************************
        else if (cmd == "exit")
        {
            std :: cout << "Bye bye: Terminating interval calculator program." << std :: endl;
            T =0;
        }
        //******************************** END OF EXIT ******************************************************
        
        else
        {
            std :: cout << "Error: illegal command" << std :: endl;
        }
    }
    // end of while loop
    return 0;
}
// end of interval calculator

