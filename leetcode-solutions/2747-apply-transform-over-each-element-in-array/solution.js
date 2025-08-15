/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var map = function(arr, fn) {
    let arr2 = new Array();
    arr.forEach((val, idx)=>{
        arr2.push(fn(val, idx));
    });
    return arr2;
};
