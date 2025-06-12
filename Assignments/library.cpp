#include<iostream>
#include<cstring>
using namespace std;

class Book{
    protected:
    char* title;
    char* author;
    bool isborrowed;

    public:
    Book(char *t, char *a){
        title=new char[strlen(t)+1];
        strcpy(title,t);

        author=new char[strlen(a)+1];
        strcpy(author,a);

        isborrowed=false;
    }

    virtual void borrow(){
        if(isborrowed){
            cout<<"The Book is already Borrowed\n";
        }
        else{
            isborrowed=true;
            cout<<"The Book is successfully Borrowed\n";
        }
    }

    virtual void returned(){
        if(!isborrowed){
            cout<<"The Book is not Borrowed Yet\n";
        }
        else{
            isborrowed=false;
            cout<<"The Book is successfully returned\n";
        }
    }
    
    virtual void display(){
        cout<<"Name: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
    }

    virtual ~Book(){
        delete []title;
        delete []author;
    }
};

class PrintedBook:public Book{
    int pages;
    public:
    PrintedBook(char *t,char*a,int p):Book(t,a),pages(p){};

    void display() override{
        cout<<"The Printed Book Details\n";
        Book::display();
        cout<<"Pages: "<<pages<<endl;
    }
};

class EBook:public Book{
    char* format;
    public:
    EBook(char *t,char *a,char* f):Book(t,a){
        format=new char[strlen(f)+1];
        strcpy(format,f);
    };

    void display() override{
        cout<<"The EBook Details\n";
        Book::display();
        cout<<"Format: "<<format<<endl;
    }

    void borrow() override{
        cout<<"You can not borrow EBook\n";
    }

    void returned() override{
        cout<<"It is EBook You Don't have to return\n";
    }

    ~EBook() override{
        delete []format;
    }

};

int main() {
    Book* pBook = new PrintedBook((char*)"Clean Code", (char*)"Robert C. Martin",100);
    Book* eBook = new EBook((char*)"The Pragmatic Programmer", (char*)"Andrew Hunt",(char*)"pdf");

    pBook->display();
    cout << endl;
    eBook->display();
    cout << endl;

    pBook->borrow();    
    pBook->borrow();    
    cout << endl;

    eBook->borrow();
    cout << endl;

    pBook->returned();  
    pBook->returned();  
    cout << endl;

    eBook->returned();  
    cout << endl;

    eBook->borrow();
    eBook->returned();

    delete pBook;
    delete eBook;

    return 0;
}

