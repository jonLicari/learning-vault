
Default constructors can be deleted to prevent new object instances from being created.

```cpp
class Log {
public:
	Log() = delete; // deletes the ctor so new objects cannot be created
	
	static void Write() {
	
	}
};

int main() {
	Log l; // ! Produces compile error since no constructor exists
	Log::Write(); // this works
	return 0;
}
```