/**
Create a function that takes two or more arrays and returns an array of the
symmetric difference  (△ or ⊕) of the provided arrays.

Given two sets (for example set A = {1, 2, 3} and set B = {2, 3, 4}), the 
mathematical term "symmetric difference" of two sets is the set of elements 
which are in either of the two sets, but not in both (A △ B = C = {1, 4}). 
For every additional symmetric difference you take (say on a set D = {2, 3})
, you should get the set with elements which are in either of the two the 
sets but not both (C △ D = {1, 4} △ {2, 3} = {1, 2, 3, 4}). The resulting 
array must contain only unique values (no duplicates).
**/

function unique(arg) {
    res = [];
    arg.map(e => { if (res.indexOf(e) == -1) res.push(e) });
    return res;
}

function sym(...args) {
    if (args.length == 2) {
        result = [];
        // result.concat(args[0].filter( e => args[1].indexOf(e) == -1)); 
        let t1 = args[0].filter( e => args[1].indexOf(e) == -1); 
        // result.concat(args[1].filter( e => args[0].indexOf(e) == -1)); 
        let t2 = args[1].filter( e => args[0].indexOf(e) == -1); 
        result = result.concat(t1);
        result = result.concat(t2);
        // remove dulicate elements in results;
        result = unique(result);
        return result;
    } else {
        //let arg1 = args[0];
        //let arg2 = args.slice(1, args.length);
        //return sym(arg1, sym(...arg2));
        return sym(args[0], sym(...args.splice(1, args.length)));
    }
}

console.log(sym([1, 2, 5], [2, 3, 5], [3, 4, 5]));
