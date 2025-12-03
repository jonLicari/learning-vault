
An **lvalue** is something that **points to a specific memory location**. 

An **rvalue** is something that **doesn’t point anywhere**.

In general, **rvalues are short lived and temporary**, while **lvalues live a longer life since they exist as variables**. You can think of **lvalues as containers** and **rvalues the things stored inside the containers**. Without a container they would expire. 

  
```cpp
int x = 420;
```

Here, 420 is the rvalue, the actual data being stored in the lvalue, in this case, variable x.

(Source: [Understanding the meaning of lvalues and rvalues in C++](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c))