#include<iostream>
using namespace std;

struct Member
{
    string name;
    int id;
    int ph_no;

    void display(){
        cout<<name<<endl<<id<<endl<<ph_no<<endl;
    }
};

void get_data(int n,struct Member &m){
    
    cout<<"Enter the name of the member ";
    cin>>m.name;
    cout<<"Enter the id of the member ";
    cin>>m.id;
    cout<<"Enter the ph no of the member ";
    cin>>m.ph_no;
}


int main(){
    int n;
    cout<<"Enter the no of members ";
    cin>>n;
    struct Member m[n];
    for(int i=0;i<n;i++){
        get_data(n,m[i]);
    }

    cout << "\nMember Details:\n";
    for (int i = 0; i < n; i++) {
        m[i].display();
        cout << "-------------------\n";
    }
}
