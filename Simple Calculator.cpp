#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num1,num2;
    cout << "Enter number 1 : ";
    cin >> num1;
    
    cout << "Enter number 2 : ";
    cin >> num2;
    
    cout << "Choose an operation('+','-','*','/') : ";
    char operation;
    cin >> operation;
    
    switch(operation){
        case '+':
         cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
         break;
        case '-':
         cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
         break;
        case '*' :
         cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
         break;
        case '/':
         if(num2!=0)
          cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
         else 
          cout << "Error!!! Division by zero not possible." << endl;
         break;
         default :
          cout << "Invalid Operation!!!" << endl;
    }
}
