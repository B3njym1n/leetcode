/**
 * @param {number} n
 * @return {string[][]}
 */
function swap(array, m, n)
{
    [array[m], array[n]] = [array[n], array[m]];
}

function permutation(array, i, size, result)
{
    if (i + 1 == size)
    {
        // end
        let re = [...array];
        result.push(re);
        return;
    }
    else
    {
        for ( let j = i; j < size; j++)
        {
            swap(array, i, j);
            permutation(array, i + 1, size, result);
            swap(array, i, j);
        }
    }
}

function validate(array, size) {
    let l = size;
    // need a double loop to check all the combination
    for (let i = 0; i < l - 1; i++)
    {
        for (let j = i+1; j < l;j++)
        {
            let slope = (array[j] - array[i]) / (j - i);
            if (slope == 1 || slope == -1) {
                return false;
            }
        }
    }
    return true;
}

var solveNQueens = function(n) {
    let result = [];
    let result2 = [];
    let result3 = [];
    let comb = [];
    for (let i = 0; i < n; i++)
    {
        comb.push(i);
    }
    permutation(comb, 0, n, result);
    console.log(result);
    for(let m = 0; m < result.length; m++)
    {
        let row = result[m];
        if (validate(row, n)) result2.push(row);
    }

    console.log(result2);
    for (let m = 0; m < result2.length; m++)
    {
        let se = result2[m];
        let re = new Array(n);
        for (let j = 0; j < n; j++)
        {
            re[j] = new Array(n);
            for ( let l = 0; l < n; l++)
            {
                re[j][l] = ".";
            }
        }
        
        for (let k = 0; k < se.length; k++)
        {
            re[k][se[k]] = "Q";
        }
        result3.push(re);
    }
    console.log(result3);
    return result3;
};

solveNQueens(4);
