
_Build a new list safely!_

Used when:
- merging
- filtering
- partitioning
- removing elements
- stable reordering

```cpp
ListNode dummy;
ListNode* tail = &dummy;

while (condition) {
    tail->next = chosenNode;
    tail = tail->next;
}

return dummy.next;
```

Examples:
- [[Merge Two Sorted Lists]]

