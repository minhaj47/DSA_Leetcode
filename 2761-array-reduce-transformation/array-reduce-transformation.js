/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    // return nums.reduce((result, num) => {
    //     return fn(result, num);
    // }, init);

    // nums.map((num) => {
    //     init = fn(init, num);
    // });

    // for(let i=0; i<nums.length; i++) {
    //     init = fn(init, nums[i]);
    // }

    for(x of nums) {
        init = fn(init, x);
    }

    return init;
};