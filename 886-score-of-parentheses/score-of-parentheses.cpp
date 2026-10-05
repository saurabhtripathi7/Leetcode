class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '(') {
                // Going one level deeper means that anything inside
                // this pair will eventually get multiplied by 2.
                depth++;
            }
            else {
                // We are closing the current pair, so move back
                // to the depth of its parent.
                depth--;

                // "()": base score is 1.
                //
                // Instead of waiting for all inner scores and then
                // calculating 2 * innerScore for every outer pair,
                // we directly give each "()" its final contribution.
                //
                // Every enclosing pair doubles its score:
                // depth 0 -> 1
                // depth 1 -> 2
                // depth 2 -> 4
                // ...
                //
                // Therefore, a "()" at depth d contributes 2^d.
                if (s[i - 1] == '(') {
                    ans += (1 << depth);
                }
            }
        }
        return ans;
    }
};