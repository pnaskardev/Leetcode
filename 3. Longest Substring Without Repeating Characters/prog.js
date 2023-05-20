/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) 
{
    if(s.length==0)
        return;
    if(s.length==1)
        return 1;
    let left=0;
    let st=new Set();
    let maxLength=0;
    for(let i=0;i<s.length;i++)
    {
        while(st.has(s[i]))
        {
            st.delete(s[left]);
            left++;
        }
        st.add(s[i]);
        maxLength=Math.max(maxLength,i-left+1);
    }
    return maxLength;
};


// const s="abcabcbb";
const s="bbbbb";
console.log(lengthOfLongestSubstring(s));