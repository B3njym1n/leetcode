#include <iostream>
#include <vector>
#include <stack>
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

class Solution {
public:
    void LevelTraverse(TreeNode<int> &root) {

        vector<vector<TreeNode<int>&>> Levels;
        stack<TreeNode<int>&> stack;

        TreeNode<int> &curr = root;
        int level = 0;
        Levels.push_back(vector<TreeNode<int>&>());
        Levels[level].push_back(curr);
        if  (curr.left != 0) {
            stack.push(curr.left);
        }
        if (curr.right != 0) {
            stack.push(curr.right);
        }
        while( true ) {
            
            level++;
            Levels.push_back(vector<TreeNode<int>&>());
            curr = stack.top();
            Levels[level].push_back(curr);
            
            stack.pop();
            
            for (TreeNode<int>& node : Levels[level]) {
                TreeNode<int> &curr = node;
                if  (curr.left != 0) {
                    stack.push(curr.left);
                }
                if (curr.right != 0) {
                    stack.push(curr.right);
                }       
            }
            if (stack.size == 0) return;
        }
        
        cout << '[';
        for (int i = 0; i < level; i++) {
            cout << '\t' << '[';
            for ( TreeNode<int>& node : Levels[i]) {
                cout << " " << node.val << ',';
            }
            cout << ']' << endl;
        }
        cout << ']' << endl;
    }
};

int main () {
    Solution s;
    TreeNode<int> root(3);
    root.left = TreeNode(9);
    root.right = TreeNode(20);
    
    root.right.left = new TreeNode(15);
    root.right.left = new TreeNode(7);
    s.LevelTraverse(root);
    return 0;
}