Four main concepts:
1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

## Encapsulation

*"Bundle data & operations; hide internals"*

Cpp: group data & operations into classes; use access specifiers
```cpp
class A {
	private: int x;
	public: void setX(int v) { x = v; }
};

```
## Abstraction

*"Expose only essential behaviour; hide details"*

Cpp: Use interfaces (pure virtual functions)
```cpp
class Shape {
public:
    virtual void draw() = 0;   // pure virtual
};

```
## Inheritance

*"Reuse and extend behaviour"*

```cpp
class Base { };
class Derived : public Base { };
```

TODO
- Deep dive, sequence of creation/ destruction for inherited classes, multiple-inherited classes, overridden methods etc.
## Polymorphism

*"Call derived behaviour through base pointer/reference."*

Objects of different types respond to the same method call in their own ways, using a common interface, which runs differently for each. It's achieved through concepts like Method [[Overriding]] (runtime) and [[Overloading]] (compile-time).

For example, *Car*, *Horse*, or *Bicycle* are all *Racer* subclasses but have unique implementations for the single `start()` command.

Cpp: Requires virtual functions and no slicing
```cpp
class Base { public: virtual void f(); };
class Derived : public Base { public: void f() override; };

Base* b = new Derived;
b->f();   // calls Derived::f
```

TODO 
- Runtime polymorphism
- V Tables
- Memory implications

### Good Practices

- Always pass objects by `const &` - you can decide within the function if you need to copy the data but it avoids creating unnecessary and costly copies and bloating/ slowing your code