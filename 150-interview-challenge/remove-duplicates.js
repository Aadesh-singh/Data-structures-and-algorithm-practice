/* 26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

*/

// Hashmap
// idea: Create a map object which contain if element is visited or not if not visited then add it to visited map
// else replace no. with out of bound value i.e >100 in this case and sort the array in last.
var removeDuplicates = function (nums) {
  let len = nums.length;
  let countOfRepeat = 0;
  let visited = {};
  for (let i = 0; i < len; i++) {
    if (!visited[nums[i]]) {
      visited[nums[i]] = 1;
    } else {
      nums[i] = 101;
      countOfRepeat++;
      // len--;
    }
  }
  nums.sort((a, b) => a - b);
  // console.log('nums:', nums)

  return len - countOfRepeat;
};

// Recursion
//Idea: divide array in 2 half with base conditon return if arr size is 1 then return arr and merge
// both arr such that copy left and copy right while checking duplicate and return merged arr
// In the end the arr will contain all unique elements.
const helper = (arr) => {
  if (arr.length == 1) return arr;
  let mid = Math.floor(arr.length / 2);
  let arrLeft = helper(arr.slice(0, mid));
  // console.log(arrLeft)
  let arrRight = helper(arr.slice(mid));
  // console.log(arrRight)
  let finalArr = [...arrLeft];
  arrRight.map((i) => {
    if (!finalArr.includes(i)) {
      finalArr.push(i);
    }
  });
  // console.log('finalArr', finalArr);
  return finalArr;
};
