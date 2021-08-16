// base class is the class that has members that are to be used in one or more derived classes, aka super class, parent class
// derived class is the class thats being created and is based upon the base class

// members given PUBLIC access are abailable to all objects, base, derived and other objects
// members given PROTECTED are avail to base class and any derived classes
// members given PRIVATE are avail to only base class

// a derived class may also overload members of base class

// FRIENDSHIP
// sometimes want to grant access to a class' private variables, to another object

// POLYMORPHISM
// sometimes it's useful to overload a function that's defined in a base class

#include <iostream>
#include <string>
using namespace std;

// MULTIPLE INHERITANCE
class Fur {
    string _quality;
    Fur(){

    }
    protected:
        Fur(const string & f) : _quality(f){}
    public:
        // getter for quality of fur
        const string & quality() const {return _quality;}
};

// Animal class (base)
class Animal {
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){}

    friend const string & get_animal_name(const Animal &);
protected:
    // protected constructor for use by derived classes
    Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}

    // friend class Dog;
    // friend class Cat;
    // friend class Pig;
public:
    // tells compiler that this member function may be overloaded in derived classes and go look for that 
    // caveat when using virtual qualifier in class, need to also declare virtual destructor
    // because if overloading the function, may be doing things in the derived class that requires a different destructor
    virtual void speak() const;
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
    virtual ~Animal(){}
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int _walked;
public:
    Dog( string n ) : Animal(n, "dog", "woof"), _walked(0) {};
    int walk() { return ++_walked; }
};

// Cat class - derived from Animal
// is inheriting from both Animal and Fur class
// constructs both of teh paired objects
class Cat : public Animal, public Fur {
    int _petted;
public:
    Cat( string n ) : Animal(n, "cat", "meow"), Fur("Silky"), _petted(0) {};
    int pet() { return ++_petted; }
    void speak() const {
        Animal::speak();
        puts("purrr");
    }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int _fed;
public:
    Pig( string n) : Animal(n, "pig", "oink"), _fed(0) {};
    int feed() { return ++_fed; }
};

// friendship 
const string & get_animal_name(const Animal & a){
    return a._name;
}

int main() {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
    cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
    cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;

    cout << "the " << c.type() << " has " << c.quality() << " fur" << endl;

    // animal array of pointers
    Animal *ap[] = {&d, &c, &p};
    // this calls speak defined in base class. Must address "virtual" in base
    // Even though we're taking pointer of cat, it's still considered Animal class
    for(auto p : ap){
        p->speak();
    }
}
