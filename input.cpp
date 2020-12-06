#include <iostream>
using namespace std;
// create enumeration in C++
enum EyeColor {
    Brown, Blue, Green, Gray, Other
};

int main() {
    // to print to the console, use cout.
    // std is a namespace. Standard to include to use the cout command. Unless declared on top
    // cout<<"Enter your name" << endl;
    
    // a variable in C++ is just a container that takes memory and that container can hold a data of a certain type
    // types: integer, floating point number, character, boolean, string, array
    // Similar to Javscript, if variable is declared using const, you will not be able to reassign.

    // DATA TYPES
    // int age = 25;
    // age = 26;

    // stores decimal
    // float weight = 65.5;
    // double can store double the data. can hold larger number or show with more decimals
    // double balance = 12345.67;
    // char can hold one char. to assign a vlaue to char, use single quotes
    // char gender = 'm';
    // string hold regular string. more than 1 charatcert. double quotes
    // string username = "Code";
    // smallest data type in C++ in booleans
    // bool isSunnyToday = false;

    // array. collection of vars of a certain type. Array takes contionous space in memory. When declaring an array, have to specify its size upfront
    // in C++, cannot have an array that stores a char, integer, string. Specify the type of array upfront
    // if you initialize the array with vals, you can omit declaring the array size
    // string colors[10] = {"red", "green", "blue", "pink", "black"};

    //print out specidic index in array
    // cout << colors[1];
    //to reassign value at specific position
    // cin>>colors[1]; // takes input from user with cin
    // cout << colors[1];

    //once you reach the max limit in thtat set array, you have to recreate array, reinitialize so it can take that continous space of memory somewhere else

    // CONDITIONS SELECTION
    // executing one part of the code rather than another one depending on a certain condtion

    bool isTodaySunny = false;
    bool isTodayWeekend = false;

    // multiple conditions
    // if(isTodaySunny && isTodayWeekend){
    //     cout << "Go to Park" << endl;
    // }
    // else if(isTodayWeekend && !isTodaySunny){
    //     cout << "Go to Park but take umbrella" << endl;
    // }
    // else{
    //     cout << "Go to work" << endl;
    // }
    // nested conditions
    // if(isTodayWeekend){
    //     if(isTodaySunny){
    //         cout << "Go to Park" << endl;
    //     }else{
    //         cout << "Go to Park but take umbrella" << endl;
    //     }
    // }else{
    //     cout << "Go to work" << endl;
    // }
    // switch case
    EyeColor eyeColor = Brown;
    switch(eyeColor){
        case Brown: cout << "80 % of people have Brown eyes" << endl; break; // break once match is found
        case Blue: cout << "10 % of people have Blue eyes" << endl; break;
        case Green: cout << "2 % of people have Green eyes" << endl; break;
        case Gray: cout << "1 % of people have Gray eyes" << endl; break;
        case Other: cout << "7 % of people have Other eyes" << endl; break;
        default: cout << "Not valid eye color" << endl;
    }
    // ternary operator
    // isTodaySunny ? cout << "Go to Park" << endl : cout << "Take an umbrella" << endl; 
    return 0;
    // system("pause>0");
}