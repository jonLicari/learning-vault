Given a set of strings, find the longest prefix that is common to the whole set.

Note: Finding a common prefix is significantly different (and easier) than finding a common substring because the prefix is known to start at index 0 whereas the substring can appear at any position in the string.
## Solution: Prefix Shrinking

Process:
- Start with first string in the set, assign it to be the prefix
- Compare prefix to the next string in the set
	- if it does not match, remove a suffix character and restart the check
		- If no substrings exist, return ""
	- If it matches, compare to the next string and cycle through the whole set

Time complexity: O(N * M)
- where N is the number of strings in the set
- where M is the maximum length of each string

This solution is optimal performance-wise and is standard for solving this kind of problem but a slightly more optimal solution is preferred in interviews.

## Solution (Optimal): Column Checking

Process:
- Compare the value of all strings in column 0 (index 0 of string)
	- If they don't match, return ""
	- If they match, move to column 1

Time complexity: O(N * M)
- where N is the number of strings in the set
- where M is the maximum length of each string

This solution has the same time-complexity performance as Prefix Shrinking yet it is considered more optimal due to a few other factors:
- Simplicity of Logic 
	- CC logic moves left --> right
	- PS logic moves right  --> left
- Avoid Repeated Checks 
	- PS can repeatedly recheck characters
	- CC only checks characters once
- Less Prone to Bugs
	- PS performs a lot of string operations (find, pop/ push_back, substring vs prefix confusion) which can increase risk of errors
	- CC has simple array index lookups, a lot less prone to errors
- Scalability

When multiple optimal solutions exist:

> Prefer the one that directly mirrors the mathematical definition of the problem.
> Start optimizing: mental complexity, implementation risk, predicatability
