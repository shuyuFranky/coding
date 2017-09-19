/**
*   二叉树的操作
*/
#include <iostream>

using namespace std;

struct node {
    node * left;
    node * right;
    int var;
    node () {}
    node (int v):var(v) {}
}

void destroyTree(node * root) {
    if (root == NULL) return ;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
    return;
}

node * getNode(node * root, int var) {
    if (root == NULL) return NULL;
    if (root->var == var) return root;
    node * tmp;
    tmp = getNode(root->left,var);
    if (tmp != NULL) return tmp;
    tmp = getNode(root->right,var);
    return tmp;
}

void printNode(node * root, int var) {
    node * cn = getNode(root, var);
    while(cn->left != NULL)
        cn = cn->left;
    cout<<cn->var<<endl;
    return ;
}

node * getParent(node * root, int var) {
    if (root->left != NULL && root->left->var == var) return root;
    if (root->right != NULL && root->right->var == var) return root; 
    node * tmp = getParent(root->left);
    if (tmp != NULL) return tmp;
    tmp = getParent(root->right);
    return tmp;
}

void swapNode(node * root, int x, int y) {
    node * X = getParent(root, x);
    node * Y = getParent(root, y);
    node * tmp;
    if (X->left->var == x) {
        if (Y->left->var == y) {
            tmp = X->left;
            X->left = Y->left;
            Y->left = tmp;
        } else {
            tmp = X->left;
            X->left = Y->right;
            Y->right = tmp; 
        }   
    } else {
        if (Y->left->var == y) {
            tmp = X->right;
            X->right = Y->left;
            Y->left = tmp;
        } else {
            tmp = X->right;
            X->right = Y->right;
            Y->right = tmp; 
        } 
    }
}

int main() {
    int T;
    cin>>T;
    int n, m;
    int op,arg1,arg2;
    int pa, left, right;
    while(T--) {
        cin>>n>>m;
        node * root;
        cin>>pa>>left>>right;
        root = new node(pa);
        root->left = new node(left);
        root->right = new node(right);
        for (int i = 1; i<n; i++) {
            cin>>pa>>left>>right;
            node * parent = getNode(root, pa);
            node * ln = new node(left);
            node * rn = new node(right);
            parent->left = ln;
            parent->right = rn; 
        }
        for (int i = 0; i<m; i++) {
            cin>>op;
            if (op == 1) {
                cin>>arg1>>arg2;
                swapNode(root,arg1,arg2);
            } else if (op == 2) {
                cin>>arg1;
                printNode(root,arg1);
            } else {
                return 0;
            }
        }
        destroyTree(root);
    }
    
}