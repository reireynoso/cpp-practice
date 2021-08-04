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

## Function Overloading
- `Function Overloading` create functions with the SAME name but functions will have different parameters

```cpp
#include <iostream>
using namespace std;

int sum(int a, int b);
double sum(double a, double b);
float sum(float a, float b, float c);

int main(){
    cout << sum(4,3) << endl;
    system("pause>0");
}

int sum(int a, int b){
    int result = a + b;
    return result;
}

double sum(double a, double b){
    double result = a + b;
    return result;
}

float sum(float a, float b, float c){
    float result = a + b + c;
    return result;
}
```

## Generics function and templates
- Use the same function but different data types
```cpp
#include <iostream>
using namespace std;

template<typename T>
// created a template with generic type
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp
}

int main(){
    cout << sum(4,3) << endl;
    system("pause>0");
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

## Pointers and Arrays

```cpp
#include <iostream>
using namespace std;



int main(){
    int luckyNumbers[5];
    for(int i = 0; i <=4; i++){
        cout << "Number: ";
        cin >> luckyNumbers[i];
    }

    for(int i = 0; i <=4; i++){
        // if you try to iterate and access an element outside, it could reference another memory location space. for example. changing i limit to 5;
        cout << *(luckyNumbers+i) << " "; // another of accessing elements using deferencing
    }
}
```

## Return Multiple values from a Function using Pointers
- How to use pointers to return multiple values from function
```cpp
#include <iostream>
using namespace std;

int getMin(int numbers[], int size){
    int min = numbers[0];

    for(int i = 1; i < size; i++){
        if(numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

int getMax(int numbers[], int size){
    int max = numbers[0];

    for(int i = 1; i < size; i++){
        if(numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

void getMinandMax(int numbers[], int size, int*min, int*max){ // pointer to min and max
    for(int i = 1; i < size; i++){
        if(numbers[i] > *max) //dereference max
            *max = numbers[i];
        if(numbers[i] > *min) //dereference min
            *min = numbers[i];
    }
}

int main(){
    int numbers[5]={5,4,-2,29,6};
    // cout << "Min is " << getMin(numbers,5) << endl;
    // cout << "Min is " << getMax(numbers,5) << endl;
    int min = numbers[0];
    int max = numbers[0];
    getMinandMax(numbers,5,&min,&max); //address of min and max, passing a parameter using a reference => pass an address of a var to function rather than 
    // passing value because if address is not passed, function is going to create a copy and whatever changes will only appear on that copy
    system("pause>0");
    return 0;
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

# Important Characteristics of OOP
- `Encapsulation` => properties of class should NOT be public. User not be available to change as how they want. Create methods that user can invoke to change the data instead.
- `Inheritance` => In C++, can inherit properties and methods of a class to another
- `Polymorphism` => ability of object to have multiple forms. What we should be able to do is to have the same method with the same name but different implementation. With poly, you have a pointer of the base class pointing to an object of derived class
```cpp
class Car {
    // In C++ by default, are properties of class are private. If you want to make it public, use public
    // public:
    private:
        // string Name;
        string Color;
        double Price;
        // bool isBroken;

    // in order to make these accessible outside of the class, you would have to maek it public. But instead, we want to make these accessbile from derived classes
    // third access modifier: protected

    protected:
        string Name;
        bool isBroken;

    public:
    // create constructor. does not have return type. constructor has same name as class
    Car(string name, string color, double price){
        // assign declared vars to passed params;
        Name = name;
        Color = color;
        Price = price;
        isBroken = false;
    }

    // method to manipulate a property of the class
    void crashCar(){
        cout << Name << " crashed" << endl;
        isBroken = true;
    }

    void repairCar(){
        cout << Name << " repaired" << endl;
        isBroken = false;
    }

    void move(){
        if(isBroken)
            cout << Name << " is broken" << endl;
        else 
            cout << Name << " is driving" << endl;
    }

    void getInfo(){
        cout << "Name: " << Name << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << endl;
    }
};

class FlyingCar :public Car { // syntax for inheriting from another class. Flying Car is the derived and the Car is the base class. Public is stating that whatever is public in the base, is also going to be public in the derived.
    public:
    FlyingCar(string name, string color, double price):Car(name,color,price){ // invoke Car constructor and passing the properties to it since it knows how instantiate it.

    }

    void move(){
        if(isBroken)
            cout << Name << " is broken" << endl;
        else 
            cout << Name << " is flying" << endl;
    }
};

class UnderwaterCar :public Car { // syntax for inheriting from another class. Flying Car is the derived and the Car is the base class. Public is stating that whatever is public in the base, is also going to be public in the derived.
    public:
    UnderwaterCar(string name, string color, double price):Car(name,color,price){ // invoke Car constructor and passing the properties to it since it knows how instantiate it.

    }

    void move(){
        if(isBroken)
            cout << Name << " is broken" << endl;
        else 
            cout << Name << " is diving" << endl;
    }
};

int main() {
    Car myCar("Ford", "Red", 50000); // created object of type Car

    // THREE Most important characteristics of OOP are encapsulation, inheritance, and polymorphism
    // Encapsulation => properties of class should NOT be public. User not be available to change as how they want. Create methods that user can invoke to change the data instead.
    // myCar.move();
    // myCar.crashCar();
    myCar.move();
    // Inheritance => In C++, can inherit properties and methods of a class to another
    FlyingCar flyingCar("Sky Fury", "black", 500000);
    // flyingCar.getInfo();
    flyingCar.move();

    // Polymorphism => ability of object to have multiple forms. What we should be able to do is to have the same method with the same name but different implementation
    UnderwaterCar underwaterCar("Sea Storm", "blue", 60000);
    underwaterCar.move();
    // With poly, you have a pointer of the base class pointing to an object of derived class
    // float variable = 5;
    // int* intPtr = &variable;
    Car* car1 = &flyingCar; // create a pointer
    Car* car2 = &underwaterCar;
    car1->crashCar(); // used when want to invoke a method using a pointer
    car2->crashCar();
    return 0;
    // system("pause>0");
}
```

## Introduction to OOP: What are Classes and Objects?

```cpp
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    public:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
}

int main(){
    YouTubeChannel ytChannel;
    ytChannel.Name = "Sample";
    ytChannel.OwnerName = "Owner";
    ytChannel.SubscriberCount = 1800;
    ytChannel.PublishedVideoTitles = {"C++ for beginners Video 1", "HTML & CSS Video 1", "C++ OOP Video 1"};

    cout << "Name" << ytChannel.Name << endl;
    cout << "OwnerName" << ytChannel.OwnerName << endl;
    cout << "SubscribersCount" << ytChannel.SubscribersCount << endl;
    cout << "Videos" << ytChannel.Videos << endl;

    for(string videoTitle : ytChannel.PublishedVideoTitles){
        cout << videoTitle << endl;
    }
}
```

## OOP Constructors and Class Methods

```cpp
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    public:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;

    //constructor method
    YouTubeChannel(string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    void getInfo(){
        cout << "Name" << Name << endl;
        cout << "OwnerName" << OwnerName << endl;
        cout << "SubscribersCount" << SubscribersCount << endl;
        cout << "Videos" << Videos << endl;

        for(string videoTitle : PublishedVideoTitles){
            cout << videoTitle << endl;
        }
    }
}

int main(){
    YouTubeChannel ytChannel("Sample", "Owner");
    ytChannel.PublishedVideoTitles.push_back("C++ for beginners Video 1") // push_back is method on list, to add to list
    ytChannel.PublishedVideoTitles.push_back("HTML & CSS Video 1") 
    ytChannel.PublishedVideoTitles.push_back("C++ OOP Video 1") 
    // ytChannel.Name = "Sample";
    // ytChannel.OwnerName = "Owner";
    // ytChannel.SubscriberCount = 1800;
    // ytChannel.PublishedVideoTitles = {"C++ for beginners Video 1", "HTML & CSS Video 1", "C++ OOP Video 1"};
    ytChannel.getInfo();
    
}
```

## Dynamic Arrays, create/change arrays at runtime
- size of array has to be known at compile time
- allocate/deallocate memory => new/delete
- every time you allocate new memmory, must deallocate
```cpp
#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Size: ";
    cin >> size;
    // int myArray[size];
    int * myArray = new int [size];

    for(int i = 0; i <<size; i++){
        cout << "Array[" << i << "] ";
        cin >> myArray[i];
    }

    for(int i = 0; i <<size; i++){
        cout << myArray[i] << " ";
    }

    delete[]myArray;
    myArray = NULL; // array will not point to address
}
```