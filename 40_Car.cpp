/*
Write a C++ program to create a class called Car that has private member variables
for company, model, and year.
Implement member functions to get and set these variables
using constructors and setters and getters.

Sample Output:
Company: AUDI
Model: A6
Year: 2023

Updated Company: BMW
Updated Model: M4
Updated Year: 2022



*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string Company;
    string Model;
    int year;

public:
    Car(string company, string model, int nYear)
    {
        Company = company;
        Model = model;
        year = nYear;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << nYear << endl;
    }
    void displayNew(string company, string model, int nYear)
    {
        cout << "Updated Company: " << company << endl;
        cout << "Updated Model: " << model << endl;
        cout << "Updated Year: " << nYear << endl;
    }
};

int main()
{
    Car Car("AUDI", "A6", 2023);
    Car.displayNew("BMW", "M4", 2022);
    return 0;
}