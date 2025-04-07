// get coordinates is the most important part here

class Solution {
public:
    pair<int, int> getCoordinates(int num, int n) {
        int r = (num - 1) / n; // Row number from the top (0-indexed), assuming
                               // normal left-to-right layout
        int c = (num - 1) % n; // Column number from the left (0-indexed),
                               // assuming normal left-to-right layout

        int row = n - 1 - r; // Convert row from top-based to bottom-based
                             // (since board starts at bottom)

        // Adjust column based on zigzag pattern:
        // If the row (from bottom) is an odd level, reverse column direction
        // (right-to-left)
        int col = (r % 2 == 1) ? (n - 1 - c) : c;

        return {row, col}; // Return final 2D board coordinates
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> q; // num, lvl
        int n = board.size();
        vector<bool> vis(n * n + 1, false);
        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            if (curr == n * n)
                return moves;

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n)
                    continue;

                auto pos = getCoordinates(next, n);
                int row = pos.first, col = pos.second;
                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
