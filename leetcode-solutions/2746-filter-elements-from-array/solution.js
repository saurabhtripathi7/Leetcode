/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let arr2 = new Array();
    arr.forEach((val, idx)=>{
        if(fn(val, idx)) arr2.push(val);
    });
    return arr2;
};
