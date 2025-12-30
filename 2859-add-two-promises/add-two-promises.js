/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // const [a, b] = await Promise.all([promise1, promise2]);
    // return a + b;
    const values = await Promise.all([promise1, promise2]);
    return values.reduce((total, val) => total + val, 0);
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */