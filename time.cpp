#include<iostream>
using namespace std;

struct Time{
    int hr;
    int min;
    int sec;
};

void time_conversion(Time t){
    cout<<"The whole time in second is "<<(t.hr*3600+t.min*60+t.sec);
}

int main(){
    struct Time t;
    cout<<"Enter hour, minute and second ";
    cin>>t.hr>>t.min>>t.sec;
    time_conversion(t);
}
