
_Change direction of links!_

Used in:
- reverse list
- reverse sublist
- palindrome check
- reorder list
- rotate list

### Principle

```cpp
prev = nullptr;
curr = head;

while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}

return prev;
```