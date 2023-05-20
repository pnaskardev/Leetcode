/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) 
{
    let limit=Math.ceil(cardPoints.length/2)
    // console.log(limit);
    if(k>limit)
    {
        let left=0;
        let right=cardPoints.length-1;
        let left_sum=0,right_sum=0;
        let temp=k;
        while(left<cardPoints.length && temp--)
        {
            left_sum+=cardPoints[left];
            // right_sum+=cardPoints[right];
            // sum+=Math.max(cardPoints[left],cardPoints[right]);
            left++;
            // right--;
        } 
        while(right>=0 && temp--)
        {
            // left_sum+=cardPoints[left];
            right_sum+=cardPoints[right];
            // sum+=Math.max(cardPoints[left],cardPoints[right]);
            // left++;
            right--;
        } 
        return Math.max(left_sum,right_sum);    
    }

    let left=0;
    let right=cardPoints.length-1;
    let sum=0;
    while(left<=right && k--)
    {
        // left_sum+=cardPoints[left];
        // right_sum+=cardPoints[right];
        sum+=Math.max(cardPoints[left],cardPoints[right]);
        if(cardPoints[left]>cardPoints[right])
        {
            left++;
        }
        else
        {
            right++;
        }
    }    
    
    return sum;
};

// const arr=[1,2,3,4,5,6,1];
// const arr=[9,7,7,9,7,7,9];
const arr=[2,2,2];
const k=2;
console.log(maxScore(arr,k));