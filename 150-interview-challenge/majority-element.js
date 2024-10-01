/* Statement
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

// Sol - 1
var majorityElement = function (nums) {
  let count = { "-1": -1 };
  let max = -1;
  for (let i of nums) {
    if (!count[i]) {
      count[i] = 1;
    } else {
      count[i]++;
    }
  }
  // console.log('max:', count);
  for (let k in count) {
    // console.log(k, count[k])
    if (count[k] > count[max]) {
      max = +k;
    }
  }
  // console.log('max: ', max);
  return max;
};

// sol - 2
// this is with constant space and linear time

var majorityEle = function (nums) {
  let finalCount = 0,
    curCount = 0;
  nums.sort((a, b) => a - b);
  let cur = nums[0];
  let final = cur;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] == cur) {
      curCount++;
      if (i + 1 == nums.length) {
        if (finalCount < curCount) {
          finalCount = curCount;
          final = cur;
        }
        cur = nums[i];
        curCount = 1;
      }
    } else {
      if (finalCount < curCount) {
        finalCount = curCount;
        final = cur;
      }
      cur = nums[i];
      curCount = 1;
    }
  }
  return final;
};
