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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            
            int size=q.size();
            vector<int>ls(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                int index=(flag==0)? i:size-1-i;
                ls[index]=node->val;

                if(node->left!=nullptr)q.push(node->left);
                if(node->right!=nullptr)q.push(node->right);


            }
            flag=!flag;
            ans.push_back(ls);

            
        }
        return ans;

      
        
    }
};