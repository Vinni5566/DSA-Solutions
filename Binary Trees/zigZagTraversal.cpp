#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> result;

        if(!root) return result;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {

            int levelsize = q.size();
            vector<int> level(levelsize);

            for(int i = 0; i < levelsize; i++) {
                Node* node = q.front() ;
                q.pop();

                if(leftToRight) {
                    level[i] = node->data;
                } else {
                    level[levelsize-1-i] = node->data;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            for(int i = 0; i < level.size(); i++) {
                result.push_back(level[i]);
            }
            
            leftToRight = !leftToRight;
        }

        return result;
    }
};