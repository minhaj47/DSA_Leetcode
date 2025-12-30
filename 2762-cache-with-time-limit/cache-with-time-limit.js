var TimeLimitedCache = function() {
    this.cache = {};
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let isFound = false;
    if(this.cache[key]) {
        clearTimeout(this.cache[key].timeoutId);
        isFound = true;
    }
    const timeoutId = setTimeout(() => {
        delete this.cache[key];
    }, duration);
    this.cache[key] = {
        value, 
        timeoutId,
    };
    return isFound;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if(!this.cache[key]) return -1;
    return this.cache[key].value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let count = 0;
    for(i in this.cache) {
        count++;
    }
    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */