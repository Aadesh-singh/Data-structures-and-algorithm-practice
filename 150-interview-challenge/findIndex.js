/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1


*/

// Approach: implement binary search
var searchInsert = function (nums, target) {
  // Helper function with boundary parameters
  const binarySearch = (nums, target, left, right) => {
    if (left > right) return left; // Insert position

    const mid = Math.floor((left + right) / 2);

    if (nums[mid] === target) return mid;
    else if (nums[mid] > target) {
      return binarySearch(nums, target, left, mid - 1);
    } else {
      return binarySearch(nums, target, mid + 1, right);
    }
  };

  // Initial call with boundaries set to start and end of the array
  return binarySearch(nums, target, 0, nums.length - 1);
};
