#include<iostream>
#include<cstring>
using namespace std;

class Book{
    char *title;
    char *author;
    char *publisher;
    int price;
    int stock;

    public:
    Book(char *t, char*a, char*p, int pr, int s){
        title=new char[strlen(t)+1];
        strcpy(title,t);

        author=new char[strlen(a)+1];
        strcpy(author,a);

        publisher=new char[strlen(p)+1];
        strcpy(publisher,p);

        price=pr;

        stock=s;
    }

    ~Book(){
        delete[] title;
        delete[] author;
        delete[] publisher;
    }

    void display(){
        cout<<"The book is Found \n";
        cout<<"Name: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Price: Rs "<<price<<endl;
    }

    void search( char *t,  char *a, int s){
        if(strcmp(t,title)==0 && strcmp(a,author)==0){
            display();
        
            if(s<=stock){
                cout<<"Stock Available\n";
                cout<<"Total cost: Rs "<<s*price<<endl;
            }
            else{
                cout<<"Required stock not available\n";
            }
        }
        else{
            cout<<"Book Not Found\n";
        }
    }
};

int main() {
    
    char title[50], author[50], publisher[50];
    int price, stock;

    cout << "Enter the book title: ";
    cin.getline(title, 50);

    cout << "Enter author name: ";
    cin.getline(author, 50);

    cout << "Enter publisher name: ";
    cin.getline(publisher, 50);

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter stock: ";
    cin >> stock;
    cin.ignore(); 

    Book b1(title, author, publisher, price, stock);

    char searchTitle[50], searchAuthor[50];
    int copies;

    cout << "Enter book title to search: ";
    cin.getline(searchTitle, 50);

    cout << "Enter author name: ";
    cin.getline(searchAuthor, 50);

    cout << "Enter number of copies needed: ";
    cin >> copies;

    b1.search(searchTitle, searchAuthor, copies);

    return 0;
}
