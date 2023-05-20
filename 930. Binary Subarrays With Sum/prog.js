/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function (nums, goal) {

    function calc(nums,goal) {
        let left = 0;
        let right = 0;
        let sum = 0;
        let ans = 0;
        if(goal<0)
        {
            return 0;
        }
        while (right < nums.length) {
            sum += nums[right];
            while (sum > goal) {
                // console.log(`${left} ${right}`);
                sum -= nums[left];
                left++;
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }



    return calc(nums, goal) - calc(nums, goal - 1);
};

const nums = [1, 0, 1, 0, 1];
const goal = 2;
console.log(numSubarraysWithSum(nums, goal));
