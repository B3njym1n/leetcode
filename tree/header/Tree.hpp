#ifndef _TREE_HEADER
#define _TREE_HEADER
template<typename T>
struct TreeNode {
    T val;
    TreeNode &left;
    TreeNode &right;
    TreeNode(T v) : val{v}, left(NULL), right(NULL) {}
};

#endif