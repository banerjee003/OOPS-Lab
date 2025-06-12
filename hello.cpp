#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
    float x;
    float result;
    while(true){
        cout<<"Enter the no ";
        cin>>x;
        result=(3*pow(x,4)+9)/(4*pow(x,3)-1);
        cout<<result<<endl;
    }
}
