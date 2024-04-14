-----
# How to Solve Coding Problems
## Overview
Ultimately, companies want to know if you can solve their problems.
The interview values the problem solving thought process.
Understanding tradeoffs between [[Software#Data Structures & Algorithms|data structures and algorithms]], space and time complexity.

## What Are Companies Looking For?
1. Analytic Skills
    - How to think through a problem
2. Coding Skills
    - Is code organized, readable?
3. Technical Skills
    - Do you know the fundamentals, understand pros and cons of different solutions?
4. Communication Skills 
    - Does your personality match the company's? Do you fit well, and play well with others?

Know when and why you would use certain data structures and algorithms over others.

See cheatsheet.pdf for an Interview Cheat Sheet.

## Interview Practise Question
Given 2 arrays, create a function that let's a user know (T/F) whether these 2 arrays 
contain any common items.

For example:
    const array1 = ['a', 'b', 'c', 'x']
    const array2 = ['z', 'y', 'i']
    should return false

    const array1 = ['a', 'b', 'c', 'x']
    const array2 = ['z', 'y', 'x']
    should return true

```c
const char array1[4] = {'a', 'b', 'c', 'x'};
const char array2[3] = {'z', 'y', 'i'};

/* The first solution that comes to mind is the quick and dirty nested loop.
For each element of array1, cycle through the elements of array2 and compare.
If a common item is identified, return true. 
Otherwise, if no common items are found, return false.
*/

int i,j;
bool result = false;

for(i=0; i < sizeof(array1); i++) {
    for (j=0; j < sizeof(array2); j++) {
        if (array1[i] == array2[j]) {
            result = TRUE;
            break;
        }
    }
}

printf(result);

/* This solution works but it's bad because the time complexity is O(a*b).
A better solution can reduce the time complexity using a hash map.
Loop through first array and create hash map properties based on array items.
Loop through second array and check if item in second array exists on the created object.
Time complexity reduces to O(a + b) from O(a * b).
*/
```
## Section Summary
Practice the step-by-step problem solving process.
Do not memorize problems, understand the tools at your disposal, the advantages, and uses of each.
Check out the Heuristics section of the cheat sheet for some common tips.

![[Master_the_Interview.png]]![[interview-cheatsheet.pdf]]