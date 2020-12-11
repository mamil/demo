#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    节点非空，就交换左右子节点
    然后递归左节点，右节点
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);

    node1->left = node2;
    node1->right = node3;

    Solution s;
    TreeNode* node = s.invertTree(node1);

    return 0;
}