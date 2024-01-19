#include<iostream>
using namespace std;
void add(int a,int b){
    int c=a+b;
    cout<<"Addition: "<<c<<endl;
}
void subtract(int a,int b){
    int c=a-b;
    cout<<"Subtraction: "<<c<<endl;
}
void multiply(int a,int b){
    int c=a*b;
    cout<<"Multiplication: "<<c<<endl;
}
void divide(int a,int b){
    int c=a/b;
    cout<<"Division: "<<c<<endl;
}

int main(){
    cout<<"Select following for operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter your choice: ";
    int choice;
    cin>>choice;
    int x,y;
    cout<<"Enter numbers(separated by space)";
    cin>>x;
    cin>>y;
    switch (choice)
    {
    case 1:
        add(x,y);
        break;
    case 2:
        subtract(x,y);
        break;
    case 3:
        multiply(x,y);
        break;
    case 4:
        divide(x,y);
        break;
    default:
        cout<<"Wrong choice";
        break;
    }
}