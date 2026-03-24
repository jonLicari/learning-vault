Most Linked List interview questions can be classified as one of the following patterns:
1. [[Dummy Head & Tail Builder]]
2. [[Two Pointer Traversal]]
3. [[In-Place Pointer Reversal]]

| Question                    | Pattern      |
| --------------------------- | ------------ |
| Building new list?          | Dummy + Tail |
| Find position structurally? | Two Pointers |
| Change direction/order?     | Reversal     |
# Recognition Shortcut

When reading a problem, ask:

> Am I constructing a list?  
> → Dummy head

> Am I locating something?  
> → Two pointers

> Am I changing order?  
> → Reverse links

## Core Invariants

#### 1. Never Modify Processed Region
Always maintain a region of the list that is guaranteed correct and never touch it again!
Never modify the processed region once it has been completed.
```
processed part   |   unprocessed part
(correct)        |   (still being worked on)
```

#### 2. Always Ensure a Path to Every Remaining Node Exists
Never break a chain and risk losing nodes - always track chains.

