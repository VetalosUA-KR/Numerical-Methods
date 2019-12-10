#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

using namespace std;

double func(double x)
{
    return (pow(x, 2) + 3) * exp(x-5) - 2; // вольфрам
}

double funcPrim(double x)
{
    return 2*x*exp(x-5)+(x*x+3)*exp(x-5);
}

double U(double x)
{
    return func(x)/funcPrim(x);
}

/**
Функции со своим уровнением
*/
double func2(double x)
{
    return (pow(x, 2) + 3) * exp(x-5) - 2; // вольфрам
}

double funcPrim2(double x)
{
    return 2*x*exp(x-5)+(x*x+3)*exp(x-5);
}

double U2(double x)
{
    return func2(x)/funcPrim2(x);
}
/// ////////////////////////////////
double newton2(double x, double epsilon)
{
    int k = 0;
    double h;

    do
    {
        h = - U2(x);
        x += h;
        k++;
    }
    while(fabs(h) >= epsilon);
    return x;
}

double wielopunktowa2(double x, double elipson)
{
    int k = 0;
    double h;

    do
    {
        h = -((1/4.0) * ( U2(x) + ( (3*func2(x)) / funcPrim2(x - (2/9.0) * (2*U2(x) + (func2(x) / funcPrim2(x-U2(x))))) )));
        x += h;
        k++;
    }
    while(fabs(h) >= elipson);
    cout<<"k: "<<k<<"  ";
    return x;
}
/// ////////////////////////////

double newton(double x, double epsilon)
{
    int k = 0;
    double h;

    do
    {
        h = -U(x);
        x += h;
        k++;
    }
    while(fabs(h) >= epsilon);
    return x;
}

double wielopunktowa(double x, double elipson)
{
    int k = 0;
    double h;

    do
    {
        h = -((1/4.0) * ( U(x) + ( (3*func(x)) / funcPrim(x - (2/9.0) * (2*U(x) + (func(x) / funcPrim(x-U(x))))) )));
        x += h;
        k++;
    }
    while(fabs(h) >= elipson);
    cout<<"k: "<<k<<"  ";
    return x;
}

int main()
{
    cout.precision();

    double eps;
    double rez;
    cout<<"metoda wielopunktowa, X-const"<<endl;
    for(int i = 3; i <= 15; i++) // приближена
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps<<" ";
        rez = wielopunktowa(3, eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, E-const"<<endl;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = wielopunktowa(i,eps);
        cout<<"x = "<<rez<<endl;

    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, z bladem, X-const"<<endl;
    double x1 = 0;
    double blad = 0;
    for(int i = 3; i <= 15; i++)
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps;
        rez = wielopunktowa(3, eps);
        cout<<"x = "<<rez;
        blad = fabs(rez - x1);
        cout<<"  blad = "<<blad<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, z bladem, X-const"<<endl;
    x1 = 0;
    blad = 0;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = wielopunktowa(i,eps);
        cout<<"x = "<<rez;
        blad = fabs(rez - x1);
        cout<<"  blad = "<<blad<<endl;
    }

    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, X-const"<<endl;

    for(int i = 3; i <= 15; i++) // приближена
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps<<" ";
        rez = newton(3, eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, E-const"<<endl;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = newton(i,eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, z bladem, X-const"<<endl;
    x1 = 0;
    blad = 0;
    for(int i = 3; i <= 15; i++)
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps;
        rez = newton(3, eps);
        cout<<"x = "<<rez;
        blad = fabs(rez - x1);
        cout<<"  blad = "<<blad<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, z bladem, E-const"<<endl;
    x1 = 0;
    blad = 0;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = newton(i,eps);
        cout<<"x = "<<rez;
        blad = fabs(rez - x1);
        cout<<"  blad = "<<blad<<endl;
    }


    /// ниже должно быть свое уравнение

    return 0;
}















