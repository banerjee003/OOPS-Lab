#include<iostream>
using namespace std;

class Student{
    private:
    long long id;
    int marks;
    public:
    string name;
    Student(string name){
        this->name=name;
        id=201001001000;
        marks=0;
    }
    void set_id(int i){
        id=20100100100000+i;
    }
    void set_marks(int m){
        marks=m;
    }

    void display(){
        cout<<endl<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Marks: "<<marks<<endl;
    }

};

int main(){
    string n1,n2;
    int m1,m2;
    long long i1,i2;
    cout<<"Enter the name of Student 1 and 2 ";
    cin>>n1>>n2;
    cout<<"Enter the last two digit of ID of Student 1 and 2 ";
    cin>>i1>>i2;
    cout<<"Enter the Marks of Student 1 and 2 ";
    cin>>m1>>m2;

    Student s1(n1);
    Student s2(n2);

    s1.set_id(i1);
    s2.set_id(i2);

    s1.set_marks(m1);
    s2.set_marks(m2);

    cout<<endl<<"Student Details:"<<endl;
    s1.display();
    s2.display();

}
