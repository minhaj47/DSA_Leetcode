/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = (functions) => {
    // const promises = functions.map((fn) => fn());
    // return Promise.all(promises);

    return new Promise((resolve, reject) => {
        const results = [];
        let completed = 0;

        functions.forEach((fn, i) => {
            fn()
                .then((value) => {
                    completed++;
                    results[i] = value;
                    if(completed == functions.length) {
                        resolve(results);
                    }
                })
                .catch((err) => {
                    reject(err);
                });
        });

        if(functions.length === 0) resolve([]);
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */