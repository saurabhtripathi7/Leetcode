/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */

function dfs(obj){
    if(!obj) return false;
    if(typeof obj !== 'object') return obj; //for number, string, boolean, etc.

    if(Array.isArray(obj)){
        let ans = [];
        for(let val of obj){
            let subRes = dfs(val);
            if(subRes) ans.push(subRes);
        }
        return ans;
    }
    
    const ans = {};
    for(let key in obj){  //use 'in' for traversing OBJ and Array ('of' -> iterables)
        let subRes = dfs(obj[key]);
        if(subRes) ans[key] = subRes; 
    }
    return ans;
}

var compactObject = function(obj) {
    return dfs(obj); //write fn inside only when it is needed once
};
