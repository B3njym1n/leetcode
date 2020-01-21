/**
Compare and update the inventory stored in a 2D array against a second 2D array of a fresh delivery. Update the current existing inventory item quantities (in arr1). If an item cannot be found, add the new item and quantity into the inventory array. The returned inventory array should be in alphabetical order by item.
 **/

function compare(a, b) {
    let comparison = 0;
    if ( a[1][0] > b[1][0]) {
        comparison = 1;
    } else if (a[1][0] < b[1][0]) {
        comparison = -1;
    }
    return comparison;
}

function updateInventory(arr1, arr2) {
    for (i = 0; i < arr2.length; i++) {
        let k = -1;
        for (j = 0; j < arr1.length; j++) {
            if (arr1[j][1] == arr2[i][1])
                k = j;
        }
        if (k != -1) {
            arr1[k][0] = arr2[i][0] + arr1[k][0];
        } else {
            arr1.push(arr2[i]);
        }
    }
    arr1.sort(compare);
    return arr1;
}

var curInv = [[21, "Bowling Ball"], [2, "Dirty Sock"], [1, "Hair Pin"], [5, "Microphone"]];

var newEnv = [[2, "Hair Pin"], [3, "Half-Eaten Apple"], [67, "Bowling Ball"], [7, "Toothpaste"]];

updateInventory(curInv, newEnv);
console.log(curInv);
