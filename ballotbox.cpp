#include<iostream>
using namespace std;

class BallotBox{
    int count[5];
    int spoil;
    public:
    BallotBox(){
        for(int i=0;i<5;i++){
            count[i]=0;
        }
        spoil=0;
    }
    void votecount(int vote){
        if(vote>=1 and vote<=5){
            count[vote-1]++;
        }
        else spoil++;
    }
    void display(){
        cout<<"Vote Count"<<endl;
        for(int i=0;i<5;i++){
            cout<<"Vote for candidate "<<i+1<<" is "<<count[i]<<endl;
        }
        cout<<"The amount of spoiled vote is "<<spoil<<endl;
    }

};

int main(){
    int vote_num;
    cout<<"Enter the total no of votes ";
    cin>>vote_num;
    BallotBox box;

    for(int i=0;i<vote_num;i++){
        int vote;
        cout<<"Enter Your Vote ";
        cin>>vote;
        box.votecount(vote);
    }
    box.display();
}

