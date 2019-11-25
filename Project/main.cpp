#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return (pow(x, 2) + 3) * exp(x-5) - 2;
}

double funcPrim(double x)
{
    return 2*x*exp(x-5)+(x*x+3)*exp(x-5);
}

double U(double x)
{
    return func(x)/funcPrim(x);
}

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
    while(fabs(h) >= 0);
    ///cout<<"ilosc krokow = "<<k<<endl;
    return x;
}

double wielopunktowa(double x, double elipson)
{
    int k = 0;
    double h;

    do
    {
        h = x - (1/4) * ( U(x) + ( (3*func(x)) / funcPrim(x - (2/9) * (2*U(x) + (func(x) / funcPrim(x-U(x))))) ));
        x += h;
        k++;
    }
    while(fabs(h) >= elipson);
    //cout<<"ilosc krokow = "<<k<<endl;
    return k;
}

int main()
{
    double eps;
    double rez;
    cout<<"algorutm wielopunktowa, x-const"<<endl;
    for(int i = 3; i <= 18; i++)
    {
        eps = pow(10, -i);
        rez = wielopunktowa(3, eps);
        cout<<"x = "<<rez<<endl;
    }

    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0: "<<i<<endl;
        rez = wielopunktowa(i,eps);
        cout<<"x: "<<rez<<endl;

    }

    return 0;
}
