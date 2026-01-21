
1. Local Static
2. Static Globally Scoped Variable/ Function
3. Static Class Variable/ Function

## 1. Local Static

The static value persists in memory for the program lifetime so the same value exists if you rerun the function (only gets initialized once).
## 2. Static Globally Scoped Variable/ Function

Variable will share memory with all of the instances of the class. 
Therefore, across ***all instances*** of the class, there will only be ***one instance*** of the static variable.
## 3. Static Class Variable/ Function
See: [[Linker]], [[Translation Units]]

Variable is only visible to the translation unit it was declared in.
If you declare a variable `static int data;` in a file `data.cpp` you cannot access `data` from `main.cpp` as it is only visible to the translation unit, in this case, the file scope of `data.cpp`. Even if you were to declare data in main with [[Extern Keyword]] the linker would not be able to find `data` since the static access modifier makes it essentially private.
