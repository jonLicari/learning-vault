"pointers in disguise"
A way to reference an existing variable.
Unlike pointers, references are not new variables, don't really occupy memory.
References are constant - once a reference is made to a variable, it cannot later be changed to refer to a different variable.
Thus, you must initialize the reference at the time of declaration.

ex. 
```cpp
int main() {

	int var = 8;

	int * b = &var; // pointer

	int& ref = var; // reference
}
```

We can then use the reference as if it were the the variable it's referencing.
ex.

```cpp
...
ref = 2;

std::cout << var << std::endl;
...
```
```Output: 2```

Here's where it is useful. If we wanted to modify a variables value from a separate function, we can achieve this by passing:
1. the variable as a parameter to the function, return the new value, and assign it to the variable
2. the address of the variable as a parameter, dereference the pointer, and modify the value
3. the variable as a reference to the function, allowing the value to be modified as if you had used a pointer but with the simplistic syntax of passing by value

Using Pointers:
```cpp
void Increment(int * ptr) {
	(*ptr)++;
}

int main () {
	int var = 8;
	Increment(&var)
}
```

Using References:
```cpp
void Increment(int& ptr) {
	ptr++;
}

int main () {
	int var = 8;
	Increment(var)
}
```

References are cleaner and simpler than using pointers. If you can get by with using a reference instead of a pointer, always do so. Pointers are more powerful and offer more functionality however, so they cannot be entirely replaced by references.
