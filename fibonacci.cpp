#include<iostream>
using namespace std;

class Fibonacci{
    public:
    int fibo(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return fibo(n-1)+fibo(n-2);
    }
};

int main(){
    Fibonacci f;
    int n;
    cout<<"Enter the no of elements to print ";
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<f.fibo(i)<<" ";
    }
}
