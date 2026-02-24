Given a set of data, you are asked to find two elements that satisfy an **arithmetic** condition.

The initial thought is to brute force it with loops but that will yield a time complexity of O(n<sup>2</sup>).

For arithmetic conditions, use a **hash table** for better performance.

Complexity:
- Time: O(n) average
- Space: O(n)

Why it works
- for each element `x` instead of comparing to every other element in the set, simply see if `target - x` exists in the set.

Example: Sum Two Numbers

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.

You can return the answer in any order.

**Example 1:**

**Input:** `nums = [2,7,11,15], target = 9`
**Output:** `[0,1]`
**Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

**Example 2:**

**Input:** `nums = [3,2,4]`, `target = 6`
**Output:** `[1,2]`

**Example 3:**

**Input:** `nums = [3,3], target = 6`
**Output:** `[0,1]`

**Constraints:**

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **Only one valid answer exists.**

#### Brute Force O(n<sup>2</sup>)

```cpp
class Solution {

public:

	vector<int> twoSum(vector<int>& nums, int target) {
	
		vector<int> result = {};
		const auto LAST_INDEX = nums.size() - 1;
		
		for (auto start = 0; start < LAST_INDEX; start++) {
			for (auto i = start + 1; i <= LAST_INDEX; i++) {
				if (nums[start] + nums[i] == target) {
					result.push_back(start);
					result.push_back(i);
				}
			}
		}
		
		return result;
	}
};
```

### Optimized O(n)

