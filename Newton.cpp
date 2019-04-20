#include<bits/stdc++.h>
using namespace std;

double temp[20];

//Horner's Method
double func(int degree,double ara[],double x){
    double p[degree+1];
    p[0]=ara[0];
    for(int i=1;i<=degree;i++){
        p[i]=p[i-1]*x+ara[i];
    }
    return p[degree];

}
double derivative(int degree,double ara[],double x){
    double p[degree+1];
    p[0]=ara[0]*degree;
    for(int i=1;i<=degree;i++){
        p[i]=p[i-1]*x+ara[i]*(degree-i);
    }
    return p[degree-1];

}
double deflate(int degree,double ara[],double x){
    temp[0]=0;
    for(int i=1;i<=degree;i++){
        temp[i]=ara[i-1]+temp[i-1]*x;
        cout<<temp[i]<<endl;
    }
    for(int i=0;i<=degree;i++){
        ara[i]=temp[i+1];
    }
}

int main()
{
    int degree;
    cin>>degree;
    double ara[degree+1];
    for(int i=0;i<=degree;i++){
        cin>>ara[i];
    }
    double x0=2;
    double fx,fdx;
    int d=degree;
    double x1;
    while(d>1){
        while(1){
            fx=func(d,ara,x0);
            fdx=derivative(d,ara,x0);

            if(fx==0.0){
                x1=x0;
                break;
            }
            x1=x0-(fx/fdx);
            if(fabs((x1-x0)/x1)>.001)
                break;
            x0=x1;
        }
        cout<<"Root: "<<x1<<endl;
        deflate(d,ara,x1);
        d--;
    }
    cout<<"Root: "<<-ara[d]/ara[d-1]<<endl;

}
