#include <bits/stdc++.h>
using namespace std;

struct Node {
    // prefix run
    char pref_c;
    int pref_len;
    // suffix run
    char suff_c;
    int suff_len;
    // best run inside this segment
    int best;
    // length of the segment itself
    int len;
};

class SegTree {
    int n;
    vector<Node> tree;
    string s;

    // Merge two child nodes into parent
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;

        // Prefix
        res.pref_c = left.pref_c;
        res.pref_len = left.pref_len;
        // If entire left is same char as right's prefix, extend
        if (left.pref_len == left.len && left.pref_c == right.pref_c) {
            res.pref_len += right.pref_len;
        }

        // Suffix
        res.suff_c = right.suff_c;
        res.suff_len = right.suff_len;
        // If entire right is same char as left's suffix, extend
        if (right.suff_len == right.len && right.suff_c == left.suff_c) {
            res.suff_len += left.suff_len;
        }

        // Best run: max of children, or cross-boundary merge
        res.best = max(left.best, right.best);
        if (left.suff_c == right.pref_c) {
            res.best = max(res.best, left.suff_len + right.pref_len);
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            char c = s[l];
            tree[idx] = {c, 1, c, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            tree[idx] = {c, 1, c, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx * 2, l, mid, pos, c);
        else            update(idx * 2 + 1, mid + 1, r, pos, c);
        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

public:
    SegTree(const string& str) {
        s = str;
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void pointUpdate(int pos, char c) {
        update(1, 0, n - 1, pos, c);
    }

    int getMaxRun() const {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryCharacters.size();
        SegTree seg(s);
        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; ++i) {
            seg.pointUpdate(queryIndices[i], queryCharacters[i]);
            ans.push_back(seg.getMaxRun());
        }
        return ans;
    }
};