_"Divide & Conquer"_

Quick Sort:
- Choose pivot: 
	- Pick an element to be a "pivot" 
- Partition the array: rearrange the array around the pivot 
	- **All elements smaller** than the pivot will be on the **left**
	- **All elements greater** than the pivot will be on the **right**
	- We know the pivot is now in the correct position and we keep the index of the pivot
- Recursively Call:
	- Apply the same process to the partitioned sub-arrays (left or right)
- Base Case:
	- Recursion stops when there is only one element left in the sub-array (single elements are sorted)

```cpp

```