/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function (nums, k) {
    let left = 0;
    let maximumLength = 0;
    let count_zero = 0;
    for (let right = 0; right < nums.length; right++) 
    {
        if (nums[right] == 0)
            count_zero++;
        
        while (count_zero > k) {
            if (nums[left] == 0)
                count_zero--;
            left++;
        }
        maximumLength = Math.max(maximumLength, right - left + 1);
    }
    return maximumLength;
};

const nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
const k = 2

console.log(longestOnes(nums, k));