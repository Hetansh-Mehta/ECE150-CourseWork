// PROJECT 0 - CALCULATE THE RANGE OF THE BANANA.

#include <iostream>
#include <cmath>


// function decelaration

#ifndef MARMOSET_TESTING
int main();
#endif

double horizontal_velocity(double launch_velocity, double launch_angle);
double vertical_velocity(double launch_velocity, double launch_angle);
double gravity();
double computed_range(double launch_velocity, double launch_angle, double height);


// defining the other functions
double horizontal_velocity(double launch_velocity, double launch_angle)
{
    return launch_velocity * cos((launch_angle*M_PI)/180);
}

double vertical_velocity(double launch_velocity, double launch_angle)
{
    return launch_velocity * sin((launch_angle * M_PI)/180);
}

double gravity()
{
    double g;
    g = 9.80665;
    return g;
}

double computed_range(double launch_velocity, double launch_angle, double height)
{
    double h_velocity, v_velocity, g;
    
    h_velocity = horizontal_velocity(launch_velocity, launch_angle);
    v_velocity = vertical_velocity(launch_velocity, launch_angle);
    g = gravity();
    return ((h_velocity * v_velocity)/g) + ((h_velocity * (sqrt((v_velocity * v_velocity) + 2 * g * height))/g)) ;
    
}

// function definition
#ifndef MARMOSET_TESTING
int main()
{
    double launch_angle [] =  {10, 20, 25.5, 30, 40, 50, 55.5, 60, 70, 75.5, 80, 90 };
    // for loop
    for (int a = 0; a<12; a+=1)
    {
        std :: cout << "The range the banana reaches for the launch angle of " << launch_angle[a] << " degrees is " << computed_range(600, launch_angle[a],10) << std :: endl;
        
    }
    return 0;
}
#endif

