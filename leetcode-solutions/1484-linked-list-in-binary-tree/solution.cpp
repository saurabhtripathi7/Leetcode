class Solution {
public:
    bool checker(TreeNode* treeHead, ListNode* head) {
        if (!head) return true; 
        if (!treeHead) return false; 

        if (treeHead->val != head->val) return false;

        return checker(treeHead->left, head->next) || checker(treeHead->right, head->next);
    }

    bool searchHead(TreeNode* root, ListNode* head) {
        if (!root) return false;

        if (root->val == head->val && checker(root, head)) {
            return true;
        }

        return searchHead(root->left, head) || searchHead(root->right, head);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true; 
        if (!root) return false; 

        if (searchHead(root, head)) return true;
        return false;
    }

};

