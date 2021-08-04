# Static and Dynamic binding in C++ 

# Intro
- `binding` associating the call of a function with the definition of that function.
- `static` all of the info necessary in order to perform that association is avail at compile time so that association is happening at compile time. ie compile time binding or early binding. makes program run faster. happens by default, function call, ufnction overloading, operator overloading
- `dynamic` performed during runtime because all of the info necessary to perform that binding is not avail during compile time but it is avail at runtime. ie runtime binding or late binding. a little slower but flexible, allows us to decide which function definition we want to invoke at runtime. happens during virtual function or function overriding 
```cpp
#include <iostream>
#include <list>
using namespace std;

// float sumNumbers(float a, float b){
//     return a + b;
// }

// float sumNumbers(float a, float b, float c){
//     return a + b + c;
// }

class User{
    public:
        void getPermissions(){
            cout << "Users can see limited info" << endl;
        }
};

class SuperUser:public User{
    void getPermissions(){
        cout << "SuperUsers can see limited info" << endl;
    }
};

void main(){
    // happens at compile time which function to use based on paramters. static binding
    // cout << sumNumbers(1,2) << endl;
    // cout << sumNumbers(1,2,3) << endl;

    // happens at runtime. dynamic binding
    User u;
    SuperUser s;
    list<User*>users; // list of users pointers
    users.push_back(&u); // user pointer
    users.push_back(&s); // super user pointer

    for(User* userPtr:users){
        userPtr->getPermissions();
    }
    cin.get();
    system("pause>0");
}

```