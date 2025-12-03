A member function of a base class that is redefined in a child class is declared using the virtual keyword. It tells the compiler to perform dynamic linkage on the function.

There is a necessity to use the single pointer to refer to all the objects of the different classes. So, we create the pointer to the base class that refers to all the derived objects. But, when the base class pointer contains the address of the derived class object, it always executes the base class function. This issue can only be resolved by using the 'virtual' function.



## Rules of Virtual Function

- must be members of some class.
- cannot be static members.
- accessed through object pointers.
- can be a friend of another class.
- must be defined in the base class, even though it is not used.
- The prototypes of a virtual function of the base class and all the derived classes must be identical. If two functions with the same name but different prototypes, C++ will consider them as the overloaded functions.
- cannot have a virtual constructor, but we can have a virtual destructor

C++11 introduced two more keywords *override* and *final* to better describe our intentions.

## Override

Every time you define a method in the derived class that overrides a virtual method in the base class, you should tag it override.

| Example                                                                                                                                                                                                                                                                                                                                  |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| class Base  <br>{  <br>public:  <br>    virtual void f()  <br>    {  <br>        std::cout << "Base class default behaviour\n";  <br>    }  <br>};  <br>  <br>class Derived : public Base  <br>{  <br>public:  <br>    void f() override  <br>    {  <br>        std::cout << "Derived class overridden behaviour\n";  <br>    }  <br>}; |

## Pure Virtual Function

A virtual function declared and assigned to 0 declares the function as a pure virtual function. You can think of it as setting the function pointer to 0.

```cpp
virtual void onSubExit(uint8_t s, int8_t code, uint8_t index) = 0;
```

Pure virtual functions are used when the designer wants to force derived classes to override the function and provide their own implementation.

**If a class contains any pure virtual functions, it is considered an "abstract" class and instances of that class cannot be instantiated.**
