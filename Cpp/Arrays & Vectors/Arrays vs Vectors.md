
[[Arrays (Cpp)]] are not entirely replaceable by [[Vectors]] and some cases still suit raw arrays better than vectors.

**Vectors are always dynamic allocations (heap)**, even if it's size is known at compile time and fixed for the duration of its lifecycle.

Raw **arrays can be statically allocated (stack)**.

```
std::array  → fixed size, stack
std::vector → dynamic size, heap
T[]         → low-level memory
```

```cpp
std::vector<int> v(1000);
```

```
Stack:
    v (control object: pointer, size, capacity)

Heap:
    1000 ints
```

### Advantages of Vectors

Vectors are advantageous for:
- Automatic memory management (RAII, no memory leaks)
- Resizable (dynamic memory)
- Bounds-safe access using `.at` (optional checking)
- STL compatibility (algorithms, iterators)
- Copyable / movable (safe semantics)
- Exception safety (strong guarantees)

### Advantages of Raw Arrays

Raw arrays still remain valuable in kernels, embedded systems, real-time code, stack-only constraints - scenarios where heap allocation may be expensive or forbidden.

Advantages:
- No heap allocation
- Predictable lifetime & layout (hardware drivers, DMA buffers, shared memory, )
- Zero allocation overhead (vectors may reallocate during growth when using `push_back`, `realloc`, `copy/move`, but arrays never relocate)
- Compile time size guarantees

### Industry Usage

| Situation                        | Preferred              |
| -------------------------------- | ---------------------- |
| General C++ application          | `std::vector`          |
| Performance-critical but dynamic | `vector` + `reserve()` |
| Fixed small buffer               | `std::array`           |
| Embedded / kernel / DMA          | raw array              |
| Compile-time size                | `std::array`           |
| Legacy C API                     | raw array              |