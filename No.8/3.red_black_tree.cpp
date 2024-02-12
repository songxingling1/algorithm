#include <bits/stdc++.h>
#include <tools.hpp>
#define NIL (&RedBlackTree::mNIL)
#define K(n) (n->mKey)
#define L(n) (n->mLeft)
#define R(n) (n->mRight)
#define C(n) (n->mColor)
using namespace std;
const char* gStr[3] = { "red", "black", "double black" };
class RedBlackTree {
private:
    enum COLOR { RED, BLACK, DBLACK };
    class TreeNode {
    public:
        int mKey;
        COLOR mColor;
        TreeNode *mLeft, *mRight;
        TreeNode ()
            : mKey (0), mColor (RED), mLeft (NIL), mRight (NIL) {}
        TreeNode (int key)
            : mKey (key), mColor (RED), mLeft (NIL), mRight (NIL) {}
        TreeNode (int key, COLOR c)
            : mKey (key), mColor (c), mLeft (NIL), mRight (NIL) {}
        ~TreeNode () {
            if (this == NIL)
                return;
            delete mLeft;
            delete mRight;
        }
        void* operator new (size_t size) {
            return malloc (size);
        }
        void operator delete (void* ptr) {
            if (ptr == NIL)
                return;
            free (ptr);
        }
    };
    static inline bool hasRedNode (TreeNode* root) {
        return C (L (root)) == RED || C (R (root)) == RED;
    }
    static TreeNode* insertMaintain (TreeNode* root) {
        int flag = 0;
        if (C (L (root)) == RED && hasRedNode (L (root)))
            flag = 1;
        if (C (R (root)) == RED && hasRedNode (R (root)))
            flag = 2;
        if (flag == 0)
            return root;
        if (C (L (root)) == RED && C (R (root)) == RED)
            goto upRedMaintain;
        if (flag == 1) {
            if (C (R (L (root))) == RED) {
                L (root) = leftRotate (L (root));
            }
            root = rightRotate (root);
        } else {
            if (C (L (R (root))) == RED) {
                R (root) = rightRotate (R (root));
            }
            root = leftRotate (root);
        }
    upRedMaintain:
        C (root) = RED;
        C (L (root)) = C (R (root)) = BLACK;
        return root;
    }
    static TreeNode*
    eraseMainTaim (TreeNode* root) {          // NOLINT
        if (C (L (root)) != DBLACK && C (R (root)) != DBLACK)
            return root;
        // brother : red
        if (hasRedNode (root)) {
            root->mColor = RED;
            if (C (L (root)) == RED) {
                root = rightRotate (root);
                R (root) = eraseMainTaim (R (root));
            } else {
                root = leftRotate (root);
                L (root) = eraseMainTaim (L (root));
            }
            root->mColor = BLACK;
        }
        if ((C (L (root)) == DBLACK && !hasRedNode (R (root)))
            || (C (R (root)) == DBLACK && !hasRedNode (L (root)))) {
            root->mColor += 1;
            C (L (root)) -= 1;
            C (R (root)) -= 1;
            return root;
        };
        if (C (R (root)) == DBLACK) {
            C (R (root)) = BLACK;
            if (C (L (L (root))) != RED) {
                L (root) = leftRotate (L (root));
            }
            root->mLeft->mColor = C (root);
            root = rightRotate (root);
        } else {
            C (L (root)) = BLACK;
            if (C (R (R (root))) != RED) {
                R (root) = rightRotate (R (root));
            }
            root->mRight->mColor = C (root);
            root = leftRotate (root);
        }
        C (L (root)) = C (R (root)) = BLACK;
        return root;
    }
    static TreeNode* leftRotate (TreeNode* root) {
        TreeNode* ptr = root->mRight;
        root->mRight = ptr->mLeft;
        ptr->mLeft = root;
        return ptr;
    }
    static TreeNode* rightRotate (TreeNode* root) {
        TreeNode* ptr = root->mLeft;
        root->mLeft = ptr->mRight;
        ptr->mRight = root;
        return ptr;
    }
    static TreeNode* predecessor (TreeNode* root) {
        TreeNode* tmp = root->mLeft;
        while (tmp->mRight != NIL)
            tmp = tmp->mRight;
        return tmp;
    }
    TreeNode* insertT (TreeNode* root,          // NOLINT
                       int key) {
        if (root == NIL)
            return new TreeNode (key);
        if (K (root) == key)
            return root;
        if (key < K (root))
            L (root) = insertT (L (root), key);
        else
            R (root) = insertT (R (root), key);
        return insertMaintain (root);
    }
    void outputT (TreeNode* root) {          // NOLINT
        if (root == NIL)
            return;
        printf ("(%s| %d, %d, %d)\n", gStr[C (root)], K (root),
                K (L (root)), K (R (root)));
        outputT (L (root));
        outputT (R (root));
    }
    TreeNode* eraseT (TreeNode* root, int key) {          // NOLINT
        if (root == NIL)
            return root;
        if (key < root->mKey) {
            root->mLeft = eraseT (L (root), key);
        } else if (key > root->mKey) {
            root->mRight = eraseT (R (root), key);
        } else {
            if (root->mLeft == NIL || root->mRight == NIL) {
                TreeNode* tmp =
                    root->mLeft == NIL ? root->mRight : root->mLeft;
                tmp->mColor += root->mColor;
                free (root);
                return tmp;
            }
            TreeNode* tmp = predecessor (root);
            root->mKey = tmp->mKey;
            root->mLeft = eraseT (root->mLeft, tmp->mKey);
        }
        return eraseMainTaim (root);
    }
    friend COLOR& operator+= (COLOR& n1, COLOR& n2) {
        int i1 = n1, i2 = n2;
        n1 = ( COLOR )(i1 + i2);
        return n1;
    }
    friend COLOR& operator+= (COLOR& n1, int i2) {
        int i1 = n1;
        n1 = ( COLOR )(i1 + i2);
        return n1;
    }
    friend COLOR& operator-= (COLOR& n1, int i2) {
        int i1 = n1;
        n1 = ( COLOR )(i1 - i2);
        return n1;
    }
    static TreeNode mNIL;
    TreeNode* mRoot;

public:
    RedBlackTree () : mRoot (NIL) {}
    ~RedBlackTree () {
        delete mRoot;
    }
    void insert (int key) {
        mRoot = insertT (mRoot, key);
        C (mRoot) = BLACK;
    }
    void output () {
        outputT (mRoot);
    }
    void erase (int key) {
        eraseT (mRoot, key);
        mRoot->mColor = BLACK;
    }
};
RedBlackTree::TreeNode RedBlackTree::mNIL{ -1,          // NOLINT
                                           BLACK };
int main () {
#define MAX_OP 10
    RedBlackTree* t = new RedBlackTree;
    for (int i = 0; i < MAX_OP; i++) {
        int x = get_rand<int> (0, 100);
        printf ("\ninsert %d to RedBlackTree : \n", x);
        t->insert (x);
        t->output ();
    }
    int x;
    while (scanf ("%d", &x) != EOF) {
        printf ("\nerase %d from RedBlackTree\n", x);
        t->erase (x);
        t->output ();
    }
    return 0;
}