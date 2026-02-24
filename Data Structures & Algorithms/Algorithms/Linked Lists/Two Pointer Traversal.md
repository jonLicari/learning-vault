_Move pointers at different speeds or positions!_

Used when:
- finding middle
- cycle detection
- K<sup>th</sup> from end
- intersection detection

## Variant  A: Fast/ Slow Pointer

Used in:
- Find middle of list
- Palindrome list
- Merge sort on linked list
### Principle

```cpp
slow = head;
fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```
Result - `slow` ends at the midpoint

## Variant B: Gap Technique

Create distance between pointers.

Used in:
- Remove Nth element from end
### Principle

```cpp
for (int i = 0; i < k; i++)
    fast = fast->next;

while (fast) {
    slow = slow->next;
    fast = fast->next;
}
```