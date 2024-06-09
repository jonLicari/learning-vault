
---
Can tell us how well a program can be solved.

## What is Good Code?
1. Readable - is code clean and easy to interpret?
2. Scalable - Big O can tell us how performance scales

See complexity chart.
![complexity-chart](https://miro.medium.com/max/2928/1*5ZLci3SuR0zM_QlZOADv8Q.jpeg) 

Calculates amount of steps as opposed to amount of time for a given algorithm.

## O(n)
Number of operations increases linearly with the number of elements.

## O(1)
Constant time; no matter how many elements exist, the number of operations remains constant.

## Big O Calculation
```javascript
// What is the Big O of the below function? (Hint, you may want to go line by line)
function anotherFunChallenge(input) {
  let a = 5; //O(1)
  let b = 10; //O(1)
  let c = 50; //O(1)
  for (let i = 0; i < input; i++) { 
    let x = i + 1; //O(n)
    let y = i + 2; //O(n)
    let z = i + 3; //O(n)
  }
  for (let j = 0; j < input; j++) { 
    let p = j * 2; //O(n)
    let q = j * 2; //O(n)
  }
  let whoAmI = "I don't know"; //O(1)
}
// O(4) + O(5n)
// O(5n + 4)
// O(n)
```
## Rule Book
### Rule 1: Worst Case
O(n) is calculated based on the worst case.

e.g. program that searches a list for an item and breaks upon finding item can be:
- Best case: desired item is the first element in the list
- Worst case: desired item is the last element in the list

Because there is no guarantee of the location of the desired element, always assume worst case run time.

### Rule 2: Remove Constants
O(n) should be comprised of only terms that scales when inputs grow larger and larger.

e.g. O(n/2 + 101) becomes O(n)
e.g. O(a + 50) becomes O(a)
e.g. O(2n) becomes O(n)

### Rule 3: Different Terms for Inputs
Different inputs must be represented in the O() calculation.

```javascript
function compressBoxesTwice(boxes) {
  boxes.forEach(function(boxes) {
    console.log(boxes);
  });

  boxes.forEach(function(boxes) {
    console.log(boxes);
  });
}
// O(2n) becomes O(n)
```
Now, using two different inputs.
```javascript
function compressBoxesTwice(boxes, boxes2) {
  boxes.forEach(function(boxes) {
    console.log(boxes);
  });

  boxes2.forEach(function(boxes) {
    console.log(boxes);
  });
}
// O(boxes + boxes2) becomes O(a + b)
```
```javascript
function compressBoxesTwice(boxes, boxes2) {
  boxes.forEach(function(boxes) {
    console.log(boxes);

    boxes2.forEach(function(boxes) {
      console.log(boxes);
    });
  });
}
// Multiply nested terms O(a * b)
```

### Rule 4: Drop Non Dominants
Only take the most significant term.
This will be the term which dictates the behaviour of O() as inputs increase.

e.g. O(x^2 + 100x + 52) becomes O(x^2)


See BigO-cheat-sheet+(1).pdf provided by Andrei Neagoie. 

Data Structures + Algorithms = Programs

Data Structures are ways of storing data.
Algorithms are ways of using that data.

## 3 Pillars of Programming
Scalability consists of:
- Speed (CPU)
- Memory (RAM)

Pillars:
1. Readable
2. Speed 
    - Time Complexity: scales well, efficient
3. Memory
    -  Space Complexity

Tradeoff between space and time.

## Space Complexity
Heap - stores variables where we assign values to

Stack - tracks function calls

```javascript
//#5 Space complexity O(1)
function boooo(n) {
    for (let i = 0; i < n; i++) {
        console.log('booooo');
    }
}
// Only additional memory is variable i, therefore O(1)

// #6 Space complexity O(n)
function arrayOfHiNTimes(n) {
    var hiArray = [];
    for (let i = 0; i < n; i++) {
        hiArray[i] = 'hi';
    }
    return hiArray;
}

arrayOfHiNTimes(6)
// Added an array of n elements, therefore O(n)
```
## Summary
Good code is:
1. Readable
2. Scalable (BigO)

BigO describes the upper bound of time complexity and space complexity.