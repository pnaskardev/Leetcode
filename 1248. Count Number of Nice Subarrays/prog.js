/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) 
{
    function calc(nums,k) 
    {
        let left=0;
        let right=0;
        let count_odd=0;
        let ans=0;
        while(right<nums.length)
        {
            if(nums[right]%2!=0)
            {
                count_odd++;
            }
            while(count_odd>k)
            {
                if(nums[left]%2!=0)
                {
                    count_odd--;
                }
                left++;
            }
            ans+=(right-left+1);
            right++;
        }   
        return ans; 
    }

    return calc(nums,k)-calc(nums,k-1);

};

const arr=[1,1,2,1,1];
const k=3;
console.log(numberOfSubarrays(arr,k));
// console.log(numberOfSubarrays(arr,k-1));

