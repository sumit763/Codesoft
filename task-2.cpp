#include <iostream>
using namespace std;
int a ,b,res,choice;  // define all variable globally

void input(int *a , int *b){
  cout<<"Enter the first number(a)"<<endl;
  cin>>*a;
  cout<<"Enter the second number(b)"<<endl;
  cin>>*b;
}

int main()
{ 
    cout<<"\n--******A basic CALCULATOR using c++--*****"<<endl<<endl;
     
     input(&a,&b);  // function call to take input 2 numbers
do
{ cout<<""<<endl;  
    cout<<"1.Additon"<<endl;
    cout<<"2.Subtraction"<<endl;
    cout<<"3.Division"<<endl;
    cout<<"4.Multiplication"<<endl;
    cout<<"5.exit the program"<<endl;

    cout<<"enter your choice"<<endl;
    cin>>choice;                 // taking choice 

    switch(choice){
        case 1: cout<<"****--ADDITION--***"<<endl;
                res = a+b;
                cout<<"a + b = "<<res;
                break;
        case 2: cout<<"****--SUBTRACTION--***"<<endl;
                res = a-b;
                cout<<"a - b = "<<res;
                break;
        case 3: cout<<"****--DIVISION--***"<<endl;
                res = a/b;
                cout<<"a / b = "<<res;
                break;
        case 4: cout<<"****--MULTIPLICATION--***"<<endl;
                res = a*b;
                cout<<"a * b = "<<res;
                break;
        case 5: exit(0);
                break;
    default : cout<<"invalid choice";
                
    }
} while (choice!=5);   // loop terminate if enter the choice = 5
 
    return 0;
}