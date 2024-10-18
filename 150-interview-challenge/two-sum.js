/*1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// 1. BruteForce
// Idea: Iterate all items and check for any pair available.
// we can take j=i+1 because anything in left can be thaught of as already checked index.
var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[j] === target - nums[i]) {
        return [i, j];
      }
    }
  }
  // Return an empty array if no solution is found
  return [];
};

// 2. With Hashmap
// Idea: Here we can trade space with speed, we can create a hashmap and fill it with arr_val: index
// and then we can iterate to check if remaining = target - nums[i] is availabe or not if availabe check it shoudl not count current index.
var twoSum = function (nums, target) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    map.set(nums[i], i);
  }
  for (let i = 0; i < nums.length; i++) {
    const remaining = target - nums[i];
    if (map.has(remaining) && map.get(remaining) !== i) {
      return [i, map.get(remaining)];
    }
  }

  // else return
  return [];
};
