
Table of Contents
- [[#Static vs Dynamic Arrays|Static vs Dynamic Arrays]]
	- [[#Static vs Dynamic Arrays#Static Array|Static Array]]
	- [[#Static vs Dynamic Arrays#Dynamic Array|Dynamic Array]]
- [[#Implementing an Array|Implementing an Array]]
- [[#Strings & Arrays|Strings & Arrays]]
	- [[#Strings & Arrays#Reversing a String|Reversing a String]]
	- [[#Strings & Arrays#Merge Sorted Arrays|Merge Sorted Arrays]]
- [[#When to Use Arrays|When to Use Arrays]]
	- [[#When to Use Arrays#Good for...|Good for...]]
	- [[#When to Use Arrays#Bad for...|Bad for...]]

---
# Arrays

Organizes data sequentially.

| Operation | BigO |
| --------- | ---- |
| lookup    | O(1) |
| push      | O(1) |
| insert    | O(n) |
| delete    | O(n) |

**Pro**:
- fast lookup
- fast push/ pop

**Cons**:
- slow insertion 
- slow deletion 
- fixed size (unless dynamic)

**Uses**: 
- store data and iterate over it sequentially, especialy if you know the indices of the array

```javascript
const strings = ['a', 'b', 'c', 'd'];
// 4 items x 4 bytes = 16 bytes of storage
strings[2]
// outputs 'c'

//push 
strings.push('e'); // pushes data to last index, O(1)

console.log(strings)
// ['a', 'b', 'c', 'd', 'e']

//pop
strings.pop(); // pops the last index, O(1)

console.log(strings)
// [ 'a', 'b', 'c', 'd' ]

//unshift
strings.unshift('x'); 
// adds data to first index of array, 
// loops through array to shift the rest of the data
// thus, O(n)

console.log(strings)
// [ 'x', 'a', 'b', 'c', 'd' ]

strings.splice(2, 0, 'alien'); // see documentation
console.log(strings)
// [ 'x', 'a', 'alien', 'b', 'c', 'd' ]
```

## Static vs Dynamic Arrays
### Static Array
- Limited by a fixed size 

| Operation | BigO |
| --------- | ---- |
| lookup    | O(1) |
| push      | O(1) |
| insert    | O(n) |
| delete    | O(n) |

### Dynamic Array
- automatically allocate memory if more is needed 
- as more data is appended to the array, the whole array is copied and moved to a different memory space capable of storing it. This operation will cause append to be O(n) because every item will need to be iterated and moved.

| Operation | BigO             |
| --------- | ---------------- |
| lookup    | O(1)             |
| append    | O(1)<sup>1</sup> |
| insert    | O(n)             |
| delete    | O(n)             |
<sup>1</sup> can be O(n)

## Implementing an Array
```javascript
class MyArray {
    constructor() { // creeate object of length 0 and no data
        this.length = 0;
        this.data = {};
    }

    get(index) {    // returns the data stored at the given index
        return this.data[index];
    }

    push(item) {    
        this.data[this.length] = item; // push item to the last index
        this.length++; // increase the length of the array
        return this.length; // return the new length of the array
    }

    pop() {
        const lastItem = this.data[this.length-1]; // store the last item in the array
        delete this.data[this.length-1]; // delete the item from the array
        this.length--; // reduce the length of the array
        return lastItem; // return the popped item
    }

    delete(index) { // delete data at the given index
        const item = this.data[index]; // store the data at the given index
        this.shiftItems(index); // shift succeeding items 
        return lastItem;
    }

    shiftItems(index) {
        for(let i=index; i < this.length-1; i++) { // loop from the index to the end of the array
            this.data[i] = this.data[i+1]; // shift data up to fill the vacant spot
        }
        delete this.data[this.length-1]; // delete the data in the old last index
        this.length--; // reduce the size of the array 
    }
}

const newArray = new MyArray();
newArray.push('I');
newArray.push('am');
newArray.push('not');
newArray.push('hungry');
newArray.push('!');
newArray.pop();
newArray.delete(2);
console.log(newArray)
```

## Strings & Arrays
For most string questions, the solution requires you to break the string down into an array of characters.

### Reversing a String
```javascript
// Create a function that reverses a string:
// 'Hi my name is Jonathan' should be:
// 'nahtanoJ si eman ym iH'
name = ['Hi my name is Jonathan'];
name2 = [];

function reverse(name) { // O(n)
    // check input
    if(!name || name.length < 2 || typeof name !== 'string') {
        return 'Bad input';
    }
    for(let i=0; i < name.length; i++) {
        item = name.[(name.length-1)-i];
        name2.push(item);
    }
    // console.log(name2); // returns an array of characters
    return name2.join(''); // returns a string
}

console.log(name);
reverse(name);
```

### Merge Sorted Arrays
```javascript
function mergeSortedArrays(arr1, arr2) {
    sort = [];
    let a= 0; 
    let b = 0;

    while((a < arr1.length) || (b < arr2.length)) { 
        if (arr1[a] <= arr2[b]) { // element of arr1 is less than element of arr2
            sort.push(arr1[a]);
            a++;
        }
        else if (arr1[a] > arr2[b]) { // element of arr2 is less than element of arr1
            sort.push(arr2[b]);
            b++;
        }
        else if (a === arr1.length) {
          sort.push(arr2[b]);
          b++;
        }
        else if ( b === arr2.length) {
          sort.push(arr1[a]);
          a++;
        }
    }
    return sort;
}

mergeSortedArrays([0,3,4,31], [4,6,30]);
// [ 0, 3, 4, 4, 6, 30, 31 ]
```

## When to Use Arrays
### Good for...
- fast lookups
- fast push/ pop
- ordered

### Bad for...
- slow