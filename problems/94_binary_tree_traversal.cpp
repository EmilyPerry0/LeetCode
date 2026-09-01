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
    vector<int> inorderTraversal(TreeNode* root) {
        // go all the way down the left until we can't.
        // then hit the parent, then the right. then go up
        if(root == nullptr){
            vector<int> emptyVector;
            return emptyVector;
        }

        vector<int> left;
        vector<int> right;

        left = inorderTraversal(root->left);
        right = inorderTraversal(root->right);

        left.push_back(root->val);
        // Source - https://stackoverflow.com/a/201729
        // Posted by Robert Gamble
        // Retrieved 2026-09-01, License - CC BY-SA 2.5
        left.insert( left.end(), right.begin(), right.end() );
        return left;
    }

};