// Move semantics representation
// Here's a function that takes an object of type T and returns an object of the same type T
// This function uses call by value which means that when function is called, 
// an object must be constructed to be used by the function, object has the scope of the function, considered temporary
// since it returns value, another new object is constructed for the return value

// Call by Value
// T f(T o){
//     return o;
// }
// T b = f(a);

// Copy constructor
// T::T(T & old){
//     reset();
//     copy_data(_a,old._a);
//     copy_data(_b,old._b);
//     copy_data(_c,old._c);
//     copy_data(_d,old._d);
// }

// Move constructor (moving data instead of copying it) 
// T::T(T && old){
//     reset();
//     _a = std::move(old._a);
//     _b = std::move(old._b);
//     _c = std::move(old._c);
//     _d = std::move(old._d);
//     old.reset();
// }

// Movin the data involves reassociating the data with the new object. This is accomplished with Rvalue reference
// T & x lvalue reference (cannot be moveed)
// T && y rvalue reference (may be moved)

// UNDERSTANDING LVALUES AND RVALUES

// assignment expression
// (lvalue) a = b; (rvalue)

// You're an r value if...
// a teemporary value that is ready to expire
// x = a + b;
// literal value, pure rvalue, anything returned from a function that is not a reference 
// x = 42;

// USING STD::MOVE
// c++ library provides template function called move
// used to tell the compiler to use an object as it were an rvalue and then to move that value 
// from source loc to dest loc without having to use copy

// #include <cstdio>
// #include <vector>
// #include <string>
// #include <utility>
// using namespace std;

// void message(const string & s) {
//     puts(s.c_str());
//     fflush(stdout);
// }

// void disp_t(vector<string> & v) {
//     if(v.empty()) {
//         puts("[empty]");
//     } else {
//         for( string s : v ) printf("%s ", s.c_str());
//         puts("");
//     }
//     fflush(stdout);
// }

// template <typename T>
// void swap(T & a, T & b) {
//     message("swap()");
//     T _tmp(std::move(a));
//     a = std::move(b);
//     b = std::move(_tmp);
// }

// int main() {
//     vector<string> v1 = { "one", "two", "three", "four", "five" };
//     vector<string> v2 = { "six", "seven", "eight", "nine", "ten" };
    
//     disp_t(v1);
//     disp_t(v2);

//     auto v3 = std::move(v2);

//     disp_t(v1);
//     disp_t(v2);
//     disp_t(v3);
//     return 0;
// }


// MOVE CONSTRUCTOR
// in order to take adv of move semantics in your own classes, need to create move constructor

// #include <cstdio>
// #include <string>
// #include <utility>

// void message(const char * s) {
//     puts(s);
//     fflush(stdout);
// }

// // this version has messages to show which constructor (ctor) is being called.
// class Rational {
//     int _n = 0;
//     int _d = 1;
    
//     // c_str buffer
//     static const int _bufsize = 128;
//     mutable char * _buf = nullptr;
    
// public:
//     Rational() { reset(); message("default ctor"); }
//     Rational(const int & numerator) : _n(numerator), _d(1) { message("int ctor"); }
//     Rational(const int & numerator, const int & denominator) : _n(numerator), _d(denominator) { message("int,int ctor"); }
//     Rational(const Rational & other) : _n(other._n), _d(other._d) { message("copy ctor"); }
//     //move constructor, signarture, noexcept prevents the exceptions from leaving object in an unknown state
//     // whenever you have move constructor, must have no execept qualifier to prevent the exceptions from leaving src obj in unknown state
//     // compiler may ignore move constructor if no noexecpt is included
//     Rational(Rational &&) noexcept;
//     ~Rational();
//     void reset();
//     inline int numerator() const { return _n; }
//     inline int denominator() const { return _d; }
//     Rational & operator = (const Rational &);
//     Rational operator + (const Rational &) const;
//     Rational operator - (const Rational &) const;
//     Rational operator * (const Rational &) const;
//     Rational operator / (const Rational &) const;
//     operator std::string () const;
//     std::string string() const;
//     const char * c_str() const;
// };

// // move constuctor function 
// Rational::Rational(Rational && rhs) noexcept{
//     message("move constuctor");
//     _n = std::move(rhs._n);
//     _d = std::move(rhs._d);
//     rhs.reset();
// }

// Rational::~Rational() {
//     message("dtor");
//     reset();
// }

// void Rational::reset() {
//     _n = 0; _d = 1;
//     if(_buf) delete [] _buf;
//     _buf = nullptr;
// }

// Rational & Rational::operator = ( const Rational & rhs ) {
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

// Rational::operator std::string () const {
//     return string();
// }

// std::string Rational::string () const {
//     return std::string(c_str());
// }

// const char * Rational::c_str() const {
//     if(!_buf) _buf = new char[_bufsize]();
//     snprintf(_buf, _bufsize, "%d/%d", _n, _d);
//     return _buf;
// }

// int main() {
//     Rational a = 7;     // 7/1
//     Rational b(5, 3);   // 5/3
//     Rational c = b;     // copy ctor
//     Rational d = std::move(c);         // default ctor
    
//     printf("a is: %s\n", a.c_str());
//     printf("b is: %s\n", b.c_str());
//     printf("c is: %s\n", c.c_str());
//     printf("d is: %s\n", d.c_str());
    
//     printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    
//     return 0;
// }

// MOVE ASSIGNMENT OPERATOR
// operator is also an important part of supporting move semantics in code
// rational-02.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-11
// #include <cstdio>
// #include <string>
// #include <utility>

// void message(const char * s) {
//     puts(s);
//     fflush(stdout);
// }

// // this version has messages to show which constructor (ctor) is being called.
// class Rational {
//     int _n = 0;
//     int _d = 1;
    
//     // c_str buffer
//     static const int _bufsize = 128;
//     mutable char * _buf = nullptr;
    
// public:
//     Rational() { reset(); message("default ctor"); }
//     Rational(const int & numerator) : _n(numerator), _d(1) { message("int ctor"); }
//     Rational(const int & numerator, const int & denominator) : _n(numerator), _d(denominator) { message("int,int ctor"); }
//     Rational(const Rational & other) : _n(other._n), _d(other._d) { message("copy ctor"); }
//     Rational(Rational &&) noexcept;
//     ~Rational();
//     void reset();
//     inline int numerator() const { return _n; }
//     inline int denominator() const { return _d; }
//     Rational & operator = (const Rational &);
//     //Build a move assignment operator. can't be const since we;re going to be changing the rhs
//     // add && to make a R-value reference
//     // add noexcept so that this operator cannot be interrupted by an exception
//     Rational & operator = (Rational &&) noexcept;
//     Rational operator + (const Rational &) const;
//     Rational operator - (const Rational &) const;
//     Rational operator * (const Rational &) const;
//     Rational operator / (const Rational &) const;
//     operator std::string () const;
//     std::string string() const;
//     const char * c_str() const;
// };

// Rational::Rational(Rational && rhs) noexcept {
//     message("move ctor");
//     _n = std::move(rhs._n);
//     _d = std::move(rhs._d);
//     rhs.reset();
// }

// Rational::~Rational() {
//     message("dtor");
//     reset();
// }

// void Rational::reset() {
//     _n = 0; _d = 1;
//     if(_buf) delete [] _buf;
//     _buf = nullptr;
// }

// Rational & Rational::operator = ( const Rational & rhs ) {
//     message("op move =");
//     if( this != &rhs ) {
//         _n = rhs.numerator();
//         _d = rhs.denominator();
//     }
//     return *this;
// }

// // move assignment operator defintion
// Rational & Rational::operator = (Rational && rhs) noexcept{
//     // return d rederence to this pointer
//     message("op move =");

//     if( this != &rhs ) {
//         _n = std::move(rhs._n);
//         _d = std::move(rhs._d);
//         rhs.reset();
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

// Rational::operator std::string () const {
//     return string();
// }

// std::string Rational::string () const {
//     return std::string(c_str());
// }

// const char * Rational::c_str() const {
//     if(!_buf) _buf = new char[_bufsize]();
//     snprintf(_buf, _bufsize, "%d/%d", _n, _d);
//     return _buf;
// }

// int main() {
//     Rational a = 7;     // 7/1
//     Rational b(5, 3);   // 5/3
//     Rational c = b;     // copy ctor
//     Rational d = std::move(c);
    
//     printf("a is: %s\n", a.c_str());
//     printf("b is: %s\n", b.c_str());
//     printf("c is: %s\n", c.c_str());
//     printf("d is: %s\n", d.c_str());
    
//     printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    
//     return 0;
// }

// COPY AND SWAP IDIOM
// uses a class's existing copy constructor and destuctor methods to provide addiional efficiency for the copy assignment operator
// #include <cstdio>
// #include <string>
// #include <utility>

// void message(const char * s) {
//     puts(s);
//     fflush(stdout);
// }

// // this version has messages to show which constructor (ctor) is being called.
// class Rational {
//     int _n = 0;
//     int _d = 1;
    
//     // c_str buffer
//     static const int _bufsize = 128;
//     mutable char * _buf = nullptr;
    
// public:
//     Rational() { reset(); message("default ctor"); }
//     Rational(const int & numerator) : _n(numerator), _d(1) { message("int ctor"); }
//     Rational(const int & numerator, const int & denominator) : _n(numerator), _d(denominator) { message("int,int ctor"); }
//     Rational(const Rational & other) : _n(other._n), _d(other._d) { message("copy ctor"); }
//     Rational(Rational &&) noexcept;
//     ~Rational();
//     void reset();
//     inline int numerator() const { return _n; }
//     inline int denominator() const { return _d; }
//     Rational & operator = (Rational);
//     // Rational & operator = (Rational &&) noexcept;
//     Rational operator + (const Rational &) const;
//     Rational operator - (const Rational &) const;
//     Rational operator * (const Rational &) const;
//     Rational operator / (const Rational &) const;
//     operator std::string () const;
//     std::string string() const;
//     const char * c_str() const;
//     void swap(Rational &);
// };

// Rational::Rational(Rational && rhs) noexcept {
//     message("move ctor");
//     _n = std::move(rhs._n);
//     _d = std::move(rhs._d);
//     rhs.reset();
// }

// Rational::~Rational() {
//     message("dtor");
//     reset();
// }

// void Rational::reset() {
//     _n = 0; _d = 1;
//     if(_buf) delete [] _buf;
//     _buf = nullptr;
// }

// Rational & Rational::operator = (Rational rhs) {
//     message("copy and swap");
//     // no longer passing a ref. when method is invoked, a temp copy of rhs is made for param
//     // this call copy constructor on that new temp obj
//     // pass by val copy is more efficient than creating a temp obj in the body of the method
//     // perform swap on temp obj
//     // automatically destroyed when it goes out of scop 
//     swap(rhs);
//     return *this;
// }

// // Rational & Rational::operator = ( Rational && rhs ) noexcept {
// //     message("op move =");
// //     if ( this != &rhs ) {
// //         _n = std::move(rhs._n);
// //         _d = std::move(rhs._d);
// //         rhs.reset();
// //     }
// //     return *this;
// // }

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

// Rational::operator std::string () const {
//     return string();
// }

// std::string Rational::string () const {
//     return std::string(c_str());
// }

// const char * Rational::c_str() const {
//     if(!_buf) _buf = new char[_bufsize]();
//     snprintf(_buf, _bufsize, "%d/%d", _n, _d);
//     return _buf;
// }

// void Rational::swap(Rational & o){
//     std::swap(_n,o._n);
//     std::swap(_d,o._d);
// }

// int main() {
//     Rational a(5,3);     
//     Rational b(9, 5);  
//     b = std::move(a);

//     printf("a is: %s\n", a.c_str());
//     printf("b is: %s\n", b.c_str());
    
//     return 0;
// }

// RULE OF FIVE

// rule of three
// ~Class(); // Destrrcutor
// Class(Class &); // Copy construc
// Class & operator = (Class &); // copy assignment
// with move semantics...
// Class & operator = (Class &); // copy assignment
// Class & operator = (Class &&); // move assignment
// with copy and swap idion... (just combine into 1)
// Class & operator = (Class)