#include <bits/stdc++.h>
#include <tools.hpp>
#define KEY(n) (n ? n->mKey : -1)
using namespace std;
class BinarySearchTree {
private:
    class TreeNode {
    public:
        int mKey{};
        TreeNode *mLeft{}, *mRight{};
        TreeNode ();
        TreeNode (int key);
        ~TreeNode ();
    };
    struct Dat {
        Dat (TreeNode* root) : mRoot (root), mCode (0) {}
        TreeNode* mRoot;
        int mCode;
    };
    TreeNode* mRoot;
    TreeNode* insertT (TreeNode* root, int key);
    TreeNode* eraseT (TreeNode* root, int key);
    TreeNode* predecessor (TreeNode* root);
    void outputT (TreeNode* root);
    void inOrderT (TreeNode* root);
    friend void nonInOrderT (TreeNode* root) {
        stack<Dat> s;
        s.emplace (root);
        TreeNode* tmp;
        while (!s.empty ()) {
            Dat& cur = s.top ();
            switch (cur.mCode) {
                case 0:
                    if (cur.mRoot == nullptr) {
                        s.pop ();
                    } else {
                        cur.mCode = 1;
                    }
                    break;
                case 1:
                    cur.mCode = 2;
                    s.emplace (cur.mRoot->mLeft);
                    break;
                case 2:
                    printf ("%d ", cur.mRoot->mKey);
                    cur.mCode = 3;
                    break;
                case 3:
                    tmp = cur.mRoot->mRight;
                    cur.mCode = 4;
                    s.emplace (tmp);
                    break;
                case 4:
                    s.pop ();
                    break;
            }
        }
    }

public:
    BinarySearchTree ();
    ~BinarySearchTree ();
    void insert (int key);
    void erase (int key);
    void output ();
    void inOrder ();
    void nonInOrder () {
        nonInOrderT (mRoot);
    }
};
BinarySearchTree::TreeNode::TreeNode ()
    : mKey (0), mLeft (nullptr), mRight (nullptr) {}
BinarySearchTree::TreeNode::TreeNode (int key)
    : mKey (key), mLeft (nullptr), mRight (nullptr) {}
BinarySearchTree::TreeNode::~TreeNode () {
    delete mLeft;
    delete mRight;
}
BinarySearchTree::BinarySearchTree () {
    mRoot = nullptr;
}
BinarySearchTree::~BinarySearchTree () {
    delete mRoot;
}
void BinarySearchTree::insert (int key) {
    mRoot = insertT (mRoot, key);
}
void BinarySearchTree::erase (int key) {
    mRoot = eraseT (mRoot, key);
}
BinarySearchTree::TreeNode*
BinarySearchTree::insertT (TreeNode* root,          // NOLINT
                           int key) {
    if (root == nullptr)
        return new TreeNode (key);
    if (key == root->mKey)
        return root;
    if (key < root->mKey)
        root->mLeft = insertT (root->mLeft, key);
    else
        root->mRight = insertT (root->mRight, key);
    return root;
}
BinarySearchTree::TreeNode*
BinarySearchTree::eraseT (TreeNode* root,          // NOLINT
                          int key) {
    if (root == nullptr)
        return root;
    if (key < root->mKey)
        root->mLeft = eraseT (root->mLeft, key);
    else if (key > root->mKey)
        root->mRight = eraseT (root->mRight, key);
    else {
        if (root->mLeft == nullptr && root->mRight == nullptr) {
            delete root;
            return nullptr;
        } else if (root->mLeft == nullptr
                   || root->mRight == nullptr) {
            TreeNode* temp = root->mLeft ? root->mLeft : root->mRight;
            free (root);
            return temp;
        } else {
            TreeNode* temp = predecessor (root);
            root->mKey = temp->mKey;
            root->mLeft = eraseT (root->mLeft, temp->mKey);
        }
    }
    return root;
}
BinarySearchTree::TreeNode*
BinarySearchTree::predecessor (TreeNode* root) {          // NOLINT
    TreeNode* temp = root->mLeft;
    while (temp->mRight)
        temp = temp->mRight;
    return temp;
}
void BinarySearchTree::outputT (TreeNode* root) {          // NOLINT
    if (root == nullptr)
        return;
    printf ("(%d : %d : %d)\n", KEY (root), KEY (root->mLeft),
            KEY (root->mRight));
    outputT (root->mLeft);
    outputT (root->mRight);
}
void BinarySearchTree::output () {
    outputT (mRoot);
}
void BinarySearchTree::inOrderT (TreeNode* root) {          // NOLINT
    if (root == nullptr)
        return;
    inOrderT (root->mLeft);
    printf ("%d ", root->mKey);
    inOrderT (root->mRight);
}
void BinarySearchTree::inOrder () {
    inOrderT (mRoot);
}
int main () {
#define MAX_OP 10
    BinarySearchTree* tree = new BinarySearchTree;
    for (int i = 0; i < MAX_OP; i++) {
        int key = get_rand<int> (0, 100);
        printf ("insert key %d to BST\n", key);
        tree->insert (key);
    }
    tree->output ();
    printf ("in order : ");
    tree->inOrder ();
    puts ("");
    tree->nonInOrder ();
    puts ("");
    int x;
    while (scanf ("%d", &x)) {
        if (x == -1)
            break;
        printf ("erase %d from BST\n", x);
        tree->erase (x);
        tree->inOrder ();
        puts ("");
    }
    delete tree;
    return 0;
}