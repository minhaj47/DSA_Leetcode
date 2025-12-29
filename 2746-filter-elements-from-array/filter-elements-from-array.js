/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // return arr.filter(fn);

    // const result = [];
    // arr.map((x, i) => {
    //     if(fn(x, i)) {
    //         result.push(x);
    //     }
    // });
    // return result;

    const result = [];

    // arr.forEach((x, i) => {
    //     if(fn(x, i)) {
    //         result.push(x);
    //     }
    // });

    // let i = 0;

    // for(const x of arr) {
    //     if(fn(x, i)) {
    //         result.push(x);
    //     } i++;
    // }

    for(let i=0; i<arr.length; i++) {
        if(fn(arr[i], i)) {
            result.push(arr[i]);
        }
    }
    
    return result;
};