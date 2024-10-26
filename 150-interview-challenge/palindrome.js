/* 
Palindrome
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

// Idea to take reminder of given number and create a reversed number and check if both are equal or not

var isPalindrome = function (x) {
  if (x < 0) return false;
  let rev = 0,
    i = 0,
    n = x;
  while (n > 0) {
    // console.log('n: ', n);
    let rem = n % 10;
    // console.log('rem: ', rem, n);
    n = Math.floor(n / 10);
    // console.log('n: ', n);
    if (i == 0) {
      rev = rem;
    } else {
      rev = rev * 10 + rem;
    }
    // console.log('rev: ', rev);
    i++;
    // console.log('--------------')
  }
  console.log("rev", rev);
  console.log("x", x);
  if (rev === x) return true;
  else return false;
};
