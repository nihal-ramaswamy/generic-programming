# Unit 1
## Introduction
- Important to differentiate `how` vs `what`
- Important to know the difference between `interface` and `implementation`

## Object Oriented Languages
- Constructor is called when an object is created
    - Constructor is used for initialization and resource acquiring

- Destructor is called when an object dies
    - Destructor is used for deinitialization and freeing of resources
    - Frees and manages a lot of resources, example: mutex locks, semaphores,
    shares resources, etc
        - This is why constructors and destructors are important, language
          needs to know how to handle the resources

    - Garbage collector works with managing memory on deletion of object
    - When an exception occurs, stack is unwound and catch block is executed
    and destructor is called
        - `try` has a dynamic scope

- Language knows only *when* to call constructor and destructor, but does not
   know *how* to use them

## Garbage Collectors
- Garbage collectors are used to manage memory
    - Garbage is unaccessible memory. The memory has a location, but no access
    - This is opposite of `dangling pointer` who have access but no location

### Philosophy of garbage collectors in various languages
- Java
    - Allows creation of garbage
    - When memory falls below a threshold, spawn a garbage collector thread
    which has low priority
    - This goes through the data segment and then assumes the entire heap is
    garbage and tries to search if a memory location is references from the
    data segment
    - If it is, then it is marked as useful
    - This method is called `mark and sweep`
- Python
    - Every variable has a reference count
    - When count becomes 0, the location is reclaimed
    - This is `References count based garbage collection`
- C++
    - We can use shared pointers or unique pointers
    - Shared Pointers: basically reference counting
    - Unique Pointers: not shared, works on transfer of ownership
- C:
    - No concept of destructor, need to use functions

## Tree/BST
- Search operation = O(n)

## Balanced BST/BTree
- Search operation = O(log n)
- Btree is used because it requires less hard disk access

## Programming Paradigms

### Procedural
- Follows a procedure
- Split into functions

### Functional
- Follows a mathematical function
- Pure: output of each function depends on input. Nothing changes, no loops, no
  assignments
- First class citizen
    - Association of a function with another name
    - Pass function as arguments
    - Return function as result

### Object Oriented
- Type
    - Define what we have and what we can do (set of values and operations)
    - Does nto define how
- Class
    - Stores attributes and behaviour
    - Requires mechanism to make our own type
    - User defined type + implementation
- Object
    - Instance of class
- Encapsulation
    - Maintenance concept
        - Put together attributes and behaviours
        - Access control, not a security feature
        - Design decision
    - Hide implementation and expose interface
        - Hide what can change and expose what should not change
- Abstraction
    - Capture only essential features, ignore non essential ones
    - Depends on observer
    - Languages can support multiple levels of abstraction
- Composition
    - It is when an attribute of a class itself is an object of another class
    - `has a` relationship
    - Very flexible, dynamic runtime binding between objects
    - Reuse mechanism (reuse and method level)
- Inheritance
    - `is a` relationship
    - Compile time binding between classes
    - Also a resuse mechanism
        - Inheritance not mainly built for reuse
        - Reuse at class level
- Polymorphism
    - Many forms
    - Same interface
        - implementation decided during runtime
#### More on Inheritance
- Should support Liskov's substitution property
    - We should be able to replace obejct of base class with an object of the
      derived class
    - Interface of base class should also be interface of the derived class
- We use inheritance to avoid if statements based on attribute values
    - In other words, use inheritance to avoid breaking up of the code when
      attribute gets a new value
    - Polymorphism goes along with interface
        - Overring function to suit the derived class
- Inheritance is a relationship between classes

### Other programming paradigms
- Object based
- Generic

## C++
- Main goal of C++ is efficiency

### Program Structure
- As in C
- Entry function is `main`
- Case sensitive
- Free format source code
    - Formatting does not matter

### Output:
- `<<`: insertion operator, *put to* operator
    - Returns osstream object, helps in cascading output
- `cout`: variable associated with console: output stream
    - Occures left of `<<`

### Header file naming and usage:
- Before C++11
    - `#include <iostream.h>`
- After C++11
    - `#include <iostream>`
    - Introduced the standard namespace
- Header file is very weak concept
    - Any changes to header file will need a recompilation
    - C++20 introduced `modules` to try and fix this issue

### Operators and Semantics
- Same operator might have multiple semantics in C++
    - Example: `<<` can mean the ouput operator or the bitwise shift operator
- Different semantics will not alter the order of evaluation
- Semantics depends on the context, precedence does not
    - Precedence dictates what needs to be executed first which inturn dictates
      semantics

```cpp
#include <iostream> // Header file
using namespace std; // Including standard namespace

namespace Pain {
    void pain() {
        cout << "Internal pain\n";
    }
} // namespace Pain

void pain() {
    cout << "External pain\n";
}

int main() { // Main function is entry point

    cout << "Hello World\n" << "AAAAAAAAA\n"; // Output operator along with cascading
    int pow2_3 = (1 << 3); // Same operator, different meaning

    Pain::pain(); // Calling pain function from namespace
    pain(); // Calling pain function outside namespace

    return 0;
}
```

## Build Concept
1. Edit
    - source file
2. Pre-Process
    - Translation unit/ translation
3. Compile
    - Object file
4. Link
    - Loadable Image
5. Loading
    - Process
6. Run
    - output

- When compiler compiles code, it tells the linker what symbols can be used by
  other translations
    - It says what symbols are globally available
    - It also tells what symbols are used, but not defined
        - In other words, it tells whether a symbol needs external reference
- Linker's duty is to consider all object files and libraries together, resolve
  external references and make them refer to some public symbols
    - To a great extent, linker does not know the language

- C++ follows a one definition rule
    - Any entity can be defined only once
- C follows a tentative definition
    - A tentative definition is any external data declaration that has no initializer and storage class specifier.
    - It may or may not be a definition depending on if an actual external definition is found earlier or later in the translation unit.

- Linker Error:
    - Multiple definitions
        - To prevent this, use `extern`
        - It is for the compiler, nothing happens during runtime
        - To make **constants** available across translations, extern the
          definition and decleration

- Const folding
    - Use of constant is replaced by its value
    - This may or may not result in constant having a location

- Linkage
    - External Linkage
        - Name can be used across translations (example: global variables)
    - Internal Linkage
        - Name can be used only in that translation
        - In C++, const has internal linkage by default
        - Example: external static (linkage)
    - No Linkage
        - Name cannot be used outside the block
        - Example: automatic, internal static (life)

### Static Variables
- Static within the block
    - Internal static
    - Only possible for variables, not functions
        - Functions cannot be nested
    - Persistent storage with block scope
        - Works only within a particular block or function

- Static outside the block
    - External static
    - That variable can be used only within that file or program
    - Permanent storage with file scope
        - Works throughout the program

- External static variables are not given to the linker

## Lvalue and Rvalue
- Lvalue: left of assignment operator
- Rvalue: right of assignment operator

- Right of assignment operator: any expression
- Left of assignment operator: any variable or expression

- Dereferencing a pointer is both Lvalue and Rvalue

```cpp
x = 10;
y = x++; // post
// copy of x is made to a temporary variable
// y copies value from temporary variable
```

```cpp
x = 10;
y = ++x; // pre
// first x is incremented and then copied to y
// no temporary variable
```

- In C
    - Both `++x` and `x++` are not Lvalue
- In C++
    - `++x` is an Lvalue
    - You **cannot** do `x++++`
    - You **can** do `++++x`

- *In case of post increment, there are 1 extra object and 2 extra functions
  being called*

- If the result of an operation is stored in the variable of the programmer, it
  is an Lvalue
- If it is a temporary variable, it is an Rvalue
- Whenever you return a value from a function, it is always temporary

## Object Oriented Inheritance
- Inheritance with polymorphic behaviour
- Overheads
    - There is a pointer to each object we create
    - Table of pointers to fucntions to every class we create
    - Need to have dereferencing at runtime
- We dont use this in generic programming

## Concept of Inheritance
- Base class should provide default implementation
    - Derived class can modify this implementation
- If an interface of the base class cannot be supported, do not use inheritance
    - Can use composition instead
        - Concept is called delegation or forwarding
        - Reuse instead of reinventing the wheel
- Have only common items of derived class in base class

![Delegation](./images/delegation.png)
