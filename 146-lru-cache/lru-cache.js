class LRUCache {
    constructor(capacity) {
        this.cache = new Map(); // map mantains insertion order
        this.capacity = capacity;
    }

    get(key) {
        if(!this.cache.has(key)) return -1;
        const v = this.cache.get(key);
        this.cache.delete(key);
        this.cache.set(key, v);
        return v;
    }

    put(key, value) {
        if(this.cache.has(key)){
            this.cache.delete(key);
        }
        this.cache.set(key, value);
        if(this.capacity < this.cache.size) {
            const lru = this.cache.keys().next().value;  // oldest inserted key
            this.cache.delete(lru);
        }
    }
 
}