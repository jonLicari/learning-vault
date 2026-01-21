
## **What is a `friend` in C++?**

A `friend` is a function or class that is allowed to access the **private** and **protected** members of another class.

Think of it like giving someone a **house key** — they can enter your private rooms, even though normal visitors cannot.

---

## **Why does `friend` exist?**

Sometimes you need certain functions to work closely with your class **without making them class members**.

Most common example:

### `operator<<`

```cpp
std::cout << box;
```

The left operand is `std::cout`, so `operator<<` **cannot** be a member of `Box`, but it still needs access to `Box`’s internals.

This is where `friend` comes in.

---

## **How to declare a friend**

Inside the class:

```cpp
class Box {
private:
    int w, h, d;

    friend std::ostream& operator<<(std::ostream& os, const Box& b);
};
```

This lets the operator function access private members like `w`, `h`, `d`.

---

## **Important: A friend is NOT a member**

- It is **declared inside** the class
    
- But **defined outside** the class
    
- It is **not** called with `this`
    
- It does **not** count as a class method
    

```cpp
std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << b.w;   // allowed because it's a friend
    return os;
}
```

---

## **Key points**

✔ A `friend` can access private/protected data  
✔ It is not part of the class's public API  
✔ It maintains encapsulation better than making everything public  
✔ Often used for operators that cannot be members (`<<`, `>>`, `+` sometimes)

---

## Analogy (super simple)

- **Private member** = locked room
    
- **Class member function** = person with the key
    
- **Friend function** = trusted guest with a temporary spare key
    
- **Regular non-member function** = person outside without a key
    

---

If you want, I can show how `friend` is used for other operators like `+`, `==`, or for making two classes share access.

