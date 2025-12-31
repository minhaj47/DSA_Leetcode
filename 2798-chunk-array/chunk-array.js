/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    // return _.chunk(arr, size);

    const result = [];
    let temp = [];
    for(let i=0; i<arr.length; i++) {
        if(i%size == 0 && i!=0) {
            result.push(temp);
            temp = [];
        }
        temp.push(arr[i]);
    }
    if(temp.length)result.push(temp);
    return result;
};
