class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        // Check if 'd' already exists in the same column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == d) // found in column
                return false;

            if (board[row][i] == d) // found in row
                return false;
        }

        // Find the starting index of the 3x3 subgrid
        int start_i = (row / 3) * 3; // top-left row of subgrid
        int start_j = (col / 3) * 3; // top-left col of subgrid

        // Check the entire 3x3 subgrid
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[start_i + k][start_j + l] == d) // found in subgrid
                    return false;
            }
        }

        // If no conflicts → valid placement
        return true;
    }

    // Recursive backtracking Sudoku solver
    // Worst-case complexity ~ O(9^81), since for each empty cell we can try up
    // to 9 possibilities But pruning with isValid makes it much faster in
    // practice

    bool solve(vector<vector<char>>& board) {
        // Traverse the 9x9 board
        for (int i = 0; i < 9; i++) {     // iterate over rows
            for (int j = 0; j < 9; j++) { // iterate over columns

                // If an empty cell is found
                if (board[i][j] == '.') {

                    // Try placing digits '1' to '9'
                    for (char d = '1'; d <= '9'; d++) {

                        // Check if placing digit 'd' here is valid
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d; // place digit

                            // Recursively try to solve the rest of the board
                            if (solve(board) == true) {
                                return true; // solution found → stop recursion
                            }

                            // If not successful → backtrack
                            board[i][j] = '.';
                        }
                    }

                    // If no digit 1–9 works here, this path is invalid
                    return false;
                }
            }
        }

        // If no empty cell was found, board is completely solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
