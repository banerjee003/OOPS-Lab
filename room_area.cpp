#include<iostream>
using namespace std;

struct Distance{
    int feet;
    int inches;
};

struct Room{
    Distance length;
    Distance width;
};

void area_calculation(Room r){

    float total_length, total_width;
    total_length=r.length.feet+(r.length.inches/12.0);
    total_width=r.width.feet+(r.width.inches/12.0);

    float area=total_length*total_width;
    cout<<"The total area is "<<area<<" sq.feet";
};

int main(){
    struct Room dining_room;

    cout<<"Enter the length of the room in feet and inches respectively ";
    cin>>dining_room.length.feet>>dining_room.length.inches;
    
    cout<<"Enter the width of the room in feet and inches respectively ";
    cin>>dining_room.width.feet>>dining_room.width.inches;

    area_calculation(dining_room);

}
