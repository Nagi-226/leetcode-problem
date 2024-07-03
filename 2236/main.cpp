#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    bool checkTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return false;
        }
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;
        return root->val == leftVal + rightVal;
    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    Solution solution;
    if (solution.checkTree(root))
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}