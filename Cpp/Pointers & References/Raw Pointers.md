

## Constants

1. Const Pointer
2. Pointer to Const Value
3. Const Pointer to Const Value
### Summary Table

| Case | Type                  | Can modify pointer? | Can modify value through pointer? |
| ---- | --------------------- | ------------------- | --------------------------------- |
| 1.   | `int * const p`       | ❌ No                | ✔️ Yes                            |
| 2.   | `const int * p`       | ✔️ Yes              | ❌ No                              |
| 3.   | `const int * const p` | ❌ No                | ❌ No                              |
Note the position of `const`:
- **Left of the `*` means the _value is constant_**
- **Right of the `*` means the *pointer is constant***
#### 1. Constant Pointer

Pointer cannot change what it points to, but the value being pointed to **can** change.

```cpp
int x = 10;
int y = 20;

int* const ptr = &x;   // ptr is const

*ptr = 15;             // ✔️ allowed
ptr = &y;              // ❌ error: ptr is const
```

---

#### 2. Pointer to Const Value

Pointer can change where it points,  
but the value **cannot** be modified through the pointer.

```cpp
int x = 10;
int y = 20;

const int* ptr = &x;   // ptr is not const, value is const

ptr = &y;              // ✔️ pointer can move
*ptr = 15;             // ❌ error: cannot modify const int
```

Equivalent syntax:

```cpp
int const* ptr = &x;
```

---

#### 3. Const Pointer to Const Value

Neither the pointer nor the value can change.

```cpp
int x = 10;

const int* const ptr = &x;
// or: int const* const ptr = &x;

*ptr = 20;   // ❌ cannot modify value
ptr = nullptr; // ❌ cannot change pointer
```

This is the combination of (1) and (2).

---



