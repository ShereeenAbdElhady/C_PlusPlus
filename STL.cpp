/*
STL is a collection of pre-built classes and functions that make it easy to manage data 
using common data structures like vectors, stacks, and maps.
It saves time and effort by providing ready-to-use, efficient algorithms and containers.

Components of STL:-

A) Containers in C++ STL:
Containers are the data structures used to store objects and data according to the requirement. 
Each container is implemented as a template class that also contains the methods to perform basic operations on it.
 Every STL container is defined inside its own header file.

Containers can be further classified into 4 types:
Sequence Containers : Vector, Deque, List, Forward List, Array
Container Adaptors : Stack, Queue, Priority Queue
Associative Containers : Set, Multiset, Map, Multimap
Unordered Associated Containers : Unordered Set, Unordered Multiset, Unordered Map, Unordered Multimap

B) Algorithms
STL algorithms offer a wide range of functions to perform common operations on data (mainly containers). 
These functions implement the most efficient version of the algorithm for tasks such as sorting, searching, modifying and manipulating data in containers, etc. All STL algorithms are defined inside the <algorithm> and <numeric> header file. Some of the most frequently used algorithms are:

Sort : Arranges elements in ascending order (default).
Binary Search : Checks whether a value exists in a sorted range.
Find : Searches for the first occurrence of a given value.
Count : Counts how many times a value appears in the given range.
Reverse : Reverses the order of elements in the given range.
Accumulate : Computes the sum of all elements in the range.
Unique : Removes consecutive duplicate elements.
Lower bound : Returns iterator to the first element ≥ value in a sorted range.
Upper bound : Returns iterator to the first element > value in a sorted range.
Replace : Replaces all occurrences of old value with new value in the given range.

C) Iterators
Iterators are the pointer like objects that are used to point to the memory addresses of STL containers. 
They are one of the most important components that contributes the most in connecting the STL algorithms with the containers. 
Iterators are defined inside the <iterator> header file.

Benefits of C++ Standard Template Library (STL)
The key benefits of the STL is :

Saves time and effort.
Reliable and Tested
Fast and Efficient
Reusability
Built-in Algorithms

*/

                             /************ Array container ***********/

// CPP program to demonstrate working of array
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main() {

  // construction uses aggregate initialization
  // double-braces required
  array<int, 5> ar1{{3, 4, 5, 1, 2}};
  array<int, 5> ar2 = {1, 2, 3, 4, 5};
  array<string, 2> ar3 = {{string("a"), "b"}};

  cout << "Sizes of arrays are" << endl;
  cout << ar1.size() << endl;
  cout << ar2.size() << endl;
  cout << ar3.size() << endl;
  
  cout << "\nInitial ar1 : ";
  for (auto i : ar1)
    cout << i << ' ';

  // container operations are supported
  sort(ar1.begin(), ar1.end());

  cout << "\nsorted ar1 : ";
  for (auto i : ar1)
    cout << i << ' ';

  // Filling ar2 with 10
  ar2.fill(10);

  cout << "\nFilled ar2 : ";
  for (auto i : ar2)
    cout << i << ' ';


  // ranged for loop is supported
  cout << "\nar3 : ";
  for (auto &s : ar3)
    cout << s << ' ';

  return 0;
}  

                             /************ deque container ***********/
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    
    // Adding elements at the back
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    
    // Displaying elements
    cout << "Elements in deque (added using push_back): ";
    for (int val : d) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}   
                             /************ forward list container ***********/  
// declration and initialization                                                     
#include <bits/stdc++.h>
using namespace std;

void printFL(forward_list<int>& fl) {
    for (auto i : fl)
        cout << i << " ";
    cout << '\n';
}

int main() {
    
    forward_list<int> fl1;
    forward_list<int> fl2(3, 4);
    forward_list<int> fl3 = {1, 5, 3, 4};
    
    printFL(fl2);
    printFL(fl3);
    return 0;
}

// Accessing elements
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};

    // Access the first element
    cout << fl.front() << endl;
    
    // Access third element
    auto it = next(fl.begin(), 2);
    cout << *it;
    return 0;
}

// inserting element
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {5, 4};

    // Inserting Element at front
    fl.push_front(1);
    
    // Insert 3 after the second element
    auto it = fl.begin();
    advance(it, 1);
    fl.insert_after(it, 3);
    
    for (auto x: fl) cout << x << " ";
    return 0;
}

// updating elements
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};

    // Updating first element
    fl.front() = 111;
    cout << fl.front() << endl;
    
    // Updating third element
    auto it = next(fl.begin(), 2);
    *it = 333;
    cout << *it;
    return 0;
}

// finding element
#include <bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> fl = {1, 5, 3, 4};

    // Finding 3
    auto it = find(fl.begin(), fl.end(), 3);
    
    if (it != fl.end()) cout << *it;
    else cout << "Element not Found";
    return 0;
}

                             /************ list container ***********/
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    cout << "List elements: ";
    for (int n : myList){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

// inserting element
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {3, 2};

    l.push_back(5);
    l.push_front(1);
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 4);

    for (auto i : l)
        cout << i << " ";
    return 0;
}

// accessing elements
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {1, 3, 4, 2, 5};

    cout << l.front() << endl;
    cout << l.back() << endl;
    cout << *next(l.begin(), 2);

    return 0;
}

// updating elements
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {1, 3, 4, 2, 5};

    l.front() = 11;
    auto it = l.begin();
    advance(it, 2);
    
    *it = 10;

    for (auto i : l)
        cout << i << " ";
    return 0;
}

// finding elements
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {1, 3, 4, 2, 5};

    // Finding 4
    auto it = find(l.begin(), l.end(), 4);
    if (it != l.end())
        cout << *it;
    else
        cout << "Element Not Found!";
    return 0;
}

// traversing
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {1, 3, 4, 2, 5};

    // Finding 4
    auto it = find(l.begin(), l.end(), 4);
    if (it != l.end())
        cout << *it;
    else
        cout << "Element Not Found!";
    return 0;
}

// deleting elements
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l = {1, 3, 4, 2, 5};

    l.pop_back();
    l.pop_front();
    
    auto it = l.begin();
    advance(it, 2);
    l.erase(it);

    for (auto i : l)
        cout << i << " ";
    return 0;
}

                             /************ priority queue container ***********/
// Max-heap(default behavior):
// priority_queue<int>pq;

// Min-heap
// priority_queue<int,vector<int>,greater<int>>pq;

// Changing Priority Queue Order

/*
All the above operations are demonstrated on a priority queue implementing max heap. 
This can be changed by using a custom comparator in which you define the priority parameter and how to compare them.

If you only want to assign highest priority to the smallest element (min-heap), 
then inbuilt greater<type> functional object can be used.
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(9);
    pq.push(8);
    pq.push(6);

    auto temp = pq;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}

                             /************ set container ***********/
// A Set is a container which stores unique elements in some sorted order
// searching elements
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {1, 2, 3};

    // Accessing elements using find()
    auto it = s.find(1);
    if (it != s.end())
        cout << "Element found: " << *it << endl;

    // Accessing elements using count()
    if (s.count(2))
        cout << "2 exists in the set" << endl;

    // Accessing all elements by traversal
    cout << "All elements: ";
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    return 0;
}

                                   /************ multiset container ***********/
/* Multiset is an associative container similar to a set, but it can store multiple elements with the same value. 
It is sorted in increasing order by default, but it can be changed to any desired order using a custom comparator.
*/                                   
// inserting elements
#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Creating a multiset of integers
    multiset<int> ms;

    // Inserting elements (duplicates allowed)
    ms.insert(5);
    ms.insert(3);
    ms.insert(3);
    ms.insert(1);

    // Print elements (automatically sorted)
    for (auto i : ms)
        cout << i << " ";

    return 0;
}

                                   /************ map container ***********/
// inserting element
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{2, "For"}, {3, "Geeks"}};

    // Inserting a key value pair
    m.insert({1, "Geeks"});

    for (auto x: m)
        cout << x.first << " " << x.second
        << endl;
    return 0;
}

                                   /************ multimap container ***********/
// inserting element
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm;
    
    // Inserting key-value pairs
    mm.insert({1, "Geeks"});
    mm.insert({2, "For"});
    mm.insert({1, "C++"});

    for(auto x: mm)
        cout << x.first << ": " << x.second
        << endl;
    return 0;
}
/* Output
1: Geeks
1: C++
2: For
*/

                                   /************ unordered sets container ***********/

// Accessing elements
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> us = {1, 2, 3, 4, 5};

    // Accessing third element
    auto it = next(us.begin(), 2);
    cout << *it;
    return 0;
}
// output 3

                                   /************ unordered multisets container ***********/
// Accessing elements
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<int> ums =
                    {5, 1, 3, 2, 4, 1};

    // Accessing element using iterator
    auto it = next(ums.begin(), 2);
    cout << *it;
    return 0;
}
// output 3

                                   /************ unordered multimap container ***********/
// declration and initialization
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Creating an empty unordered_multimap
    unordered_multimap<int, string> umm1;
    
    // Creating unordered_multimap using
    // initializer list
    unordered_multimap<int, string> umm2 =
    {{1, "Geeks"}, {2, "For"}, {1, "C++"}};

    for (auto x : umm2) 
        cout << x.first << ": " << x.second
        << endl;
    return 0;
}

/*
 Output
1: C++
1: Geeks
2: For
*/