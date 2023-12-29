// A circular prime is a prime number with the property that the number generated at each intermediate step when cyclically permuting its digits will be prime. For example, 1193 is a circular prime, since 1931, 9311 and 3119 are also prime.

#include<iostream>
#include<cmath>
using namespace std;


bool prime(int num);
int main()
{
    int n;
    cin >> n;
    int temp = n;

    string number = to_string(n);
    int lengthN = number.size();
    int rem = 0;
    bool flag = true;
    int i = 0;
    while(i<lengthN){
        // int sum = 0;
        cout << temp << "\n";
        if(prime(temp) != true){
            cout << n << " is not a circular prime";
            flag = false;
            break;
        }
        rem = temp%10;
        temp = rem*pow(10,lengthN-1) + temp/10;
        i++;
    }
    if(flag != false){
        cout << n << " is a circular prime";
    }
    return 0 ;
}

bool prime(int num){
    if (num>=2){
        for(int i = 2; i < num; i++){
            if(num%i == 0){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}