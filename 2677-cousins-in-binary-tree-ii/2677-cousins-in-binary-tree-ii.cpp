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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> v;
        int lvl=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long tot=0;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                tot+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            v.push_back(tot);
        }
        root->val=0;
        q.push(root);
        while(!q.empty()){
            lvl++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && cur->right){
                    int s=cur->left->val + cur->right->val;
                    cur->left->val=v[lvl]-s;
                    cur->right->val=v[lvl]-s;
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else if(cur->left){
                    int s=cur->left->val;
                    cur->left->val=v[lvl]-s;
                    q.push(cur->left);
                }
                else if(cur->right){
                    int s=cur->right->val;
                    cur->right->val=v[lvl]-s;
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};