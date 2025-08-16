/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        let total = functions.length;
        let ans = [];
        let count = 0;

        functions.forEach((fn, idx) => {
            fn()
                .then((val) => {
                    ans[idx] = val;
                    count++;
                    if (total == count) resolve(ans);
                })
                .catch((err) => reject(err));
        })
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
