#include <bits/stdc++.h>
#include <tools.hpp>
#define M 3
#define MAX_OP 10
#define L(root, pos) (root->mNext[pos])
#define R(root, pos) (root->mNext[pos + 1])
#define LAST_KEY(root) (root->mKey[root->mN - 1])
#define LAST_CHILD(root) (root->mNext[root->mN])
using namespace std;
class BTree {
private:
    class TreeNode {
    public:
        int mN;
        int mKey[M + 1]{};
        TreeNode* mNext[M + 1]{};
        TreeNode () : mN (0) {
            memset (mNext, 0,
                    sizeof (TreeNode*) * (M + 1));          // NOLINT
        }
        ~TreeNode () {
            for (int i = 0; i <= mN; i++) {
                delete mNext[i];
            }
        }
    };
    TreeNode* mRoot;
    friend TreeNode* insertKey (TreeNode* root, int key) {
        if (root == nullptr) {
            root = new TreeNode;
            root->mKey[(root->mN)++] = key;
            return root;
        }
        int pos = 0;
        while (pos < root->mN && root->mKey[pos] < key)
            pos++;
        if (root->mKey[pos] == key)
            return root;
        for (int i = root->mN - 1; i >= pos; i--) {
            root->mKey[i + 1] = root->mKey[i];
        }
        root->mKey[pos] = key;
        (root->mN)++;
        return root;
    }
    friend TreeNode* insert_t (TreeNode* root,          // NOLINT
                               int key) {
        if (root == nullptr || root->mNext[0] == nullptr) {
            return insertKey (root, key);
        }
        int pos = 0;
        while (pos < root->mN && root->mKey[pos] < key)
            pos++;
        if (pos < root->mN && root->mKey[pos] == key)
            return root;
        insert_t (root->mNext[pos], key);
        return insertMainTain (root, root->mNext[pos], pos);
    }
    friend TreeNode* insertMainTain (TreeNode* root, TreeNode* child,
                                     int pos) {
        if (child->mN < M)
            return root;
        int spos = M / 2;
        TreeNode* node1 = new TreeNode;
        TreeNode* node2 = new TreeNode;
        node1->mN = spos;
        node2->mN = M - 1 - spos;
        memcpy (node1->mKey, child->mKey, sizeof (int) * spos);
        memcpy (node1->mNext, child->mNext,
                sizeof (TreeNode*) * spos);          // NOLINT
        node1->mNext[spos] = child->mNext[spos];
        memcpy (node2->mKey, &(child->mKey[spos + 1]),
                sizeof (int) * node2->mN);
        memcpy (node2->mNext, &(child->mNext[spos + 1]),
                sizeof (TreeNode*) * node2->mN);          // NOLINT
        node2->mNext[node2->mN] = child->mNext[child->mN];
        for (int i = root->mN; i >= pos; i--) {
            root->mKey[i + 1] = root->mKey[i];
            root->mNext[i + 1] = root->mNext[i];
        }
        root->mKey[pos] = child->mKey[spos];
        root->mNext[pos] = node1;
        root->mNext[pos + 1] = node2;
        (root->mN)++;
        free (child);
        return root;
    }
    friend void printNode (TreeNode* root) {
        printf ("%d : ", root->mN);
        for (int i = 0; i < root->mN; i++) {
            printf ("%4d", root->mKey[i]);
        }
        printf (" | ");
        if (root->mNext[0] == nullptr) {
            goto outputEnd;
        }
        for (int i = 0; i <= root->mN; i++) {
            printf ("%4d", root->mNext[i]->mKey[0]);
        }
    outputEnd:
        puts ("");
    }
    void outputT (TreeNode* root) {          // NOLINT
        if (root == nullptr)
            return;
        printNode (root);
        for (int i = 0; i <= root->mN; i++)
            outputT (root->mNext[i]);
    }
    friend void erasePos (TreeNode* root, int pos) {
        for (int i = pos + 1; i < root->mN; i++) {
            root->mKey[i - 1] = root->mKey[i];
        }
        (root->mN)--;
    }
    friend void rightRotate (TreeNode* root, int pos) {
        for (int i = R (root, pos)->mN + 1; i > 0; i--) {
            R (root, pos)->mKey[i] = R (root, pos)->mKey[i - 1];
            R (root, pos)->mNext[i] = R (root, pos)->mNext[i - 1];
        }
        R (root, pos)->mKey[0] = root->mKey[pos];
        root->mKey[pos] = LAST_KEY (L (root, pos));
        R (root, pos)->mNext[0] = LAST_CHILD (L (root, pos));
        LAST_CHILD (L (root, pos)) = nullptr;
        R (root, pos)->mN += 1;
        L (root, pos)->mN -= 1;
    }
    friend void leftRotate (TreeNode* root, int pos) {
        L (root, pos)->mKey[L (root, pos)->mN] = root->mKey[pos];
        (L (root, pos)->mN)++;
        root->mKey[pos] = R (root, pos)->mKey[0];
        LAST_CHILD (L (root, pos)) = R (root, pos)->mNext[0];
        for (int i = 1; i <= R (root, pos)->mN; i++) {
            R (root, pos)->mKey[i - 1] = R (root, pos)->mKey[i];
            R (root, pos)->mNext[i - 1] = R (root, pos)->mNext[i];
        }
        LAST_CHILD (R (root, pos)) = nullptr;
        R (root, pos)->mN -= 1;
    }
    friend void merge (TreeNode* root, int pos) {
        TreeNode* node = new TreeNode;
        memcpy (node->mKey, L (root, pos)->mKey,
                sizeof (int) * L (root, pos)->mN);
        memcpy (node->mNext, L (root, pos)->mNext,
                sizeof (TreeNode*)          // NOLINT
                    * (L (root, pos)->mN + 1));
        node->mN = L (root, pos)->mN + 1;
        node->mKey[node->mN - 1] = root->mKey[pos];
        memcpy (&(node->mKey[node->mN]), R (root, pos)->mKey,
                sizeof (int) * R (root, pos)->mN);
        memcpy (&(node->mNext[node->mN]), R (root, pos)->mNext,
                sizeof (TreeNode*)          // NOLINT
                    * (R (root, pos)->mN + 1));
        node->mN += R (root, pos)->mN;
        free (L (root, pos));
        free (R (root, pos));
        for (int i = pos + 1; i < root->mN; i++) {
            root->mKey[i - 1] = root->mKey[i];
            root->mNext[i] = root->mNext[i + 1];
        }
        root->mNext[pos] = node;
        root->mN -= 1;
    }
    friend TreeNode* eraseMaintain (TreeNode* root, int pos) {
        int lowerBound = (M + 1) / 2 - 1;
        if (root->mNext[pos]->mN >= lowerBound)
            return root;
        if (pos > 0 && root->mNext[pos - 1]->mN > lowerBound) {
            rightRotate (root, pos - 1);
        } else if (pos < root->mN
                   && root->mNext[pos + 1]->mN > lowerBound) {
            leftRotate (root, pos);
        } else {
            if (pos > 0)
                merge (root, pos - 1);
            else
                merge (root, pos);
        }
        return root;
    }
    friend TreeNode* eraseT (TreeNode* root,          // NOLINT
                             int key) {
        if (root == nullptr)
            return root;
        int pos = 0;
        while (pos < root->mN && root->mKey[pos] < key)
            pos++;
        if (root->mNext[0] == nullptr) {
            if (root->mKey[pos] == key)
                erasePos (root, pos);
            return root;
        } else {
            if (pos < root->mN && root->mKey[pos] == key) {
                TreeNode* tmp = root->mNext[pos];
                while (tmp->mNext[tmp->mN] != nullptr)
                    tmp = tmp->mNext[tmp->mN];
                swap (root->mKey[pos], LAST_KEY (tmp));
            };
            root->mNext[pos] = eraseT (root->mNext[pos], key);
        }
        return eraseMaintain (root, pos);
    }

public:
    BTree () : mRoot (nullptr) {}
    void insert (int key) {
        mRoot = insert_t (mRoot, key);
        if (mRoot->mN == M) {
            TreeNode* p = new TreeNode;
            p->mNext[0] = mRoot;
            mRoot = insertMainTain (p, mRoot, 0);
        }
    }
    void output () {
        outputT (mRoot);
    }
    void erase (int key) {
        mRoot = eraseT (mRoot, key);
        if (mRoot->mN == 0) {
            TreeNode* tmp = mRoot->mNext[0];
            free (mRoot);
            mRoot = tmp;
        }
    }
};
int main () {
    BTree* t = new BTree;
    for (int i = 0; i < MAX_OP; i++) {
        int val = get_rand<int> (0, 100);
        t->insert (val);
        printf ("\ninsert %d to BTree\n", val);
        t->output ();
    }
    int x;
    while (scanf ("%d", &x) != EOF) {
        printf ("erase %d from BTree", x);
        t->erase (x);
        t->output ();
    }
    return 0;
}