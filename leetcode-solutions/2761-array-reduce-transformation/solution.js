/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans = init;
    if(nums.length == 0) return init;
    nums.forEach((val)=>{
        ans = fn(ans, val); 
    });
    return ans;
};
