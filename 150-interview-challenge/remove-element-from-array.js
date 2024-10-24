/*
Remove Element from array
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

// intuitions
// Try to swap the val with last index, and if last index is val itself then make i-- and lastindex-- and contune to loop again
// by this it will find the right index to swap with thus gives the correct array by end and return len;

var removeElement = function (nums, val) {
  let len = nums.length;
  let swapIdx = len - 1;
  for (let i = 0; i < len; i++) {
    if (nums[i] == val) {
      if (nums[swapIdx] == val) {
        swapIdx--;
        len--;
        i--;
        continue;
      }
      let aux = nums[swapIdx];
      nums[swapIdx] = nums[i];
      nums[i] = aux;
      len--;
      swapIdx--;
    }
  }

  return len;
};
