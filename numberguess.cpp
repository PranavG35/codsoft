#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    cout<<"\tNumber Guessing game!\n";
    int N=5;
    cout<<"Guess the number(between 0 to 5) :";
    int guess;
    cin>>guess;
    int num;
    srand(time(0));
    num=rand()%N;
    cout<<"The number is: "<<num<<endl;
    if(guess==num){
        cout<<"Congratulations! you guessed it right!!";
        cout<<"The number is "<<guess;
    }
    else if(guess<num){
        int a=num-guess;
        cout<<"Your guess is smaller by "<<a<<endl;
    }
    else if(guess>num){
        int a=guess-num;
        cout<<"Your guess is larger by "<<a<<endl;
    }
    return 0;
}