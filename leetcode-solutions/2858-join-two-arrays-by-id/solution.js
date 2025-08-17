/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let res = {};
    arr1.forEach((val)=>{
        res[val.id] = val;
    });

    arr2.forEach((val)=>{
        if(res[val.id]){
            for(let key in val){
                res[val.id][key] = val[key] 
            }
        }
        else{
            res[val.id] = val;
        }
    });
    return Object.values(res)

};
