
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionSerialization {
public:
    // Build tree using preorder input
    TreeNode* buildTree() {
        int x;
        cin >> x;

        if (x == -1) {
            return NULL;
        }

        TreeNode* root = new TreeNode(x);

        root->left = buildTree();
        root->right = buildTree();

        return root;
    }

    // Serialize tree using preorder traversal
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "()";
        }

        return "(" + to_string(root->val) + ")" +
               serialize(root->left) +
               serialize(root->right);
    }

    // Compare two trees
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string strP = serialize(p);
        string strQ = serialize(q);

        return strP == strQ;
    }
};

int main() {
    SolutionSerialization sol;

    cout << "Enter first tree (preorder, -1 for NULL): ";
    TreeNode* p = sol.buildTree();

    cout << "Enter second tree (preorder, -1 for NULL): ";
    TreeNode* q = sol.buildTree();

    if (sol.isSameTree(p, q)) {
        cout << "Both trees are identical." << endl;
    } else {
        cout << "Trees are different." << endl;
    }

    return 0;
}
