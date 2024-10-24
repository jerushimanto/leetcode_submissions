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
    bool find(TreeNode* r1, TreeNode* r2){
        //cout<<1<<" ";
        if(r1==NULL) return(r2==NULL);
        
        if(r2==NULL) return 0;
        else if(r1->val!=r2->val) return 0;
        bool res1=find(r1->left,r2->left)&&find(r1->right,r2->right),
        res2=find(r1->left,r2->right)&&find(r1->right,r2->left);
        return res1||res2;
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return find(root1,root2);
    }
};