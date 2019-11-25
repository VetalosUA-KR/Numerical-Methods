#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


double fun (double x)
{
    double c = 3.57;
    double d = 7.72;

    return (x-c)*((x+d)*(x+d)*(x+d));
}

double funPrim(double x)
{
    double c = 3.57;
    double d = 7.72;
    return (d + x) * (d + x) * (-3 * c + d + 4 * x);
}


int main()
{

    double  x;
    double E = 0.00000001;
    cout<<"podaj x -> ";cin>>x;
    double h;

    int counter = 0;
    do
    {
        counter++;
        h = -(fun(x)/funPrim(x));
        x += h;
    }
    while(fabs(h) > E);

    cout<<"x = "<<setprecision(16)<<x<<endl;
    cout<<"counter = "<<counter<<endl;

    return 0;
}
