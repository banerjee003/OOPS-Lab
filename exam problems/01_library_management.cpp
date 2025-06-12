#include<iostream>
#include<vector>
using namespace std;

class Book{
    public:
    int id;
    string title;
    bool isIssued;

    Book(int id, string title){
        this->id=id;
        this->title=title;
        this->isIssued=false;
    }

    void display(){
        cout<<"Name "<<title<<endl;
    }
};

class Member{
    public:
    int id;
    string name;

    public:
    Member(int id, string name){
        this->id=id;
        this->name=name;
    }

    virtual int calculateFine(int days)=0;
    virtual void getType()=0;

    virtual ~Member(){}
};

class Student:public Member{
    public:
    Student(int id, string name):Member(id,name){}

    int calculateFine(int days) override{
        if(days<=7){
            return 0;
        }
        else{
            return (days-7)*2;
        }
    }
    void getType() override {
        cout << "Student Member: " << name << endl;
    }
};

class Faculty:public Member{
    public:
    Faculty(int id, string name):Member(id,name){}

    int calculateFine(int days) override{
        if(days<=14){
            return 0;
        }
        else{
            return (days-14)*1;
        }
    }
    void getType() override {
        cout << "Faculty Member: " << name << endl;
    }
};

class Library{
    public:
    vector<Book>book;
    vector<Member*>members;

    void addBook(int id, string title){
        book.push_back(Book(id,title));
    }
    void addMembers(Member* m){
        members.push_back(m);
    }

    void issueBook(int BookId, int memberId){
        for(auto&b: book){
            if(b.id==BookId && !b.isIssued){
                b.isIssued=true;
                cout<<b.title<<" Book Issued Successfully for the member with id "<<memberId<<endl;
                return;
            }
        }
        cout<<"Book Not Available\n";
        return;
    }

    void returnBook(int BookId, int memberId, int days) {
        for (auto& b : book) {
            if (b.id == BookId && b.isIssued) {
                b.isIssued = false;
                cout << b.title << " Book returned successfully by member ID " << memberId << endl;

                for (auto& m : members) {
                    if (m->id == memberId) {
                        int fine = m->calculateFine(days);
                        cout << "Fine to be paid: Rs" << fine << endl;
                        return;
                    }
                }

                cout << "Member not found\n";
                return;
            }
        }
        cout << "Book ID not found or wasn't issued\n";
    }

    ~Library(){
        for(auto&m:members){
            delete m;
        }
    }
};

int main() {
    Library lib;

    lib.addBook(1, "Data Structures");
    lib.addBook(2, "C++ Programming");

    lib.addMembers(new Student(101, "Alice"));
    lib.addMembers(new Faculty(201, "Dr. Bob"));

    lib.issueBook(1, 101);             
    lib.returnBook(1, 101, 10);         

    lib.issueBook(2, 201);           
    lib.returnBook(2, 201, 16);         

    return 0;
}
