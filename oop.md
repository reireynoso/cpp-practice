# Object Oriented Programming
- OOP allows you to represent real life objects in programming. Represented together with their attributes and their behaviors

## Intro to Classes and Objects
- `Class` is going to represent a template, blueprint. It is user defined data type
- `Object` represents an instance of that class

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
- contructor has same name as class. also does not have return
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

## What is encapsulation in programming?
- `Encapsulation` states that properties of class should not be public, and only methods should be able to access/change them.

```cpp
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    private:
        string Name;
        string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    public:
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

    void subscribe(){
        SubscribersCount++;
    }

    void unsubscribe(){
        if(SubscribersCount){
            SubscribersCount--;
        }
    }

    void PublishVideo(string title){
        ytChannel.PublishedVideoTitles.push_back(title)
    }
}

int main(){
    YouTubeChannel ytChannel("Sample", "Owner");
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.unsubscribe();
    ytChannel.getInfo();
    ytPublishVideo("Title");
}
```

## What is inheritance in programming?
-

```cpp
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    private:
        string Name;
        // string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
        string OwnerName; // can be accessed from another derived class but not directly
    public:
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

    void subscribe(){
        SubscribersCount++;
    }

    void unsubscribe(){
        if(SubscribersCount){
            SubscribersCount--;
        }
    }

    void PublishVideo(string title){
        ytChannel.PublishedVideoTitles.push_back(title)
    }
}

// public access modifier, whatever is public in the base class will also be public to the dervied
class CookingYouTubeChannel:public YouTubeChannel {
    CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name,ownerName){
        // receive properties to initilize
        // will not be intialized in the contructor but in the base consturctor. Call constructor of base class and pass the paremeters
    }
}

int main(){
    CookingYouTubeChannel ytChannel("Cooking Show", "Cook"); // needs its constructor
    ytChannel.PublishVideo("Food");
    ytChannel.PublishVideo("Sushi Food");
    ytChannel.GetInfo();
}
```

## What is polymorphism in programming? 
- `Polymorphism` describes the ability of an object to have multiple forms. Can have two or more objects that inherit from the same base class.
- Those objects can have the method that have the same name but different implementation, different behavior

```cpp
#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
    private:
        string Name;
        // string OwnerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
        string OwnerName; // can be accessed from another derived class but not directly
        int contentQuality;
    public:
    //constructor method
    YouTubeChannel(string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        contentQuality = 0;
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

    void subscribe(){
        SubscribersCount++;
    }

    void unsubscribe(){
        if(SubscribersCount){
            SubscribersCount--;
        }
    }

    void PublishVideo(string title){
        ytChannel.PublishedVideoTitles.push_back(title)
    }

    void checkAnalytics(){
        if(contentQuality <5){
            cout << Name << " has bad quality" << endl;
        }else{
            cout << Name << " has good quality" << endl;
        }
    }
}

// public access modifier, whatever is public in the base class will also be public to the dervied
class CookingYouTubeChannel:public YouTubeChannel {
    CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name,ownerName){
        // receive properties to initilize
        // will not be intialized in the contructor but in the base consturctor. Call constructor of base class and pass the paremeters
    }

    void Practice(){
        cout << owenerNmae << " is practicing cooking" << endl;
        contentQuality++;
    }
}

class SingingYouTubeChannel:public YouTubeChannel {
    SingingYouTubeChannel(string name, string ownerName):YouTubeChannel(name,ownerName){
        // receive properties to initilize
        // will not be intialized in the contructor but in the base consturctor. Call constructor of base class and pass the paremeters
    }

    void Practice(){
        cout << owenerNmae << " is practicing singing" << endl;
        contentQuality++;
    }
}

int main(){
    CookingYouTubeChannel ytChannel("Cooking Show", "Cook"); // needs its constructor
    ytChannel.PublishVideo("Food");
    ytChannel.PublishVideo("Sushi Food");
    ytChannel.GetInfo();
    ytChannel.practice();
    SingingYouTubeChannel singChannel("Cooking Show", "Cook");
    singChannel.practice();

    // a pointer of base class can point to a variable of derived class
    YouTubeChannel* yt1 = &ytChannel;
    YouTubeChannel* yt2 = &singChannel;

    yt1->CheckAnalytics(); // changed dots to arrow. used to invoke methods using pointers
    yt2->CheckAnalytics();
}
```

## Relationship between Virtual Functions, Pure Virtual Functions and Abstract Classes in OOP
- `Virtual Function` a function that is defined in base class and then it's redefined in derived class. A virtual function has a very specific ppurpose and the main purpose of virtual functions is to give you the ability of runtime polymorphism.
- `Pure Virtual Function` force all derived classes to make their own implementation of this function
```cpp
#include <iostream>
#include <list>
using namespace std;

class Instrument {
    public:
        // virtual indicates that if a function with the same name exists in the derived class, otherwise run this
        // virtual void makeSound(){
        //     cout << "Instrument is playing...\n";
        // }

        // pure virtual function => class becomes an ABSTRACT class. By definition an abtract class has one PURE VIRTUAL FUNCTION
        // no implementation. each devrived class will have to provide their own implementation
        virtual void makeSound() = 0;
};

class Accordion:public Instrument {
    public:
        void makeSound(){
            cout << "Accordion is playing...\n";
        }
}

class Piano:public Instrument {
    public:
        void makeSound(){
            cout << "Piano is playing...\n";
        }
}

int main(){
    Instrument* i1 = new Accordion(); // pointer to instrument
    // i1.makeSound();
    // i1->makeSound();
    Instrumnents* i2 = new Piano();
    // i2->makeSounds();
    Instrument* instruments[2] = {i1,i2};
    for(int i =0; i<2;i++)
        instruments[i]->makeSound();
}
```

## Abstraction explained with real-life examples and code
- `Abstraction`, showing and displaying important details while not showing the complex
- An abstract class in C++ is a class that has at least one pure virtual function. We cannot create instances of abstract classes but we can create pointers of abstract classes
```cpp
#include <iostream>
using namespace std;

class SmartPhone {
    public:
        virtual void TakeASelfie() = 0;

};

class Android:public SmartPhone {
    public:
        void TakeASelfie(){
            cout << "Android selfie \n";
        }
};

class iPhone:public SmartPhone {
    public:
        void TakeASelfie(){
            cout << "iPhone selfie \n";
        }
}

int main(){
    SmartPhone* s1 = new iPhone();
    s1->TakeASelfie();
}
```

## C++ Operator Overloading (beginner to advanced)

```cpp
#include <iostream>
using namespace std;

struct YouTubeChannel {
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscibersCount){
        Name = name;
        SubscribersCount = subscribersCount;
    }
}

void operator<<(ostream& COUT, YouTubeChannel& ytChannel){
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subs Count: " << ytChannel.SubscribersCount << endl;
    return COUT;
}

struct MyCollection {
    list<YouTubeChannel>myChannels;

    void operator+=(YouTubeChannel& channel){
        this->myChannels.push_back(channel);
    }
}

int main(){

    YouTubeChannel yt1 = YouTubeChannel("Name", 75000);
    cout << yt1; // error. by default c++ doesn't operate on user defined data types have to override function
    operator<<(cout,yt1);
    YouTubeChannel yt2 = YouTubeChannel("Second Channel", 80000);
    cout << yt1 << yt2;

    MyCollection myCollection;
    myCollection += yt1;
    cin.get();

}
```