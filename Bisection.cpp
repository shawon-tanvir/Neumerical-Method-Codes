#include<bits/stdc++.h>
using namespace std;

double func(int degree,double ara[],double x){
    double p[degree+1];
    p[0]=ara[0];
    for(int i=1;i<=degree;i++){
        p[i]=p[i-1]*x+ara[i];
    }
    return p[degree];
}
double derivative(int degree,double ara[],double x)
{
    double p[degree+1];
    p[0]=ara[0]*degree;
    for(int i=1;i<=degree;i++){
        p[i]=p[i-1]*x+ara[i]*(degree-i);
    }
    return p[degree-1];
}
void bisection(int degree,double x1,double x2,double ara[]){
    double f1,f2,f0,x0;
    f1=func(degree,ara,x1);
    f2=func(degree,ara,x2);
    //cout<<f1<<" "<<f2<<endl;
    if(f1*f2>0)
        return;
    do{
        x0=(x1+x2)/2;
        f0=func(degree,ara,x0);
        if(f1*f0<0){
            x2=x0;
            //f2=f0;
        }
        else{
            x1=x0;
            //f1=f0;
        }
        cout<<x0<<" "<<x2<<endl;
    }while(fabs((x2-x1)/x2)>.001);
    cout<<"Root: "<<(x1+x2)/2<<endl;
}
int main()
{
    int degree;
    double a,b;
    cout<<"degree: ";
    cin>>degree;
    double ara[degree+1];
    cout<<"Co-efficient: ";
    for(int i=0;i<=degree;i++){
        cin>>ara[i];
    }
    cout<<func(degree,ara,1.2);
    cout<<"a b :";
    cin>>a>>b;
    double dx;
    cout<<"dx: ";
    cin>>dx;
   // double x1=a,x2=a+dx;
    do{
        bisection(degree,a,a+dx,ara);
        a+=dx;
    }while(a<b);

}
