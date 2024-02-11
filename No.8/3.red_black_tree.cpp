#include <bits/stdc++.h>
#include <tools.hpp>
#define NIL (&RedBlackTree::mNIL)
#define K(n) (n->mKey)
#define L(n) (n->mLeft)
#define R(n) (n->mRight)
#define C(n) (n->mColor)
using namespace std;
const char* str[3] = {
    "red",
    "black",
    "double black"
};
class RedBlackTree {
private:
    enum Color {
        red,black,dblack
    };
    class TreeNode {
    public:
        int mKey;
        Color mColor;
        TreeNode *mLeft,*mRight;
        TreeNode():mKey(0),mColor(red),mLeft(NIL),mRight(NIL) {}
        TreeNode(int key):mKey(key),mColor(red),mLeft(NIL),mRight(NIL) {}
        TreeNode(int key,Color c):mKey(key),mColor(c),mLeft(NIL),mRight(NIL) {}
        ~TreeNode() {
            if(this == NIL) return;
            delete mLeft;
            delete mRight;
        }
        void *operator new(size_t size) {
            return malloc(size);
        }
        void operator delete(void *ptr) {
            if(ptr == NIL) return;
            free(ptr);
        }
    };
    inline bool hasRedNode(TreeNode *root) {
        return C(L(root)) == red || C(R(root)) == red;
    }
    TreeNode *insert_maintain(TreeNode *root) {
        int flag = 0;
        if(C(L(root)) == red && hasRedNode(L(root))) flag = 1;
        if(C(R(root)) == red && hasRedNode(R(root))) flag = 2;
        if(flag == 0) return root;
        if(C(L(root)) == red && C(R(root)) == red)
            goto upRedMaintain;
        if(flag == 1) {
            if(C(R(L(root))) == red) {
                L(root) = leftRotate(L(root));
            }
            root = rightRotate(root);
        } else {
            if(C(L(R(root))) == red) {
                R(root) = rightRotate(R(root));
            }
            root = leftRotate(root);
        }
    upRedMaintain:
        C(root) = red;
        C(L(root)) = C(R(root)) = black;
        return root;
    }
    TreeNode *leftRotate(TreeNode *root) {
        TreeNode *ptr = root->mRight;
        root->mRight = ptr->mLeft;
        ptr->mLeft = root;
        return ptr;
    }
    TreeNode *rightRotate(TreeNode *root) {
        TreeNode *ptr = root->mLeft;
        root->mLeft = ptr->mRight;
        ptr->mRight = root;
        return ptr;
    }
    TreeNode *insertT(TreeNode *root,int key) {
        if(root == NIL) return new TreeNode(key);
        if(K(root) == key) return root;
        if(key < K(root)) L(root) = insertT(L(root),key);
        else R(root) = insertT(R(root),key);
        return insert_maintain(root);
    }
    void outputT(TreeNode *root) {
        if(root == NIL) return;
        printf("(%s| %d, %d, %d)\n",str[C(root)],K(root),K(L(root)),K(R(root)));
        outputT(L(root));
        outputT(R(root));
    }
    static TreeNode mNIL;
    TreeNode* mRoot;
public:
    RedBlackTree():mRoot(NIL) {}
    ~RedBlackTree() {
        delete mRoot;
    }
    void insert(int key) {
        mRoot = insertT(mRoot,key);
        C(mRoot) = black;
    }
    void output() {
        outputT(mRoot);
    }
};
RedBlackTree::TreeNode RedBlackTree::mNIL{-1,black};
int main() {
#define MAX_OP 10
    RedBlackTree* t = new RedBlackTree;
    for(int i = 0;i < MAX_OP;i++) {
        int x = rand() % 100;
        printf("insert %d to RedBlackTree : \n",x);
        t->insert(x);
        t->output();
    }
    t->output();
    return 0;
}