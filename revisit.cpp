#include<iostream>
using namespace std;

class Reverse{
    public:
    string str;
    void revisit(string s,int length){
        for(int i=0;i<=length/2;i++){
            swap(str[i],str[length-i]);
        }
        cout<<"The revisited version is "<<str<<endl;
    }
};

int main(){
    Reverse r;
    cout<<"Enter the string ";
    getline(cin,r.str);
    int n=r.str.length()-1;
    r.revisit(r.str,n);
}
