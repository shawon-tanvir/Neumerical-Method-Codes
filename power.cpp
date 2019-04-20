#include<iostream>
#include<math.h>
#define size 20
using namespace std;
int main()
{
    double x[size],y[size],sumX=0,sumXX=0,sumY=0,sumXY=0;
    float a,b;
    int n;
    cout<<"linear regression\n";
    cout<<"Enter the data points: ";
    cin>>n;
    cout<<"Enter the value of x: ";
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
    }
    cout<<"Enter the value of y: ";
    for(int i=0; i<n; i++)
    {
        cin>>y[i];
    }
    for(int i =0; i<n; i++)
    {
        sumX=sumX+log(x[i]);
        sumXX =sumXX+log(x[i])*log(x[i]);
        sumY=sumY+log(y[i]);
        sumXY =sumXY+log(x[i])*log(y[i]);

    }
    b= ((sumXY*n)-(sumX*sumY))/((n*sumXX)-(sumX*sumX));
    a= (sumY-b*sumX)/n;
    cout<<a<<endl;
    a=exp(a);
    cout<<"Linear regression line :Y =A+BX"<<endl;
    cout<<"The coefficients are:"<<a<<"\t"<<b;

    return 0 ;
}

