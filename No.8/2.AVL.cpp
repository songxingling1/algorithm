#include <bits/stdc++.h>
#include <tools.hpp>
#define NIL (&(AVLTree::__NIL))
#define H(n) (n->mH)
#define L(n) (n->mLeft)
#define R(n) (n->mRight)
#define K(n) (n->mKey)
using namespace std;
const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"
};
class AVLTree {
private:
    class TreeNode {
    public:
        int mKey,mH;
        TreeNode *mLeft,*mRight;
        TreeNode():
                mKey(0),mH(1),mLeft(NIL),mRight(NIL) {}
        TreeNode(int key):
                mKey(key),mH(1),mLeft(NIL),mRight(NIL) {}
        ~TreeNode() {
            if(this == NIL) return;
            delete mLeft;
            delete mRight;
        }
        void* operator new(size_t size) {
            return malloc(size);
        }
        void operator delete(void* ptr) {
            if(ptr == NIL) return;
            free(ptr);
        }
    };
    TreeNode* mRoot;
    static TreeNode __NIL;
    inline void updateHeight(TreeNode *root) {
        H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1 ;
    }
    TreeNode *left_rotate(TreeNode *root) {
        printf("left rotate : %d\n",K(root));
        TreeNode *t = R(root);
        R(root) = L(t);
        L(t) = root;
        updateHeight(root);
        updateHeight(t);
        return t;
    }
    TreeNode *right_rotate(TreeNode *root) {
        printf("right rotate : %d\n",K(root));
        TreeNode *t = L(root);
        L(root) = R(t);
        R(t) = root;
        updateHeight(root);
        updateHeight(t);
        return t;
    }
    TreeNode *maintain(TreeNode *root) {
        if(abs(H(L(root)) - H(R(root))) <= 1) return root;
        int type = 0;
        if(H(L(root)) > H(R(root))) {
            if(H(R(L(root))) > H(L(L(root)))) {
                L(root) = left_rotate(L(root));
                type++;
            }
            root = right_rotate(root);
            type++;
        } else {
            type = 2;
            if(H(L(R(root))) > H(R(R(root)))) {
                R(root) = right_rotate(R(root));
                type++;
            }
            root = left_rotate(root);
            type++;
        }
        printf("%s\n",type_str[type]);
        return root;
    }
    TreeNode *insertT(TreeNode *root,int key) {
        if(root == NIL) return new TreeNode(key);
        if(root->mKey == key) return root;
        if(key < root->mKey) root->mLeft = insertT(root->mLeft,key);
        else root->mRight = insertT(root->mRight,key);
        updateHeight(root);
        return maintain(root);
    }
    void outputT(TreeNode *root) {
        if(root == NIL) return;
        printf("(%d[%d] | %d, %d)\n",K(root), H(root),K(L(root)),K(R(root)));
        outputT(L(root));
        outputT(R(root));
    }
    TreeNode *eraseT(TreeNode* root,int key) {
        if(root == NIL) return root;
        if(key < K(root)) L(root) = eraseT(L(root),key);
        else if(key > K(root)) R(root) = eraseT(R(root),key);
        else {
            if(L(root) == NIL || R(root) == NIL) {
                TreeNode *tmp = L(root) != NIL ? L(root) : R(root);
                free(root);
                return tmp;
            } else {
                TreeNode *temp = predecessor(root);
                root->mKey = temp->mKey;
                L(root) = eraseT(L(root),K(temp));
            }
        }
        updateHeight(root);
        return maintain(root);
    }
    TreeNode *predecessor(TreeNode *root) {
        TreeNode *temp = L(root);
        while(R(temp) != NIL) temp = R(temp);
        return temp;
    }
    TreeNode *findT(TreeNode *root,int key) {
        if(root == NIL) return NIL;
        if(K(root) == key) return root;
        else if(key < K(root)) return findT(L(root),key);
        else return findT(R(root),key);
    }
public:
    AVLTree():mRoot(NIL) {}
    ~AVLTree() {
        delete mRoot;
    }
    void insert(int key) {
        mRoot = insertT(mRoot,key);
    }
    void erase(int key) {
        mRoot = eraseT(mRoot,key);
    }
    void output() {
        outputT(mRoot);
    }
    int find(int key) {
        if(findT(mRoot,key) == NIL) return 0;
        else return 1;
    }
    __attribute__((constructor)) friend void init_nil();
};
AVLTree::TreeNode AVLTree::__NIL;
__attribute__((constructor))
void init_nil() {
    NIL->mKey = -1;
    NIL->mH = 0;
    NIL->mLeft = NIL->mRight = NIL;
}
int main() {
    AVLTree* t = new AVLTree;
    int x;
    //insert
    while(scanf("%d",&x)) {
        if(x == -1) break;
        printf("insert %d to AVLTree\n",x);
        t->insert(x);
        t->output();
    }\
    //erase
    while(scanf("%d",&x)) {
        if(x == -1) break;
        printf("erase %d to AVLTree\n",x);
        t->erase(x);
        t->output();
    }
    //find
    while(scanf("%d",&x)) {
        if(x == -1) break;
        printf("find %d in AVLTree : %d\n",x,t->find(x));
    }
    delete t;
    return 0;
}