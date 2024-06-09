Also see [[References]] for similarities.
## Raw Pointers

## Smart Pointers

A way of automating `new` and `delete`. It essentially wraps a raw pointer with automatic cleanup.

Rule of thumb is to use them as much as possible. The benefits of automating memory cleanup and not having to worry about calling `delete` and risk memory leaks is quite invaluable.

The one tradeoff is additional overhead, especially with Shared Pointers because of its reference counting although custom memory management often carries its own overhead.

### Unique Pointers
Cannot duplicate or copy a unique pointer.
It is a scoped pointer meaning once the program execution leaves the scope of the code block where the unique pointer lives, the pointer will free its resource.

If you were able to make a unique pointer reference another unique pointer, when one goes out of scope and is freed, the other is referencing garbage essentially.

```cpp
std::unique_ptr<obj_type> entity = std::make_unique<obj_type>()
```

### Shared Pointers
Utilize a method known as "reference counting".

Reference Counting is essentially a reference counter which increments when a new shared pointer refers to an entity, and decrements when a shared pointer dies.

The resources held by the entity will only be freed once the reference count is 0 (when no more shared pointers referencing that entity exist).

```cpp
#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
	Entity() {
		std::cout << "Created Entity" << std::endl;
	}
	~Entity() {
		std::cout << "Destroyed Entity" << std::endl;
	}
};

int main() {
	{
		// Block A
		std::shared_ptr<Entity> e0;
		{
			// Block B
			std::shared_ptr<Entity> e1 = std:make_shared<Entity>();
			e0 = e1;
		}
		// When we exit Block B, e1 goes out of scope and dies
			// but e0 still exists, so too does the object exist
	}
	// When we exit Block A, e0 goes out of scope and dies
		// since e0 is the last remaining reference, object is now destroyed
}
```

### Weak Pointers
A variation of shared pointers with the difference being that the creation of a weak pointer does NOT increment the reference count of an entity.

This can be used when you do not want to take ownership of an entity but still want to access it.

If a weak pointer is destroyed, the reference count will not decrement.

Similarly, if all shared pointers for an entity die, but a weak pointer to that same entity exists, the entity's resources will be freed and destroyed.

```cpp
#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
	Entity() {
		std::cout << "Created Entity" << std::endl;
	}
	~Entity() {
		std::cout << "Destroyed Entity" << std::endl;
	}
};

int main() {
	{
		// Block A
		std::weak_ptr<Entity> e0;
		{
			// Block B
			std::shared_ptr<Entity> e1 = std:make_shared<Entity>();
			e0 = e1;
		}
		// when we exit Block B, the shared pointer dies
			// since a weak pointer cannot keep an entity alive
			// the entity will be destroyed even though 
			// the weak pointer is still in scope
	}
}
```
