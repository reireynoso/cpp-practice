# What are header files in C++?

## Intro
- If you want to use function, you must make declaration and definition of that function
- declaration got BEFORE main 
- definition goes AFTER main
```cpp
#include <iostream>

const char* RecommendMeAFood(char firstLetter);

int main(){
    std::cout << "Today I'll eat " << RecommendMeAFood('c');

    system("pause>0");
}

const char* RecommendMeAFood(char firstLetter){
    if(firstLetter == 'a' || firstLetter == 'A')
        return "apple";
    else if(firstLetter == 'b' || firstLetter == 'B')
        return "banana";
    else if(firstLetter == 'c' || firstLetter == 'C')
        return "chocolate";
    else return "pizza";
}
```

## How program compilation works?
- you write cpp files which are source code files
- when a program is compiled, every cpp file will be compiled into an independent compilation unit
- for each cpp file, compiler will generate an obj file
- these compilation units are independent of each other
- Once compiler generates all of these obj files, the job of your `linker` will be to link all of those obj files together into one, which will be application, usually, .exe
- for each file that needs the function, you have to declare it in each cpp file. but cannot define it. cpp will realize you have multiple definitions for the same function declaration.
- the solutiion for this is `header file`. Inside header file, you put all of the declarations and make another file called `implementation` and include the definition.

## Create Header File and Implementation

```cpp
// Food.h
const char* RecommendMeAFood(char firstLetter);

// Food.cpp
#include <Food.h> // look into string as alternative
const char* RecommendMeAFood(char firstLetter){
    if(firstLetter == 'a' || firstLetter == 'A')
        return "apple";
    else if(firstLetter == 'b' || firstLetter == 'B')
        return "banana";
    else if(firstLetter == 'c' || firstLetter == 'C')
        return "chocolate";
    else return "pizza";
}


// Main.cpp
#include <iostream>
#include <Food.h> // look into string as alternative
int main(){
    std::cout << "Today I'll eat " << RecommendMeAFood('c');

    system("pause>0");
}

```

## What is include iostream?
- `iostream` provides us with standard input/output services