var isValidSudoku = function(board) {

    let region = new Array(9);
    let columns = new Array(9);
    let rows = new Array(9);
    for (let k = 0; k < 9; k++)
    {
        region[k] = new Map();
	columns[k] = new Map();
	rows[k] = new Map();
    }

    // iterate the board to test
    
    for (let i= 0; i < 9; i++)
    {
        for (let j = 0; j < 9; j++)
	{
	    if (board[i][j] != '.') {
		// check column
		if (columns[j].has(board[i][j])) return false;
		columns[j].set(board[i][j], 1);
		
		// check row
		if (rows[i].has(board[i][j])) return false;
		rows[i].set(board[i][j], 1);

		let region_idx =Math.floor(i/3) * 3 + Math.floor(j /3);
		if (region[region_idx].has(board[i][j])) return false;
		region[region_idx].set(board[i][j], 1);
	    }
        }
    }
    return true;
};


var test = [["7",".",".",".","4",".",".",".","."],[".",".",".","8","6","5",".",".","."],[".","1",".","2",".",".",".",".","."],[".",".",".",".",".","9",".",".","."],[".",".",".",".","5",".","5",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".","2",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]];

console.log(isValidSudoku(test));
