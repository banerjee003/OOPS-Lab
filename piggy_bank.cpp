#include<iostream>
using namespace std;

class AddAmount{
    public:
    int amount;
    AddAmount(){
        amount=50;
    }
    AddAmount(int a){
        amount=50+a;
    }
    void display(){
        cout<<"The net amount is "<<amount<<endl;
    }
};

int main(){
    AddAmount p1;
    AddAmount p2(100);

    p1.display();
    p2.display();
}
