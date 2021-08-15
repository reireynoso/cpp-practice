#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// DEFINING A CLASS
// included in .h
// use struct only if there are data members (default to public)
// use class where there are also function members (default to privtae)
// class c1 {
//     int i = 0;
// public: 
//     // best practice to define functions outside of class
//     void setValue(const int & value); // technically, name of var doesn't need to be included
//     // {
//     //     i = value;
//     // }
//     int getValue() const; 
//     // { // function member is const safe, may be used in a const context from the object interface
//     //     return i;
//     // }
// };

// // included in .cpp

// void c1::setValue(const int & value){
//     i = value;
// }
// int c1::getValue() const{ 
//     return i;
// }

// int main() {
//     const int i = 47;
//     c1 o1;
//     o1.setValue(i);
//     printf("Value is %d\n", o1.getValue());  
//     return 0;
//     // system("pause>0");
// }

// FUNCTION MEMBERS
// class A {
// // private: by default
//     int _value = 0;
// public: 
//     // best practice to define functions outside of class
//     void setValue(const int a)
//     {
//         _value = a;
//     }
//     // can have two version of function, one with const and one without
//     int getValue();
//     int getValue() const;
//     // { 
//     //     return _value;
//     // }
// };

// // can have two functions with the same signature but diff is const qualified
// // mutable one will get called by MUTABLE objects
// // const qualified ones will get called by CONST qualified

// // const functions can always be called, from mutable and from const objects
// // non const functions may only be called by non const objects
// int A::getValue(){
//     puts("mutable getValue");
//     return _value;
// }

// // must also be included
// int A::getValue() const{
//     puts("const getValue"); 
//     return _value;
// }


// int main() {
//     A a;
//     a.setValue(42);
//     printf("A is %d\n", a.getValue());  

//     // const qualified object. make sure function is const qualified as well
//     // any method that is called on a const-qualified object MUST be const safe. To do so, put const qualifier in the function definition
//     const A b = a;
//     // b.setValue(42);
//     printf("B is %d\n", b.getValue());  
//     return 0;
//     // system("pause>0");
// }

// CONSTRUCTORS AND DESTRUCTORS
// example 1
// constructors and des are special member functions that serve to create and destroy respectively objects from a class
// class c1 {
//     int i = 0;
// public: 
//     void setValue(const int & value){
//         i = value;
//     }
//     int getValue() const{ 
//         return i;
//     }
// };

// int main() {
//     const int i = 47;
//     c1 o1;
//     o1.setValue(i);
//     printf("Value is %d\n", o1.getValue());  

//     c1 o2 = o1; //using the COPY constructor. if not defined, there's an implicit one
//     printf("Value is %d\n", o2.getValue());  

//     // implicit copy constructor
//     o1.setValue(72);
//     o2 = o1; // copy or assignment operator is being used
//     printf("Value is %d\n", o1.getValue());  
//     printf("Value is %d\n", o2.getValue());  

//     // we get to the end of the code block, the memory for the object is released. implicit destructor
//     return 0;
//     // system("pause>0");
// }

// example 2
// const string unk = "unknown";
// const string clone_prefix = "clone-";

// // -- interface --
// class Animal {
//     string _type = "";
//     string _name = "";
//     string _sound = "";
// public:
//     Animal();   // default constructor no arguments
//     Animal(const string & type, const string & name, const string & sound); // default with arguments
//     Animal(const Animal &); // copy constructor takes arguments as a reference to another object of the same class
//     Animal & operator = (const Animal &); // copy operator
//     ~Animal();  // destructor
    
//     void print() const;
// };

// // -- implementation --
// // special intitializer list, that includes whatever variables (data members) you want to initialize after the colon
// Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
//     puts("default constructor");
// }

// Animal::Animal(const string & type, const string & name, const string & sound)
// : _type(type), _name(name), _sound(sound) {
//     puts("constructor with arguments");
// }

// Animal::Animal(const Animal & rhs) {
//     puts("copy constructor");
//     _name = clone_prefix + rhs._name;
//     _type = rhs._type;
//     _sound = rhs._sound;
// }

// Animal::~Animal() {
//     printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
// }

// void Animal::print () const {
//     printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
// }

// // Something called "Rule of Three"
// // C++ provides implicit methods for the copy constructure, destructor and copy operator
// // Rule of Three state that if you find yourslef needing to provide your own method for any one of these three,
// // should probably provide all three
// Animal & Animal::operator = (const Animal & rhs) {
//     puts("copy operator");
//     if(this != &rhs) {
//         _name = clone_prefix + rhs._name;
//         _type = rhs._type;
//         _sound = rhs._sound;
//     }
//     return *this;
// }

// int main() {
//     Animal a;
//     a.print();
    
//     const Animal b("cat", "fluffy", "meow");
//     b.print();
    
//     const Animal c = b;
//     c.print();
    
//     a = c;
//     a.print();
    
//     return 0;
// }

// EXPLICIT CONSTRUCTORS
// when a constructor has only one parameter, it can be used to provide implicit type conversion
// class c1 {
//     int _value = 0;
//     c1(); // prevent default constructor
// public:
//     // prevents from implicitly converting
//     explicit c1 (const int & value) : _value(value) {}
//     void setvalue( const int & value ) { _value = value; }
//     int getvalue() const { return _value; }
// };

// void func(const c1 & o) {
//     printf("value is %d\n", o.getvalue()); // returns 120 because its the ASVCII value of 'x'. iumplicit conversion
// }

// int main() {
//     c1 o = 'x'; // impliciit conversion can happen only if the constructor has only one argument
//     printf("value is %d\n", o.getvalue()); // returns 120 because its the ASVCII value of 'x'. iumplicit conversion
//     func('x'); 
//     return 0;
// }

// NAMESPACES
// as we begin co create more classes, possibility of naming collisions increases
// namespace in C++ are great for managing this
// typically defined in header files along with class definition
// namespace bw {
    
//     const std::string prefix = "(bw::string) ";
    
//     class string {
//         std::string _s = ""; // scope resolution operator, used to access namespace members
//         string ();
//     public:
//         string ( const std::string & s ) : _s( prefix + s) {

//         }
//         const char * c_str() const { 
//             return _s.c_str(); 
//         }
//         operator std::string & () { 
//             return _s; 
//         }
//         operator const char * () const { 
//             return _s.c_str(); 
//         }
//     };
    
// };  // namespace bwstring

// int main() {
//     const std::string s1("This is a string");
//     std::puts(s1.c_str());
    
//     const bw::string s2(s1);
//     std::puts(s2);
    
//     return 0;
// }

// SELF-REFERENCE POINTER
// a very simple class
// class c1 {
//     int i = 0;
// public:
//     void setvalue( const int & value ) { 
//         i = value; 
//     }
//     int getvalue() const;
//     int getvalue2() const;
// };

// int c1::getvalue() const { 
//     printf("getvalue: this is %p\n", this); // %p gives hexadecimal address of pointer, "this" is a pointer to the current object
//     return i; 
// }

// int c1::getvalue2() const{
//     printf("getvalue2\n");
//     return this->getvalue();
// }


// int main() {
//     const int i = 47;
//     c1 o1;
//     o1.setvalue(i);
//     printf("address of o1 %p\n", &o1); //address of o1
//     printf("value is %d\n", o1.getvalue2());
//     return 0;
// }

// OPERATOR OVERLOADING
// TWO ways to overload operators
// 1. with member functions as part of class def
// 2. separate non-member function
// class Rational {
//     int _n = 0;
//     int _d = 1;
// public:
//     Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
//     Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
//     ~Rational ();
//     int numerator() const { return _n; };
//     int denominator() const { return _d; };
//     // operator overloads
//     // Name of class followed by keyword operator, and operator itself
//     // then we have arguments, only need one operand. lhs of operation is the object itself and rhs is the argument or the operand
//     Rational & operator = ( const Rational & );
//     // these are const safe because they return a separate new object, not a reference to the existing object
//     Rational operator + ( const Rational & ) const;
//     Rational operator - ( const Rational & ) const;
//     Rational operator * ( const Rational & ) const;
//     Rational operator / ( const Rational & ) const;
// };

// // assignment / copy operator
// // returns a reference to itself
// Rational & Rational::operator = ( const Rational & rhs ) {
//     // comparing addresses
//     if( this != &rhs ) {
//         _n = rhs.numerator();
//         _d = rhs.denominator();
//     }
//     return *this;
// }

// Rational Rational::operator + ( const Rational & rhs ) const {
//     return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
// }

// Rational Rational::operator - ( const Rational & rhs ) const {
//     return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
// }

// Rational Rational::operator * ( const Rational & rhs ) const {
//     return Rational(_n * rhs._n, _d * rhs._d);
// }

// Rational Rational::operator / ( const Rational & rhs ) const {
//     return Rational(_n * rhs._d, _d * rhs._n);
// }

// Rational::~Rational() {
//     _n = 0; _d = 1;
// }

// // for std::cout
// std::ostream & operator << (std::ostream & o, const Rational & r) {
//     if(r.denominator() == 1) return o << r.numerator();
//     else return o << r.numerator() << '/' << r.denominator();
// }

// int main() {
    
//     Rational a = 7;        // 7/1
//     cout << "a is: " << a << endl;
//     Rational b(5, 3);    // 5/3
//     cout << "b is: " << b << endl;
//     Rational c = b;        // copy constructor
//     cout << "c is: " << c << endl;
//     Rational d;            // default constructor
//     cout << "d is: " << d << endl;
//     d = c;                // assignment operator
//     cout << "d is: " << d << endl;
//     Rational & e = d;    // reference
//     d = e;                // assignment to self!
//     cout << "e is: " << e << endl;
    
//     cout << a << " + " << b << " = " << a + b << endl;
//     cout << a << " - " << b << " = " << a - b << endl;
//     cout << a << " * " << b << " = " << a * b << endl;
//     cout << a << " / " << b << " = " << a / b << endl;
//     return 0;
// }

// NON-MEMBERS OPERATORS
// operator overloads are often accomplished with member functions defined in a class
// Rule of thumb: if you have a constructor that allows implicit conversions, consider non-member overload operators

// class Rational {
//     int _n = 0;
//     int _d = 1;
// public:
//     Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
//     Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
//     ~Rational ();
//     int numerator() const { return _n; };
//     int denominator() const { return _d; };

//     Rational & operator = ( const Rational & );
//     // transfer operator as non member overload operator
//     // Rational operator + ( const Rational & ) const;
//     Rational operator - ( const Rational & ) const;
//     Rational operator * ( const Rational & ) const;
//     Rational operator / ( const Rational & ) const;
// };

// Rational & Rational::operator = ( const Rational & rhs ) {
//     // comparing addresses
//     if( this != &rhs ) {
//         _n = rhs.numerator();
//         _d = rhs.denominator();
//     }
//     return *this;
// }

// // transfer operator as non member overload operator
// // Rational Rational::operator + ( const Rational & rhs ) const {
// //     return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
// // }

// Rational Rational::operator - ( const Rational & rhs ) const {
//     return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
// }

// Rational Rational::operator * ( const Rational & rhs ) const {
//     return Rational(_n * rhs._n, _d * rhs._d);
// }

// Rational Rational::operator / ( const Rational & rhs ) const {
//     return Rational(_n * rhs._d, _d * rhs._n);
// }

// Rational::~Rational() {
//     _n = 0; _d = 1;
// }

// // for std::cout
// std::ostream & operator << (std::ostream & o, const Rational & r) {
//     if(r.denominator() == 1) return o << r.numerator();
//     else return o << r.numerator() << '/' << r.denominator();
// }

// // non member overload operator
// Rational operator + (const Rational & lhs, const Rational & rhs ) {
//     return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
// }

// int main() {
    
//     Rational a = 7;        // 7/1
//     cout << "a is: " << a << endl;
//     Rational b(5, 3);    // 5/3
//     cout << "b is: " << b << endl;
//     Rational c = b;        // copy constructor
//     cout << "c is: " << c << endl;
//     Rational d;            // default constructor
//     cout << "d is: " << d << endl;
//     d = c;                // assignment operator
//     cout << "d is: " << d << endl;
//     Rational & e = d;    // reference
//     d = e;                // assignment to self!
//     cout << "e is: " << e << endl;
    
//     cout << a << " + " << b << " = " << a + b << endl;
//     cout << a << " - " << b << " = " << a - b << endl;
//     cout << a << " * " << b << " = " << a * b << endl;
//     cout << a << " / " << b << " = " << a / b << endl;

//     cout << 14 << " + " << b << " = " << 14 + b << endl;
//     return 0;
// }

// CONVERSION OPERATORS
// aka conversion function, overloading a cast operator for casting to another type

// class Rational {
//     int _n = 0;
//     int _d = 1;
// public:
//     Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
//     Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
//     ~Rational ();
//     int numerator() const { return _n; };
//     int denominator() const { return _d; };
//     Rational & operator = ( const Rational & );
//     // add conversion operator
//     operator std::string () const;
// };

// Rational & Rational::operator = ( const Rational & rhs ) {
//     if( this != &rhs ) {
//         _n = rhs.numerator();
//         _d = rhs.denominator();
//     }
//     return *this;
// }

// // conversion operator
// Rational::operator std::string() const {
//     if(_d == 1) return std::to_string(_n);
//     else return std::to_string(_n) + "/" + std::to_string(_d);
// }

// Rational operator + ( const Rational & lhs, const Rational & rhs ) {
//     return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
// }

// Rational operator - ( const Rational & lhs, const Rational & rhs ) {
//     return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
// }

// Rational operator * ( const Rational & lhs, const Rational & rhs ) {
//     return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
// }

// Rational operator / ( const Rational & lhs, const Rational & rhs ) {
//     return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
// }

// Rational::~Rational() {
//     _n = 0; _d = 1;
// }

// // for std::cout
// std::ostream & operator << (std::ostream & o, const Rational & r) {
//     // if(r.denominator() == 1) return o << r.numerator();
//     // else return o << r.numerator() << '/' << r.denominator();
//     return o << std::string(r);
// }

// int main() {
    
//     Rational a = 7;        // 7/1
//     cout << "a is: " << a << endl;
//     Rational b(5, 3);    // 5/3
//     cout << "b is: " << b << endl;
//     Rational c = b;        // copy constructor
//     cout << "c is: " << c << endl;
//     Rational d;            // default constructor
//     cout << "d is: " << d << endl;
//     d = c;                // assignment operator
//     cout << "d is: " << d << endl;
//     Rational & e = d;    // reference
//     d = e;                // assignment to self!
//     cout << "e is: " << e << endl;
    
//     cout << a << " + " << b << " = " << a + b << endl;
//     cout << a << " - " << b << " = " << a - b << endl;
//     cout << a << " * " << b << " = " << a * b << endl;
//     cout << a << " / " << b << " = " << a / b << endl;

//     string s = "Rational value is: ";
//     s += b; // doesn't initally work since the string object doesn't know waht to do with a rational num. To fix, add conversion opeartor. tell rational object what to do when it's a string
//     cout << s << endl;
//     return 0;
// }

// INCREMENT AND DECREMENT OPERATORS
// class num {
//     int value = 0;
// public:
//     num( int x = 0 ) : value(x) {}
//     int getvalue() const { return value; }
//     void setvalue( int x ) { value = x; }
//     num & operator ++ ();
//     num operator ++ (int);
//     num & operator -- ();
//     num operator -- (int);
// };


// // pre-increment
// num & num::operator ++ () {
//     cout << "pre-increment: ";
//     value += 1;
//     return *this;
// }

// // post-increment
// num num::operator ++ (int) {
//     cout << "post-increment: ";
//     num temp = *this;
//     value += 1;
//     return temp;
// }

// // pre-decrement
// num & num::operator -- () {
//     cout << "pre-decrement: ";
//     value -= 1;
//     return *this;
// }

// // post-decrement
// num num::operator -- (int) {
//     cout << "post-decrement: ";
//     num temp = *this;
//     value -= 1;
//     return temp;
// }

// ostream & operator << (ostream & o, const num & n) {
//     return o << (n.getvalue());
// }

// int main()
// {
//     num n(42);
//     cout << "value is " << n << endl;
//     cout << "value is " << ++n << endl;
//     cout << "value is " << n << endl;
//     return 0;
// }

// ALLOCATING OBJECT MEMORY
// class c1 {
//     int _a = 0;
//     int _b = 0;
//     int _c = 0;
// public:
//     c1(int i = 0);
//     ~c1();
//     int a() { return _a; }
//     int b() { return _b; }
//     int c() { return _c; }
// };

// c1::c1(int i) : _a(i), _b(i + 1), _c(i + 2) {
//     puts("c1 constructor");
// }

// c1::~c1() {
//     puts("c1 destructor");
// }

// int main() {
//     try {
//         c1 * o1 = new c1[5];
//         printf("o1: %d, %d, %d\n", o1->a(), o1->b(), o1->c());
//         delete [] o1;
//     } catch (std::bad_alloc & ba) {
//         printf("new c1 failed: %s\n", ba.what());
//         return 1;
//     }
    
//     return 0;
// }

// FUNCTOR
// By overloading function operator, you can create an object that operatres as it were a function, functor pattern
// handy for keeping state or context info within function calls
class MultBy {
    int mult = 1;
    MultBy();
public:
    MultBy ( int n ) : mult(n) {}
    int operator () ( int n ) const { return mult * n; }
};

int main() {
    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);
    printf("times4(5) is %d\n", times4(5));
    printf("times4(15) is %d\n", times4(15));
    printf("times10(5) is %d\n", times10(5));
    printf("times10(15) is %d\n", times10(15));
    printf("times15(5) is %d\n", times15(5));
    printf("times15(15) is %d\n", times15(15));
    return 0;
}