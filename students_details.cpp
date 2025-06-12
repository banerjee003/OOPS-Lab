#include<iostream>
using namespace std;

class Student{
    private:
    long long id;
    int marks;
    public:
    string name;
    Student(string name,long long id,int marks){
        this->name=name;
        this->id=id;
        this->marks=marks;
    }
    void display(){
        cout<<"Students Details"<<endl<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Marks: "<<marks<<endl;
    }

};

int main(){
    Student s("pallab",231001001273,69);
    s.display();
}
