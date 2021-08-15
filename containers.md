# Containers in C++

## Map C++

1. Syntax: `map<T1, T2> obj;` where T1 is `key` type and T2 is `value` type
2. `std::map` is associative container that store elements in key value combo. Similar to object, key is unique and overrides existing
3. Implemented using self-balance BST
4. Store key-value pair in sorted order on the basis of key (ascending/descending)
5. `std::map` is generally used in Dictionary type problems

```cpp
#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int main(){
    // std::map<string,int> Map;
    // sort in ascending (less) or descendubg (greater). In <>, optional but indicate value     
    std::map<string,int, std::greater<int>> Map;
    Map["Some"] = 100;
    Map["Other"] = 20;
    Map.insert(std::make_pair("Value", 400));

    // loop 
    for(auto &el1: Map){
        cout << el1.first << " " << el1.second << endl;
    }

    // access using [] operator
    cout << Map["Some"] << endl;

    return 0;
}
```

## Vector C++
- Vector is linked list (dynamically) and array (O(1)). combines pros of each DS
- since array does not grow, when capacity runs out, a new array is generated with double the capacity copying elements
- fixes are to define capacity with `Vec.reserve(1000)` or `Vec.resize(1000)` there's no copying

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> Vec;
    for(int i = 0; i < 32; ++i){
        Vec.push_back(i);
        //size => num of elements in "array"
        //capacity => how much elements vector can hold. doubles size everytime space runs out
        cout << Vec.size() << " " << Vec.capacity() << endl;
    }
}
```