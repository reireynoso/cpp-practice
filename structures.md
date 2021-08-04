# C++ Structures for Beginners

## Introduction
- `Structures` are not built in data types, user defined data types
```cpp
#include namespace std;

struct SmartPhone {
    string name;
    int storageSpace;
    string color;
    float price;
};

struct Person {
    string name;
    int age;
    Smartphone smartphone;
}

void printSmartphoneInfo(Smartphone smartphone){
    cout << "name: " << smartphone.name << endl;
    cout << "storageSpace: " << smartphone.storageSpace << endl;
    cout << "color: " << smartphone.color << endl;
    cout << "price: " << smartphone.price << endl;
}

int main(){

    // data type for phone
    // string name = "iPhone 12";
    // int storageSpace = 32;
    // string color = "black";
    // float price = 999.99;

    // using user defined data type
    SmartPhone smartphone;
    smartphone.name = "iPhone";
    smartphone.storageSpace = 32;
    smartphone.color = "black";
    smartphone.price = 999.99;

    printSmartphoneInfo(smartphone);

    Person p;
    p.name = "Me";
    p.age = 30;
    p.smartphone = smartphone;

    system("pause>0");
}
```