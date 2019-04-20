#include<bits/stdc++.h>
#include<math.h>
#define E .001
using namespace std;

//Horner's Method
double func(int degree,double x,int ara[]){
    double p[degree+1];
    p[0]=ara[0];
    for(int i=1;i<degree+1;i++){
        p[i]=x*p[i-1]+ara[i];
    }
    return p[degree];
}

int main()
{
    int degree;
    cin>>degree;
    int a[degree+1];
    for(int i=0;i<degree+1;i++){
        cout<<"Enter the value of a"<<degree-i<<" = ";
        cin>>a[i];
    }
    double x1,x2,f1,f2;
    double x3;
    x1=4,x2=2;
    f1=func(degree,x1,a);
    f2=func(degree,x2,a);
    x3=(f2*x1-f1*x2)/(f2-f1);

    while(abs((x3-x2)/x3)>E){
        cout<<x1<<" "<<x2<<" "<<x3<<endl;
        x1=x2;
        x2=x3;
        f1=func(degree,x1,a);
        f2=func(degree,x2,a);
        x3=(f2*x1-f1*x2)/(f2-f1);
       // x3=(((func(degree,x2,a)*x1)-(func(degree,x1,a)*x2)) /(func(degree,x2,a)-func(degree,x1,a)));
    }
    printf("root %.3lf",x3);
}
