#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
			vector<vector<int>> res(3);
            
            inorder(root, res);
            preorder(root, res);
            postorder(root, res);

            return res;
		}

        void preorder(TreeNode* root, vector<vector<int>>& res) {
            
            if(root == NULL) return;

            res[1].push_back(root->data);
            preorder(root->left, res);
            preorder(root->right, res);
        }

        void inorder(TreeNode* root, vector<vector<int>>& res) {
            
            if(root == NULL) return;
            
            inorder(root->left, res);
            res[0].push_back(root->data);
            inorder(root->right, res);
        }

        void postorder(TreeNode* root, vector<vector<int>>& res) {
            
            if(root == NULL) return;
            
            postorder(root->left, res);
            postorder(root->right, res);
            res[2].push_back(root->data);
        }

        
};