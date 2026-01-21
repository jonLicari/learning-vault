
# Sorting Algorithm Cheat Sheet

## 1. Comparison-Based Sorting Algorithms

### Merge Sort

- Best: O(n log n)
- **Average: O(n log n)**
- Worst: O(n log n)
- Stable: Yes
- In-place: No (requires O(n) extra space)
- Notes: Very robust; commonly used
### [[Quick Sort]]

- Best: O(n log n)
- **Average: O(n log n)**
- Worst: O(n²)
- Stable: No
- In-place: Yes
- Notes: **Fast** in practice; pivot strategy matters; C++ std::sort uses introspective variant.
### Insertion Sort

- Best: O(n)
- **Average: O(n²)**
- Worst: O(n²)
- Stable: Yes
- In-place: Yes
- Notes: Excellent for nearly sorted data and small datasets
### Heap Sort

- Best: O(n log n)
- **Average: O(n log n)**
- Worst: O(n log n)
- Stable: No
- In-place: Yes
- Notes: Strong worst-case guarantees; typically slower than quicksort in practice.
### Selection Sort

- Best: O(n²)
- **Average: O(n²)**
- Worst: O(n²)
- Stable: No (unless modified)
- In-place: Yes
- Notes: Simple; predictable behavior; **not efficient**.
### Bubble Sort

- Best: O(n) with early-exit check
- **Average: O(n²)**
- Worst: O(n²)
- Stable: Yes
- In-place: Yes
- Notes: Simple but **slow**

---

## 2. Non-Comparison Sorting Algorithms (Value-Based)

### Counting Sort

- Best/Average/Worst: O(n + k)
- Stable: Yes
- In-place: No
- Notes: Extremely fast for small integer ranges; basis for Radix Sort.

### Radix Sort

- Best/Average/Worst: O(nk)
- Stable: Yes (when using stable sub-sort)
- In-place: No
- Notes: Ideal for fixed-size integers or strings; relies on Counting Sort internally.

---

## 3. Real-World Hybrid Algorithms
### IntroSort (C++ std::sort)

- Time: O(n log n) for all cases
- Stable: No
- Notes: Starts as quicksort, switches to heapsort on bad pivots.
    

---

## 4. Quick Reference Summary Table

| Algorithm      | Best       | Average    | Worst      | Stable | In-Place |
| -------------- | ---------- | ---------- | ---------- | ------ | -------- |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | Yes    | Yes      |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | No     | Yes      |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | Yes    | Yes      |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | Yes    | No       |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | No     | Yes      |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | No     | Yes      |
| Counting Sort  | O(n + k)   | O(n + k)   | O(n + k)   | Yes    | No       |
| Radix Sort     | O(nk)      | O(nk)      | O(nk)      | Yes    | No       |
| IntroSort      | O(n log n) | O(n log n) | O(n log n) | No     | Yes      |
