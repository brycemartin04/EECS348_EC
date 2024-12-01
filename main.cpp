#include <iostream>
#include <iomanip>
#include <string>

// g++ main.cpp -o main

using namespace std;

double extractNumeric(const string& str);  //defines the extractNumeric function

int main(){     
    string input;    //initializes a string called input

    while(true){    //keep asking until user presses end
        cout<< "Enter a string (or 'END' to quit): ";
        cin >> input;                 //ask user for input

        if (input == "END"){
            break;      // if it is end, break out of the loop
        }

        double number = extractNumeric(input);        //call the function to turn the string into a double

        if (number != -999999.99){   // if it is valid 
            cout << "The input is: " << fixed << setprecision(4) << number << endl;     //give the user the number
        }else {
            cout << "The input is invalid" << endl;    //otherwise tell them it is invalid
        }
    }
    return 0;
}

double extractNumeric(const string& str){
    int num;  //initializes a number to be used as a placeholder
    double final;   //initializes the final double we will return to the user
    bool negative = false;     //initially there are no negatives
    bool decimal = false;     //initially there are no decimals
    double curDecimal = .1;    //initalizes the current decimal place
    for (int i = 0; i < str.length(); i++ ){       // for each digit in the string
        num = str[i] - 48;    //converts that digit into an int using ASCII conversion
        if (num == -3){     //if a negative sign is seen
            if (i==0) {    
                negative = true;      // if it is at the very start, flip the negative flag to true
            }else return -999999.99;    //if its not at the start, it is invalid
        }else if (num == -5){     // if a plus sign is detected
           if (i==0) {
            }else return -999999.99;    // if its not at the start, return invalid
        }else if (num == -2){    //if a decimal point is seen,
            if (decimal){   
                return -999999.99; // if there is already a decimal, it is invalid
            }else{
                decimal = true;   //otherwise flip the decimal flag to true
            }
        }else if (num < 10){   // if it is a valid integer
            if (decimal){   //if a decimal has been seen
                final += num * curDecimal;     //add the number to the final and move based on the current decimal place
                curDecimal /= 10;    //move the decimal place over
            }else{
            final *= 10;  //move the decimal over to make room for a new number
            final += num;   // add the temp number to the final running total
            }
        }else{
             return -999999.99;   // if it is not one of these valid values, return invalid
        }
        
    }
    if (negative) final *= -1;    // if the negative flag is true, multiply by -1

    return final;    //return the final number
}