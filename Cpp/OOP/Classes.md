Default visibility (when unspecified) is **private** 
```cpp
class Player {
public: // if unspecified, defaults to private
	int x, y;
	int speed;
	
	void move(int xa, int ya) {
		x += xa * speed; // don't need `this` bc this is not an implementation
		y += ya * speed;
	}	
}; // necessary semi-colon
```

## Structs

Default visibility (when unspecified) is **public**

Really not much difference between structs and classes. 
It really only exists to support backwards compatibility with C.
It can be preferential but some simply use structs as lightweight classes.
If you need complex object data or want to use complex objects or abstractions, use classes.

```cpp
struct Vec2 {
	float x, y;
};
```