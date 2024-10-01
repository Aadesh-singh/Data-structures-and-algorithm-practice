/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

// Solution
var rotate = function (nums, k) {
  k = k % nums.length; // In case k is larger than the array length
  nums.unshift(...nums.splice(nums.length - k, k));
};
// For k = k % nums.length;
// This line ensures that if k is larger than the length of the array,
//we only rotate the array by the remainder of k divided by the array length.
//For example, rotating an array of length 5 by 7 steps is the same as rotating it by 2 steps (7 % 5 = 2).

//For nums.unshift => unshift add one or more element at start of array
