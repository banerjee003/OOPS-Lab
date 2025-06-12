#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Book{
    char *title;
    char *author;
    char *publisher;
    int price;
    int stock;

    public:
    Book(){
        title = author = publisher = nullptr;
        price = 0;
        stock = 0;
    }

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

    bool find(char *t,  char *a){
        if(strcmp(t,title)==0 && strcmp(a,author)==0){
            display();
            return true;
        }
        return false;
    }

    void availability(int s){
        if(s<=stock){
            cout<<"Stock Available\n";
            cout<<"Total cost: Rs "<<s*price<<endl;
        }
        else{
            cout<<"Required Copies Not in Stock\n";
        }
    }
};

int main() {
    int n;
    cout<<"Enter the no of books ";
    cin>>n;
    cin.ignore();

    vector<Book*>b;

    for(int i=0;i<n;i++){
        cout<<"Enter the Details of Book no "<<i+1<<endl;
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

        Book* mybook=new Book(title,author,publisher,price,stock);
        b.push_back(mybook);        
    }

    char searchTitle[50], searchAuthor[50];
    int copies;

    cout << "Enter book title to search: ";
    cin.getline(searchTitle, 50);

    cout << "Enter author name: ";
    cin.getline(searchAuthor, 50);


    bool found=false;
    for(int i=0;i<n;i++){
        if(b[i]->find(searchTitle,searchAuthor)){
            found=true;
            cout << "Enter number of copies needed: ";
            cin >> copies;
            b[i]->availability(copies);
            break;
        }
    }
    if(!found){
        cout<<"Book Not Found"<<endl;
    }
    
    for(auto book:b){
        delete book;
    }

}

