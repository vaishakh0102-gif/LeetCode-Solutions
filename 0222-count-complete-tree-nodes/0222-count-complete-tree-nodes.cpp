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
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int ls=findHleft(root);
        int rs=findHright(root);

        if(ls==rs)return( 1<<rs )-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
       
    }

    int findHleft(TreeNode* node){
        int cnt1=0;
        if(node==nullptr)return 0;
        
        while(node!=nullptr){
            cnt1++;
            node=node->left;
        }
        return cnt1;

    }
    int findHright(TreeNode* node){
        int cnt2=0;
        if(node==nullptr)return 0;
        
        while(node!=nullptr){
            cnt2++;
            node=node->right;
        }
        return cnt2;

    }

};