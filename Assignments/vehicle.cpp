#include<iostream>
using namespace std;

class Engine{
    string type;
    int horsepower;

    public:
    Engine(string t, int hp) : type(t),horsepower(hp){}

    void display(){
        cout<<"Engine: "<<type<<endl<<"Horsepower: "<<horsepower<<endl;
    }
};

class Vehicle{
    protected:
    string make;
    string model;
    bool isRented;
    Engine engine;

    public:
    Vehicle(string mk, string md, Engine eng) : make(mk),model(md),engine(eng),isRented(false){};
    
    virtual void rentVehicle(){
        if(isRented){
            cout<<"Already Rented "<<endl;
        }
        else{
            isRented=true;
            cout<<"Successfully Rented"<<endl;
        }
    }

    virtual void returnVehicle(){
        if(!isRented){
            cout<<"Was not Rented"<<endl;
        }
        else{
            isRented=false;
            cout<<"Successfully Returned"<<endl;
        }
    }

    virtual void display(){
        cout<<make<<" made "<<model<<endl;
        engine.display();
    }
};

class Car : public Vehicle{
    int doors;
    public:
    Car(string mk, string md, int d, Engine eng):Vehicle(mk,md,eng),doors(d){};

    void display() override{
        Vehicle::display();
        cout<<"Doors "<<doors<<endl;
    }
};

class Bike : public Vehicle{
    int capacity;
    public:
    Bike(string mk, string md, int c, Engine eng):Vehicle(mk,md,eng),capacity(c){};

    void display() override{
        Vehicle::display();
        cout<<"Capacity: "<<capacity<<endl;
    }
};

int main(){
    Engine carEngine("V8",577);
    Engine bikeEngine("DOHC",190);

    Car car1("Mercedes","G Wagon",5,carEngine);
    Bike bike1("Suzuki","Hayabusa",2,bikeEngine);

    car1.display();
    car1.rentVehicle();

    bike1.display();
    bike1.rentVehicle();

    car1.rentVehicle();
    car1.returnVehicle();
    car1.returnVehicle();
}

