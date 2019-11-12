#include <iostream>
#include <vector>
#include "..\header\Tree.hpp"
using namespace std;

/* Given a binary tree, return the level order traversal of its nodes' values.
For example: Given binary tree { 3, 9, 20, #, #, 15, 7 }
     3
    / \
    9 20
      / \
     15 7
return its level order traversal as:
[
    [3],
    [9,20],
    [15,7]
] */
typedef TreeNode* tn;

class Solution {
public:
    void LevelTraverse(tn root) {

        vector<vector<tn>> Levels;
        int level = 0;
        _Recur(root, level, Levels);

        cout << '[';
        for (int i = 0; i < level; i++) {
            cout << '\t' << '[';
            for ( tn node : Levels[i]) {
                cout << " " << node->val << ',';
            }
            cout << ']' << endl;
        }
        cout << ']' << endl;
    }

    void _Recur(tn root, int& level,vector<vector<tn>> &Levels) {
        if (root = nullptr) return;
        if ( level - Levels.size() == 0 ) {
            Levels.push_back(vector<tn>());
        }
        level++;
        _Recur(root->left, level, Levels);
        _Recur(root->right, level, Levels);
    }
};

int main () {
    Solution s;
    tn root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    
    root->right->left = new TreeNode(15);
    root->right->left = new TreeNode(7);
    s.LevelTraverse(root);
    return 0;
}