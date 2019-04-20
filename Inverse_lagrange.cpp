#include<bits/stdc++.h>

using namespace std;

int main(){

    double x[100],y[100],s,t,result=0;
    int n;
    double a;
    cout <<"Enter the number of the terms of the table :"<<endl;
    cin>>n;
    cout<<"\nEnter the respective values of the variables x and y :"<<endl;

    for(int i=0; i<n; i++){
        cin>>x[i];

    }
     for(int i=0; i<n; i++){

        cin>>y[i];
    }

    cout<<"\nThe created table is as follows :"<<endl;
    for(int i=0; i<n; i++){
        printf("%0.3f\t%0.3f",x[i],y[i]);
        printf("\n");
    }

    cout<<"\n Enter the value of the y to find the respective value of x\n"<<endl;
    cin>>a;
    for(int i=1; i<=n; i++){
        s=1;
        t=1;
        for(int j=1; j<=n; j++){
            if(j!=i){
                s=s*(a-y[j]);
                t=t*(y[i]-y[j]);
            }
        }
        result=result+((s/t)*x[i]);
    }
    printf("\nThe respective value of the variable x is : %lf",result);

    return 0;

}

