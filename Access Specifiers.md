
- **Private** 
	- Members are only accessible by other members of the same class, not externals
	- In C++, class members are **private** by default 
- **Public**
	- Members can be accessed outside of the class
	- In C++, struct members are **public** by default
- **Protected**
	- Are similar to private in that they can not be accessed from outside the class but _can_ be accessed by derived classes
- **Friend** (C++ only)
	- A function or class can access private and protected members of another class
	- Useful if you need external functions/ classes to work closely with data of another class but without being a part of the class itself
	- Considerations:
		- Can public methods solve this without major performance impact?
		- Are you avoiding writing proper interfaces?
		- Does this class need access to all private members?
		- Should these classes be combined?

It's a good practise to list class members in order of their visibility for better readability:

```cpp

class Class {
public:
	// public members...
protected: 
	// protected members...
private:
	// private members...
};
```

