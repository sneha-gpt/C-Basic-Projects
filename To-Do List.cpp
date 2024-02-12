#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

class ToDoList{
    private : 
     vector<pair<string,bool>>tasks;
    public:
     
     void add_task(string new_task)
     {
         tasks.push_back(make_pair(new_task,false));
         cout << "Task added : " << new_task << endl;
     }
     
     void view_task()
     {
         cout << "--------To-Do List---------" << endl;
         if(tasks.size()==0)
         {
             cout << "List is empty!!!" << endl;
             return;
         }
         for(int i = 0;i < tasks.size();i++)
         {
             cout << i+1 << ". ";
             if(tasks[i].second==false)
              cout << "[Pending] " << tasks[i].first << endl;
             else 
              cout << "[Completed] " << tasks[i].first << endl;
         }
         cout << "----------------------------" << endl;
     }
     
     void mark_task()
     {
         int idx;
         cout << "Enter the tesk index to mark as completed : ";
         cin >> idx;
         if(idx >= 1 && idx <= tasks.size())
         {
             tasks[idx-1].second = true;
             cout << "Task marked as completed : " << tasks[idx-1].first << endl;
         }
         else 
          cout << "Invalid Task index!!" << endl;
     }
     
     void remove_task()
     {
         int idx;
         cout << "Enter the task index to remove : ";
         cin >> idx;
         
         if(idx >= 1 && idx <= tasks.size())
         {
             cout << "Task removed : " << tasks[idx-1].first << endl;
             tasks.erase(tasks.begin()+idx-1);
         }
         else 
          cout << "Invalid task index!!!" << endl;
     }
};

int main()
{
    ToDoList obj;
    int choice;
    
    do
    {
        cout << "---------To-Do List Manager----------"<<endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice (1-5) : ";
        cin >> choice;
        
        switch(choice)
        {
            case 1: {
             cin.ignore();
             cout << "Enter the task description: ";
             string task_description;
             getline(cin, task_description);
             obj.add_task(task_description);
             break;
            }
            case 2:{
             obj.view_task();
             break;
            }
            case 3:{
             obj.mark_task();
             break;
            }
            case 4:{
             obj.remove_task();
             break;
            }
            case 5:{
             cout << "Exiting the To-Do List!!!!" << endl;
             break;
            }
            default:
             cout << "Invalid choice!!! Try again....." << endl; 
        }
    }while(choice != 5);
}
