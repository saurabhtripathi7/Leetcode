/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
        if(!root) return result;
        
        map<int, map<int, multiset<int > > > nodes;
        queue<pair<TreeNode*, pair<int,int> > >Q;
        Q.push({root, {0,0}});

        while(!Q.empty()){
            pair<TreeNode*, pair<int,int>> curr = Q.front();
            Q.pop();
            
            TreeNode* frontNode = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            nodes[x][y].insert(frontNode->val);

            if(frontNode->left){
                Q.push({frontNode->left, {x-1, y+1}});
            }
            if(frontNode->right){
                Q.push({frontNode->right, {x+1, y+1}});
            }
        }

        // Building the result from map
        
        for(auto verticalLines : nodes){
            vector<int>col;
            for(auto lvlData : verticalLines.second){
                col.insert(col.end(), lvlData.second.begin(), lvlData.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
