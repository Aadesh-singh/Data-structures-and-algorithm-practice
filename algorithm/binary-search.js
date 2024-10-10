let arr = [12, 24, 32, 45, 56];

const calc = (arr, ele) => {
  let len = arr.length;
  if (len <= 0) {
    return -1;
  }
  let mid = Math.floor(len / 2);
  if (arr[mid] === ele) {
    return mid;
  } else if (arr[mid] > ele) {
    return calc(arr.slice(0, mid), ele);
  } else if (arr[mid] < ele) {
    let res = calc(arr.slice(mid + 1, len - 1), ele);
    return res === -1 ? -1 : res + mid + 1;
  }
};

console.log(calc(arr, 45));
