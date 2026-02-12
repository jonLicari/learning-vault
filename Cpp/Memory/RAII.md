Summarized as:
- encapsulate each resource into a class where,
	- the constructor acquires the resource and establishes all [[Class Invariant]]s or throws an exception if that cannot be done 
- always use the resource via an instance of the RAII-class that either
	- has automatic storage duration of temporary lifetime itself or
	- has lifetime that is bounded by the lifetime of an automatic or temporary object

```cpp
std::mutex m;
 
void bad() 
{
    m.lock();          // acquire the mutex
    f();               // if f() throws an exception, the mutex is never released
    if (!everything_ok())
        return;        // early return, the mutex is never released
    m.unlock();        // if bad() reaches this statement, the mutex is released
}
 
void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                     // if f() throws an exception, the mutex is released
    if (!everything_ok())
        return;              // early return, the mutex is released
}                            // if good() returns normally, the mutex is released
```
