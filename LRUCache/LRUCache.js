/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.cap = capacity;
    this.cache = new Map();
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let cache = this.cache;
    if (cache.has(key))
    {
        let val = cache.get(key);
        cache.delete(key);
        cache.set(key, val);
        return val;
    }
    else
    {
        return -1;
    }
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.cache.has(key))
    {
        this.cache.delete(key);
    }
    else
    {
        if (this.cache.size == this.cap)
        {
            this.cache.delete(this.cache.keys().next().value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key, value)
 */
