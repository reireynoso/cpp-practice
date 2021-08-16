// A smart pointer is a template class that uses operator overloads to provide the functionality of a pointer
// while providing improved memory management and safety
// Essentially a wrapper around a standard bare C language pointer

// Illustration - function signature
// T * f();
// ^ function returns a pointer but what to do with pointer once done? Is it static or allocated memory?
// Can we use delete or use free? Safe?
// Expect some other function will free the memory? 
// No way of really knowing and this leads to memory leak

// #include <memory>
// smart pointer classes are defined in the memory header, must include memory header in order to use these classes

// unique_pointer<T> & f();
// ^ this function returns a unique pointer 
// meaning this is the only copy of this pointer, cannot be copied, can safely destroy its associated resources by calling reset on the pointer
// can transfer ownership by moving it

// unique.cpp by Bill Weinman <http://bw.org/>
// 2018-11-10
// #include <cstdio>
// #include <memory>
// #include <utility>
// #include "strc.h"

// void message(const char * s) {
//     printf("\n%s\n", s);
//     fflush(stdout);
// }

// // display object value from unique_ptr
// void disp(std::unique_ptr<strc> & o) {
//     if(o) puts(o->value());
//     else puts("null");
//     fflush(stdout);
// }

// int main() {
    
//     message("create unique pointer one");
//     std::unique_ptr<strc> a(new strc("one"));
//     disp(a);
    
//     message("make_unique two");
//     auto b = std::make_unique<strc>("two");
//     disp(a);
//     disp(b);
    
//     message("reset a to three");
//     a.reset(new strc("three"));
//     disp(a);
//     disp(b);
    
//     message("move b to c");
//     auto c = std::move(b);
//     disp(a);
//     disp(b);
//     disp(c);
    
//     message("reset a");
//     a.reset();
//     disp(a);
//     disp(b);
//     disp(c);
    
//     message("release c");
//     c.release();
//     disp(a);
//     disp(b);
//     disp(c);
    
//     message("end of scope");
//     return 0;
// }

// shared_pointer<T> f();
// ^ this function returns a shared poitner
// meaning can make copies of the pointer, delete those pointer as much as we want to and resources will be automatically and safely destroyed,
// when all copies of this shared pointers are deleted and go out of scope
// Shared pointer class manages the resources so we don't have to worry

// #include <cstdio>
// #include <memory>
// #include "strc.h"

// void message(const char * s) {
//     printf("\n%s\n", s);
//     fflush(stdout);
// }

// // display object value from shared_ptr (with reference count)
// void disp(const std::shared_ptr<strc> & o) {
//     if(o) printf("%s (%ld)\n", o->value(), o.use_count());
//     else puts("[null]");
//     fflush(stdout);
// }

// int main() {
    
//     message("create pointer with one");
//     auto a = std::make_shared<strc>("one");
//     disp(a);
    
//     std::shared_ptr<strc> b(new strc("two"));
//     disp(b);
    
//     message("reset a to three");
//     a.reset(new strc("three"));
//     disp(a);
    
//     message("b = a");
//     auto c = a;
//     disp(a);
//     disp(b);
//     disp(c);
    
//     message("end of scope");
//     return 0;
    
// }

// weak pointer is a special case of a shared pointer
// not counted in the shared pointers reference count
// useful for cases where you may need a pointer that doesn't affect the lifetime of the resource it points to
// a weak pointer is typically created from a shared poitner
// a weak pointer can be used in a situation where you need to prevent a circular reference

// weak.cpp by Bill Weinman <http://bw.org/>
// 2018-10-09

// #include <cstdio>
// #include <memory>
// #include "strc.h"

// void message(const char * s) {
//     printf("\n%s\n", s);
//     fflush(stdout);
// }

// // display object value from shared_ptr (with reference count)
// void disp(const std::shared_ptr<strc> & o) {
//     if(o) printf("%s (%ld)\n", o->value(), o.use_count());
//     else puts("[null]");
//     fflush(stdout);
// }

// // display object value from weak_ptr (with reference count)
// void disp(const std::weak_ptr<strc> & o) {
//     // must get a lock to use a weak_ptr
//     size_t count = o.use_count(); // weak pointer count
//     if(auto sp = o.lock()) printf("%s (w:%ld s:%ld)\n", sp->value(), count, sp.use_count());
//     else puts("[null]");
//     fflush(stdout);
// }

// int main() {
    
//     message("create shared_ptr");
//     auto a = std::make_shared<strc>("thing");
    
//     message("make several copies");
//     auto c1 = a;
//     auto c2 = a;
//     auto c3 = a;
//     auto c4 = a;
//     auto c5 = a;
    
//     message("reference count is now 6");
//     disp(a);
    
//     message("create weak_ptr");
//     // does not afffect reference count of the shared pointer
//     // a weak pointer cannot be dereferenced without obtaining a shared pointer from it
//     auto w1 = std::weak_ptr<strc>(a);
//     disp(w1);
    
//     message("destroy copies");
//     c1.reset();
//     c2.reset();
//     c3.reset();
//     c4.reset();
//     c5.reset();
    
//     message("reference count should be 1");
//     disp(a);
    
//     message("check weak pointer");
//     disp(w1);
    
//     message("destroy a");
//     a.reset();
    
//     message("check weak pointer");
//     disp(w1);
    
//     message("end of scope");
//     return 0;
    
// }

// Sometimes when destroying a smart pointer, may need to do more than just destroy the managed object

#include <cstdio>
#include <memory>
#include "strc.h"

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> & o) {
    if(o) printf("%s (%ld)\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

void deleter(const strc * o) {
    printf("deleter: ");
    if(o) {
        printf("%s\n", o->value());
        delete o;
    } else {
        printf("[null]\n");
    }
    fflush(stdout);
}

int main() {
    
    message("create shared_ptr");
    std::shared_ptr<strc> a(new strc("thing"), deleter);
    disp(a);
    
    a.reset();
    disp(a);
    
    message("end of scope");
    return 0;
    
}
