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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int cnt = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size=q.size();
            int minimal=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int currind=q.front().second-minimal;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0)first=currind;
                if(i==size-1)last=currind;

                if(node->left){
                    q.push({node->left,(long long)currind*2+1});

                }
                if(node->right){
                    q.push({node->right,(long long)currind*2+2});

                }
                cnt=max(cnt,last-first+1);
            }
        }
        return cnt;
       
         
        
    }
};