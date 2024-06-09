[Source](https://youtu.be/I-hZkUa9mIs)

Templates are similar to [[Generics]] in other languages, but are way more versatile as Generics are constrained by a multitude of factors such as type-system.

Sort of like a macro in that you can do literally anything (at the cost of increased risk?).

Templates are evaluated at compile-time. This also means that unless a template is called in code, it will not be compiled; syntax errors or other compile-time errors will only be detected in the template once it is called in code (note: this is somewhat compiler dependent).

Template is a feature that allows you to have the compiler produce code inferred by rules that you have written. 

For example, you define a function to be reused in code but with arguments that differ in type.

```cpp
#include <iostream>

void Print(int value) {
	std::cout << value << std::endl;
}

int main() {
	Print(5); // nice
	Print("Hello"); // Not nice, "Hello" is of type const char* not int
	Print(5.5f); // shits fucked up

	return 0;
}
```
For the code above, if we wanted to print the string literal, we would need to [[overload]] the `Print(int)` function  to take in string literals `Print(const char*)`.

Furthermore, if we wanted this function to take in floating points, we would need to introduce _another_ overload implementation.

To avoid all this code duplication, we can simply define a Template.

```cpp
#include <iostream>

template<typename T>
void Print(T value) {
	std::cout << value << std::endl;
}

int main() {
	Print(5); // nice
	Print("Hello"); // nice
	Print(5.5f); // nice

	return 0;
}
```

_typename_ also interchangeable with _class_ refers to the data type to be inferred at compile time.
_T_ is the commonplace name given to the templated type. 

It is also possible to explicitly specify the argument datatype using the following invocation:
`Print<int>(5);` 
Here, we ensure that the argument is evaluated as an integer.

## LeetCode Example 

### Problem

A class template provides a specification for generating classes based on parameters. _Class templates_ are generally used to implement containers. A class template is instantiated by passing a given set of types to it as template arguments. Here is an example of a class, MyTemplate, that can store one element of any type and that has just one member function _divideBy2_, which divides its value by 2.

```cpp
template <class T>
class MyTemplate {
	T element;
	public:
	MyTemplate (T arg) {element=arg;}
	T divideBy2 () {return element/2;}
};
```
It is also possible to define a different implementation of a template for a specific type. This is called _Template Specialization_. For the template given above, we find that a different implementation for type _char_ will be more useful, so we write a function _printElement_ to print the _char_ element:

```cpp
// class template specialization:
template <>
class MyTemplate <char> {
	char element;
	public:
	MyTemplate (char arg) {element=arg;}
	char printElement ()
	{
		return element;
	}
};
```

You are given a main() function which takes a set of inputs. The type of input governs the kind of operation to be performed, i.e. concatenation for _strings_ and addition for _int_ or _float_. You need to write the class template _AddElements_ which has a function _add()_ for giving the sum of _int_ or _float_ elements. You also need to write a template specialization for the type _string_ with a function _concatenate()_ to concatenate the second string to the first string.

**Input Format**

The first line contains an integer . Input will consist of  lines where  is the number given in the first line of the input followed by  lines.

Each of the next  line contains the type of the elements provided and depending on the type, either two strings or two integers or two floating point numbers will be given. The type will be one of _int_, _float_ or _string_ types only. Out of the following two elements, you have to concatenate or add the second element to the first element.

### Solution

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

/*Write the class AddElements here*/
template<typename T>
class AddElements {
	T input1;

	public:
	AddElements(T arg) {
		input1 = arg;
	}

	T add(T arg) {
		return input1 + arg;
	}
};

/* class specialization*/  
template<>
class AddElements <string> {
	string input1;

	public:
	AddElements(string arg) {input1 = arg;}

	string concatenate(string arg) {
		return input1 + arg;
	}
};
  

int main () {
	int n,i;
	cin >> n;
	
	for(i=0;i<n;i++) {
		string type;
		cin >> type;
		
		if(type=="float") {
			double element1,element2;
			cin >> element1 >> element2;
			
			AddElements<double> myfloat (element1);
			cout << myfloat.add(element2) << endl;
		}
		
		else if(type == "int") {
			int element1, element2;
			cin >> element1 >> element2;
			
			AddElements<int> myint (element1);
			cout << myint.add(element2) << endl;
		}
		
		else if(type == "string") {
			string element1, element2;
			cin >> element1 >> element2;
			
			AddElements<string> mystring (element1);
			cout << mystring.concatenate(element2) << endl;
		}
	}
	
	return 0;
}
```