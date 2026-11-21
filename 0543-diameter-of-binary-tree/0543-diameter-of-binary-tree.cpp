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
      int maxDepth(TreeNode* root,int& count) {
        
        if(root==nullptr)return 0;
        
        int ls=maxDepth(root->left,count);
        int rs=maxDepth(root->right,count);
        count= max(count,ls+rs);
        return 1+max(ls,rs);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt=0;
        maxDepth(root,cnt);
        return cnt;
        
    }
};