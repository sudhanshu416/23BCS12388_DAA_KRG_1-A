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
 #define pii pair<int,int>
class Solution {
public:
    void dfs(TreeNode* root, int col, map<int,vector<pii>> &m, int level){
        if(!root) return;
        m[col].push_back({level, root->val});
        dfs(root->left, col-1, m,level++);
        dfs(root->right, col+1, m,level);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pii>> m;
        dfs(root, 0,m,0);
        vector<vector<int>> res(m.size());
        int k=0;
        for(auto i: m){
            sort(i.second.begin(), i.second.end());
            for(auto it: i.second){
                res[k].push_back(it.second);
            }
            k++;
        }
        return res;
    }
};
