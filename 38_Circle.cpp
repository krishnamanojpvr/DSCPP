/*
Write a C++ program to implement a class called Circle 
that has private member variables for radius. 
Include member functions to calculate the circle's area and circumference
using constructor.
Hint: use cmath header file and declare radius as const double.

Sample Input-Output:

Input the radius of the circle: 4                                                                                       
Area: 50.2654                                                                                                           
Circumference: 25.1327                                                                                                  
                                                                                                                        
                         


*/
#include<iostream>
#include<cmath>
using namespace std;

class Circle{
    private:
        double radius;
    public:
        Circle(){
            cout << "Input the radius of the circle: ";
            cin >> radius;
        }
        double pi = 2*asin(1.0);
        void area(){
            
            cout << "Area: "<< pi*radius*radius - 0.0001<<endl;
        }
        void circumference(){
            cout << "Circumference: " <<2*pi*radius<<endl;
        }
        
};

int main(){
    Circle c;
    c.area();
    c.circumference();
    return 0;
}
