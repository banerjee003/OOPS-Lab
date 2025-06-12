#include<iostream>
using namespace std;

class Scorecard{
    public:
    string name;
    int matches;
    int runs;
    float average;

    Scorecard(){
        name="";
        matches=0;
        runs=0;
        average=0.0;
    }

    Scorecard(string name,int matches,int runs){
        this->name=name;
        this->matches=matches;
        this->runs=runs;
        average=float(runs)/matches;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Matches: "<<matches<<endl;
        cout<<"Runs: "<<runs<<endl;
        cout<<"Average: "<<average<<endl;
    }
    static void find_max_matches(Scorecard player[],int n){
        int maximum_matches=0;
        string player_name;
        for(int i=0;i<n;i++){
            if(player[i].matches>maximum_matches){ 
                maximum_matches=player[i].matches;
                player_name=player[i].name;
            }
        }
        cout<<"Player with the most number of matches is "<<player_name<<" "<<maximum_matches<<endl;
    }

    static void find_max_runs(Scorecard player[],int n){
        int maximum_runs=0;
        string player_name;
        for(int i=0;i<n;i++){
            if(player[i].runs>maximum_runs){ 
                maximum_runs=player[i].runs;
                player_name=player[i].name;
            }
        }
        cout<<"Player with the most runs is "<<player_name<<" "<<maximum_runs<<endl;
    }
    static void find_max_average(Scorecard player[],int n){
        float maximum_average=0.0;
        string player_name;
        for(int i=0;i<n;i++){
            if(player[i].average>maximum_average){ 
                maximum_average=player[i].average;
                player_name=player[i].name;
            }
        }
        cout<<"Player with the highest average is "<<player_name<<" "<<maximum_average<<endl;
    }
};


int main(){
    int n;
    cout<<"Enter the no of players ";
    cin>>n;
    Scorecard player[n];
    string name;
    int matches,runs;
    for(int i=0;i<n;i++){
        cout<<"Enter the name, matches and runs of the player "<<i+1<<endl;
        cin>>name>>matches>>runs;
        player[i]=Scorecard(name,matches,runs);
    }
    cout<<"Player Details"<<endl;
    cout<<"----------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Player "<<i+1<<endl;
        player[i].display();
        cout<<"----------------------"<<endl;
    }
    
    cout<<endl;
    Scorecard::find_max_matches(player,n);
    Scorecard::find_max_runs(player,n);
    Scorecard::find_max_average(player,n);
}


