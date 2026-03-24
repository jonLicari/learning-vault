
## Logical Shifts

### Left Shift `<<`

```C
const int mask = 1u << bits;
```

*"Take the binary value 1 and shift it left by `bits` positions"*

Example: `1u << 3`
- Take `0b00000001` 
- Shift left `3` positions
- Result: `0b00001000` (8)

### Right Shift (`>>`)

```C
const int mask = bits >> 1u;
```

*"Take the value of `bits` and shift it right by 1 position"*

Example: `3 >> 1u`
- Take `0b00000011`
- Shift right `1` position
- Result `0b00000001` (1)