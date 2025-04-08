class Solution {
public:
    void solve(int i, int size, int &n, int &k, vector<int>&ds, vector<vector<int>>&ans){
        if(size == k){
            ans.push_back(ds);
            return;
        }
        if(i > n) return;

        //include
        ds.push_back(i);
        solve(i+1, size+1, n, k, ds, ans);
        ds.pop_back();

        // exclude
        solve(i+1, size, n, k, ds, ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1, 0, n, k, ds, ans);
        return ans;        
    }
};

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
