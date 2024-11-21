/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return ""; // Return an empty string if the tree is empty
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL)
                s.append("#,"); // Append '#' for null nodes
            else
                s.append(to_string(curr->val) + ','); // Append the node's value

            if (curr != NULL) {
                q.push(curr->left);  // Push left child to queue
                q.push(curr->right); // Push right child to queue
            }
        }
        cout << s << endl; // Debug: Print the serialized string
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL; // Return NULL if the data string is empty
        stringstream s(data); // Use stringstream to split data
        string str;

        getline(s, str, ','); // Extract the root value
        TreeNode* root = new TreeNode(stoi(str)); // Create the root node
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Deserialize the left child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    curr->left = NULL; // If the value is "#", set the left child as NULL
                } else {
                    TreeNode* leftNode = new TreeNode(stoi(str)); // Create the left node
                    curr->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Deserialize the right child
            if (getline(s, str, ',')) {
                if (str == "#") {
                    curr->right = NULL; // If the value is "#", set the right child as NULL
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(str)); // Create the right node
                    curr->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root; // Return the root of the deserialized tree
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

