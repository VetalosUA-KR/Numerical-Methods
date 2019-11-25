#include <iostream>
#include <iomanip>

using namespace std;

double fun (double x)
{
    double c = 3.57;
    double d = 7.72;

    return (x-c)*((x+d)*(x+d)*(x+d));
}

int main()
{
    setprecision(3);
    double a,b;
    cout<<"podaj a -> ";cin>>a;
    cout<<"podaj b -> ";cin>>b;
    const double epsilon = 0.0000000001;
    double x;

    int kounter = 0;
    do
    {
        x = (a+b)/2.0;
        if((fun(a) * fun(x)) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
        //cout<<"a = "<<a;
        //cout<<"    b = "<<b<<endl;
        kounter++;
    }
    while((b-a) > epsilon);

    double rez = (a+b)/2;
    cout<<"rez = "<<rez<<endl;
    cout<<"ilosc  = "<<kounter<<endl;
    return 0;
}
