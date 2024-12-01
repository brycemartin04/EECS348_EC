#include <iostream>
#include <iomanip>
#include <string>

// g++ main.cpp -o main

using namespace std;

double extractNumeric(const string& str);

int main(){
    string input;

    while(true){
        cout<< "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END"){
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99){
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }else {
            cout << "The input is invalid" << endl;
        }
    }
    return 0;
}

double extractNumeric(const string& str){
    int num;
    double final;
    bool negative = false;
    bool decimal = false;
    double curDecimal = .1;
    for (int i = 0; i < str.length(); i++ ){
        num = str[i] - 48;
        if (num == -3){
            if (i==0) {
                negative = true;
            }else return -999999.99;
        }else if (num == -5){
           if (i==0) {
            }else return -999999.99; 
        }else if (num == -2){
            if (decimal){
                return -999999.99;
            }else{
                decimal = true;
            }
        }
        else if (num < 10){
            if (decimal){
                final += num * curDecimal;
                curDecimal /= 10;
            }else{
            final *= 10;
            final += num;
            }
        }else{
             return -999999.99;
        }
        
    }
    if (negative) final *= -1;

    return final;
}