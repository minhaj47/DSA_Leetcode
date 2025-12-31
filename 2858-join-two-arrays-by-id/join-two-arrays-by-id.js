/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    // we should return array 
    // using object like 1: {id:"1", ......} for approach 
    // later return Object.values;

    const combinedArray = [...arr1, ...arr2];
    const merged = {};   // 1: {id:"1", ......}

    combinedArray.forEach((obj) => {
        const id = obj.id;
        if(!merged[id]){
            merged[id] = obj;
        } 
        else {
            merged[id] = {...merged[id], ...obj};
        }
    });

    return Object.values(merged);
};