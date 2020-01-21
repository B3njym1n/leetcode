var backtracking = function(result, ori, count, depth, mem)
{
    if ( depth == 0) {
        let row = [...mem];
        result.push(row);
        return;
    }
    for (let i = count; i < ori.length - depth + 1; i++) {
        mem.push(ori[i]);
        backtracking(result, ori.slice(i+1, ori.length), count + 1, depth-1, mem);
        mem.pop();
    }
}

var combine = function(n, k) {
    let result = [];
    let original = new Array(n);
    // initial
    for (let i = 0 ; i < n; i++)
    {
        original[i] = i + 1;
    }
    if (n == k) {
        result.push(original);
        return result;
    }
    backtracking(result, original, 0, k, []);
    return result;
};

console.log(combine(4,3));
