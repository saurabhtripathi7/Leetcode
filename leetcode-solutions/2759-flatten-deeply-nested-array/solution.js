/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    
    if (n === 0) {
        return arr;
    }
    
    let answer = [];
    
    for (let i = 0; i < arr.length; i++) {
        if (n > 0 && Array.isArray(arr[i])) {
            //rec call with depth = n-1
            let flattened = flat(arr[i], n - 1);
            
            // instead of spreading, push elements one by one
            for (let j = 0; j < flattened.length; j++) {
                answer.push(flattened[j]);
            } // or answer.push(...flat(arr[i], n-1)); //spreading method
        } else {
            answer.push(arr[i]);
        }
    }
    
    return answer;
};

