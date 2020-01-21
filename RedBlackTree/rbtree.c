#include <stdio.h>
#include <stdlib.h>

#define MAX 32
#define KRED "\x1B[31m"
#define KBLK "\x1B[30m"
#define KGRN "\x1B[32m"
#define KNRM "\x1B[0m"

typedef struct rbnode *node;

node insert(int value, node root, node p, node gp, node ggp);
node new_node(int value);
void rebalance(node root, node p, node gp, node ggp);
void disp(node t, int lvl);

/**
 * define 0 black 1 red 
 */
struct rbnode {
    int value;
    node left;
    node right;
    int color;
} nilnode = { -10000, &nilnode, &nilnode, 0}, *nil = &nilnode;

node new_node(int value) {
    node new_ = malloc(sizeof(struct rbnode));
    new_->value = value;
    new_->left = nil;
    new_->right = nil;
    new_->color = 1;
    return new_;
}

/**
 * dir 0 left 1 right
 */
node rotate(node parent, int dir) {
    node child;
    if (dir == 0) {
        child = parent->left;
        parent->left = child->right;
        child->right = parent;
    } else {
        child = parent->right;
        parent->right = child->left;
        child->left = parent;
    }
    return child;
}

void rebalance(node root, node p, node gp, node ggp) {
    
}

node insert(int value, node root, node p, node gp, node ggp) {
    if (root != nil) {
        if (root->value > value) {
            ggp = gp;
            gp = p;
            p = root;
            root = root->left;
            insert(value, root, p, gp, ggp);
        } else if (root->value < value) {
            ggp = gp;
            gp = p;
            p = root;
            root = root->right;
            insert (value, root, p, gp, ggp);
        }
    } else {
        root = new_node(value);
        root->color = 1;
        if (p->value > root->value) p->left = root;
        if (p->value < root->value) p->right = root;
        rebalance(root, p, gp, ggp);
        return root;
    }
}

void disp(node t, int lvl) {
    if (t == nil) return;
    char *space = "    ";
    disp(t->left, lvl+1);
    for (int j = 0; j < lvl; j++) {
        printf( "%s" KNRM, space);
    }
    if (t->color == 0) {
        printf(KBLK "%d\n" KNRM, t->value);
    } else {
        printf(KRED "%d\n" KNRM, t->value);
    }
    
    disp(t->right, lvl+1);
}


int main() {
    node root = new_node(-1);
    root->color = 0;
    node p = root, gp = root ,ggp = root;
    for (int i = 0; i < MAX; i++) {
        insert(i, root, p, gp, ggp);
    }

    disp(root, 0);
    return 0;
}
