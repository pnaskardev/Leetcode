/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function (s) {
    let left = 0;
    let right = 0;
    let ans = 0;
    let obj = { 'a': 0, 'b': 0, 'c': 0 };
    while (right < s.length) {
        obj[s[right]]++;
        while (obj['a'] > 0 && obj['b'] > 0 && obj['c'] > 0) {
            // console.log(`${left}  ${right}`);
            ans += (s.length - right);
            obj[s[left]]--;
            left++;
        }
        right++;
    }
    return ans;
};

const arr = "abcabc";
console.log(numberOfSubstrings(arr));