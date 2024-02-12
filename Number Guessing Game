#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "       Welcome to Guess Number Game!!!      " << endl;
  cout << " You have to guess a number between 1 and 100  " << endl;
  srand(time(0));
  int number = (rand()%100)+1;
  
  int user_guess,attempt = 0;
  
  do{
    cout << "Enter the guess : ";
    cin >> user_guess;
    
    attempt++;
    if(user_guess == number)
     cout << "Congratulations!! You guessed the correct number." << endl;
    else if(user_guess > number)
     cout << "Too high!! Try again" << endl;
    else 
     cout << "Too low!! Try again" << endl;
  }while(user_guess != number);
  
}
