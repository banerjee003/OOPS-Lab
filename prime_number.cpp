#include<iostream>
#include<cmath>
using namespace std;

class Prime{
    public:
    int n;
    bool isprime(int x){
        if(x==1) {
            cout<<"1 is neither prime nor composite\n";
            return false;
        }
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Prime p;
    cout<<"Enter the number ";
    cin>>p.n;
    if(p.isprime(p.n)){
        cout<<p.n<<" is a prime number";
    }
    else
        cout<<p.n<<" is not a prime number";
}
