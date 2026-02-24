## Reverse String using New String

### Solution: Read Characters into New Reversed String

- Create `reverse` string
- Loop through original string backwards
	- Find the size of the string
	- Set loop counter to be the last index
	- Append the character into the new `reverse` string
	- Decrement counter until string is fully traversed
	- **Time: O(n)**

```cpp
#include <string>

class Solution {
public:
	bool isPalindrome(int x) {
		// convert x to string
		const auto original = std::to_string(x);
		// create reverse string		
		std::string reverse;
		for ( auto c : original) {
			reverse.insert(reverse.begin(), c);
		}
		
		// compare strings; return true if equal
		return (reverse == original) ? true : false;
	}
};
```

This may not always be an available solution due to the fact that we have to allocate more memory to manipulate the string. We can reduce memory consumption by reversing the string in place. See below.

## Reverse String in Place

#### Solution: Two-pointer Technique

Swap characters from the start and end of the string until the pointers meet in the middle:
- Initialize _left_ or _start_ pointer and _right_ or _end_ pointer
- Replace character at _i<sub>start</sub> + n_ with the character at _i<sub>end</sub> - n_
- Exit when _i<sub>start</sub> + n_ == _i<sub>end</sub> - n_ 

```cpp
// Reverse string in place
void reverseString (const string & original) {
	// two pointer method
	char * left = original.start();
	char * right = original.end();
	
	for ()

}
```


