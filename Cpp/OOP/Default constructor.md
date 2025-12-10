Special method that gets called every time an object gets constructed.

By default, an empty constructor exists under the hood. Up to you to define a unique implementation.

```cpp
class Entity {
public:
	float x, y;
	
	void print() {
		std::cout << x << ", " << y << std::endl;
	}
};

int main() {
	Entity e;
	
	e.print(); // Runs but produces garbage x, y values since no initialization
	
	std::cout << e.x << std::endl; // Compiler error - e not initialized
	
	return 0;
}
```

```cpp
class Entity {
public:
	float x, y;
	
	Entity() {
		x = 0.0f;
		y = 0.0f;
	};
	
	Entity(float x, float y) {
		x = x;
		y = y;
	};
	
	void print() {
		std::cout << x << ", " << y << std::endl;
	}
};

int main() {
	Entity e(10.0f, 50.0f);
	e.print(); // Should print "10.0, 50.0"
		
	return 0;
}
```