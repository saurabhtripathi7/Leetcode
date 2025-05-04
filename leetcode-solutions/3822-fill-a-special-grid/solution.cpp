class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        return build(N);
    }

private:
    vector<vector<int>> build(int N) {
        if (N == 0) {
            return {{0}};
        }
        auto small = build(N - 1);
        int M = 1 << (N - 1);  // 2^(N-1)
        int quadSize = M * M;     
        vector<vector<int>> big(2 * M, vector<int>(2 * M)); //2^M * 2^M

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                int v = small[i][j];
                big[i][j + M] = v + 0 * quadSize;  // TR
                big[i + M][j + M] = v + 1 * quadSize;  // BR
                big[i + M][j] = v + 2 * quadSize;  // BR
                big[i][j] = v + 3 * quadSize;  // TL
            }
        }
        return big;
    }
};

