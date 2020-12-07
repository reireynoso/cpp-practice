# C++ Crash Course 

# C++ Background
- Created back in 1980s and it was created with two other programming languages: Simula was 1 of the two. It was slow but easy to understand.
- So it was combined with C and took the best of both worlds to form C++.
- C++ is general purpose language, not specialized for one domain but it can be used to solve a wide variety of problems 
- Examples: build browsers with C++, games, other programming languages, OS. Heavy on the CPU. C++ is so much closer to the hardware that allows it to manage CPU and memory resources efficiently.
- C++ is a `compiled language`, code that you write first has to be converted in a code that your machine can understand. This is what `compiler` is used for. 
- It is a `case sensitive language` means that it will matter if you use upper or lower case
- C++ is `statically typed` language. Means once you declare a variable,, you cannot change the type.
- C++ is OO. allows us to represent real-life objects in programming. Those real life objects are going to be represented with their properties or attributes and then their behaviors. Most important concepts of OO are classes and objects.
- Class is blueprint, template. Object is concretet example of that class or instance.
- Class can be animal, object can be dog,cat.

# Setup
- Need text editor and compiler. IDE has everything. Visual Studio -> Community version for Windows. 
- First, compile code and build using the `build` tab. 
- You can compile and run using the `debug` tab with `Start Debugging`
- To avoid the syntax bulk code that comes after running the code, add, `system("pause>0")`
- For Mac, no support for Visual Studio but install extensions for VSCode. `C/C++`, `Code Runner`. To run the code, make sure to click the `play` symbol on the top right first. TO enable input, 
* In VsCode, Go to File > Preference > Setting.
* In the User tab on the left panel, find the extensions section
* Scroll and find 'Run Code Configuration'
* Scroll and find a checkbox “Run in Terminal” (Whether to run code in Integrated Terminal) Check the box.
OR
* In your “setting.json” file, add:
"code-runner.runInTerminal": true

# C++ Concepts

## Printing
- to print to the console, use cout.
- std is a namespace. Standard to include to use the cout command. Unless declared on top
```cpp
    cout<<"Enter your name" << endl;
```

## Data Types
- a variable in C++ is just a container that takes memory and that container can hold a data of a certain type
- Types: `integer`, `floating point number`, `character`, `boolean`, `string`, `array`
- Similar to Javscript, if variable is declared using `const`, you will not be able to reassign.

DATA TYPES
```cpp
int age = 25;
age = 26;

//stores decimal
float weight = 65.5;
//double can store double the data. can hold larger number or show with more decimals
double balance = 12345.67;
//char can hold one char. to assign a vlaue to char, use single quotes
char gender = 'm';
//string hold regular string. more than 1 charatcert. double quotes
string username = "Code";
//smallest data type in C++ in booleans
bool isSunnyToday = false;
```

## Array
- array. collection of vars of a certain type. Array takes contionous space in memory. When declaring an array, have to specify its size upfront
- in C++, cannot have an array that stores a char, integer, string. Specify the type of array upfront
- if you initialize the array with vals, you can omit declaring the array size
```cpp
string colors[10] = {"red", "green", "blue", "pink", "black"};

//print out specidic index in array
cout << colors[1];
//to reassign value at specific position
cin>>colors[1]; // takes input from user with cin
cout << colors[1];
```
- once you reach the max limit in thtat set array, you have to recreate array, reinitialize so it can take that continous space of memory somewhere else

## Conditions Selection
- executing one part of the code rather than another one depending on a certain condtion
```cpp
#include <iostream>
using namespace std;

// create enumeration in C++
enum EyeColor {
    Brown, Blue, Green, Gray, Other
};

int main(){
    bool isTodaySunny = false;
    bool isTodayWeekend = false;

    // multiple conditions
    if(isTodaySunny && isTodayWeekend){
        cout << "Go to Park" << endl;
    }
    else if(isTodayWeekend && !isTodaySunny){
        cout << "Go to Park but take umbrella" << endl;
    }
    else{
        cout << "Go to work" << endl;
    }
    // nested conditions
    if(isTodayWeekend){
        if(isTodaySunny){
            cout << "Go to Park" << endl;
        }else{
            cout << "Go to Park but take umbrella" << endl;
        }
    }else{
        cout << "Go to work" << endl;
    }
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
    isTodaySunny ? cout << "Go to Park" << endl : cout << "Take an umbrella" << endl;
}
```

## Loops
```cpp
cout << "WHILE:\n";

int counter = 1;
while(counter <= 10){
    cout << counter << endl;
    counter++;
}

cout << "DO-WHILE\n";
// does first and then checks condition
do{
    cout << counter << endl;
    counter++;
}while(counter <=10);

//FOR used for when you know in advance how many iterations
string animals[5] = {"cat", "dog", "cow", "goat", "bee"};
for(int i = 0; i < 5; i++){
    cout << animals[i] << endl;
}
```

## Functions
- FUNCTIONS, block of code that is organized and grouped together in way so that it can perform a specific task 
- NOTE function declaration happens BEFORE main function, function definition happens AFTER main function
- To invoke, call function inside of main;
```cpp
 // function that returns value
 // declare what the return type of the function will be
 // known as function declaration. it goes before main function
float sum(float a, float b);

// function that doesn't return value. has to be declared with return type void (nothign)
void introduceMe(string name, int age = 0); // default parameter

int main(){
    cout << sum(2.2, 5) << endl;
    introduceMe("Rei", 13);
}
// function definition. comes after main function
float sum(float a, float b){
    return a + b;
}

void introduceMe(string name, int age){
    cout << "My name is " << name << endl;
    cout << "My age is " << age << endl;
}
```

## Pointers
- POINTERS instead of storing a value itself, it stores address of a variable
- Ex. an integer variable can store an integer number, a whole number. An integer pointer is going to store an address of an integer variable
- TWO common uses of pointers: 
    1. poitners with functions and 
    2. pointers with arrays
```cpp
void celebrateBirthday(int* age); // star symbol acccpets the pointer variable

int main(){
    
    // POINTERS W/ FUNCTIONS
    int myAge = 56;
    cout << "BEFORE function age: " << myAge << endl; //56
    //celebrateBirthday(myAge); //function gets it own copy of the age and doesn't directly mutate the original
    celebrateBirthday(&myAge);  // if we want to directly mutate, pass the address of the variable using &. Since we're passing an address, have to receive a pointer in the declaration
    cout << "AFTER function age: " << myAge << endl; //56 value does not change

    // POINTERS W/ ARRAYS
    int luckyNums[5] = {1,3,5,7,8};
    cout << luckyNums << endl; // represents address of the first element
    cout << &luckyNums[0] << endl; // print out address of specific index

    // pointer pointing to int variable
    int* luckyPointer= luckyNums; // points to first element address
    cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << endl;
    luckyPointer++;
    cout << "Pointing to " << luckyPointer << ", value: " << *luckyPointer << endl;
}

void celebrateBirthday(int* age){
    // function gets it own copy of the age and doesn't directly mutate the original
    // when receiving pointer, in order to change the pointer's value instead of the address,
    (*age)++; // deference the pointer. Access the val stored on that address. Then incremenet
    cout << "AYEEE " << *age << " birthday." << endl;
}
```

## Classes
```cpp
class Car {
    // In C++ by default, are properties of class are private. If you want to make it public, use public
    public:
        string Name;
        string Color;
        double Price;
    
    // create constructor. does not have return type. constructor has same name as class
    Car(string name, string color, double price){
        // assign declared vars to passed params;
        Name = name;
        Color = color;
        Price = price;
    }

    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << endl;
    }
};

int main(){
    // before main function, define a class 
    Car myCar("Ford", "Red", 50000); // created object of type Car
    // myCar.Name = "Ford";
    // myCar.Color = "Red";
    // myCar.Price = 50000;

    // cout << "Name: " << myCar.Name << endl;
    // cout << "Color: " << myCar.Color << endl;
    // cout << "Price: " << myCar.Price << endl;

    // Contructor method called automatically when instances of class is created

    // Class Methods = represent behavior of class which is basically function
    myCar.getInfo();
}
```
