#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) return -1;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return max(leftHeight, rightHeight)+1;
        
    }
};