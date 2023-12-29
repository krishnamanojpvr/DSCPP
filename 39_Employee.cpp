/*
Write a C++ program to implement a class called Employee that has 
private member variables for name, employee ID, and salary. 
Include member functions to calculate and set salary based on employee performance
using  constructors.
Hint:salary *= performanceRating;

Sample Input-Output:

Input employee name: laxmi                                                                                              
Input employee ID: 543                                                                                                  
Input employee salary: 56000                                                                                            
Initial salary: 56000                                                                                                   
Input performance rating (0.0-1.4): 1.4                                                                                 
Updated salary: 78400                                                                                                   
                                                                                                                        
                                                                                                                                
                        
*/

#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        int employeeId;
        int salary;
    public:
        Employee(){
            cout << "Input employee name: ";
            cin >> name;
            cout << "Input employee ID: ";
            cin >> employeeId;
            cout << "Input employee salary: ";
            cin >> salary;
            cout << "Initial salary: " << salary<<endl;
        }
        void performance(){
            float perfRating;
            cout <<"Input performance rating(0.0-1.4): ";
            cin >> perfRating;
            cout << "Updated salary: "<< salary*perfRating;
        }
  
};

int main(){
    Employee e;
    e.performance();
    return 0;
}
