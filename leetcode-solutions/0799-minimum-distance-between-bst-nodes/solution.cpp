class Solution {
public:
void diff(TreeNode* root ,vector<int>& arr)
{
    if(root==NULL)
    {
        return ;
    }
    diff(root->left,arr);
    arr.push_back(root->val);
    diff(root->right,arr);
}
    int minDiffInBST(TreeNode* root) 
    {
        vector<int>arr;
        diff(root,arr);
        int min1,min2=INT_MAX;
        for(int i =0;i<arr.size()-1;i++)
        {
            min1=arr[i+1]-arr[i];
            if(min1<=min2)
            {
                min2=min1;
            }
        }
        return min2 ;
        
    }
};
