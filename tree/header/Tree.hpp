#ifndef _TREE_HEADER
#define _TREE_HEADER
/* template<typename T> */
struct TreeNode {
    /* T val; */
    int val;
    TreeNode *left;
    TreeNode *right;
    /* TreeNode(T v) : val{v}, left(nullptr), right(nullptr) {} */
    TreeNode(int v) : val{v}, left(nullptr), right(nullptr) {}
};

#endif