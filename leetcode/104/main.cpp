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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    自己有root算一层，然后左右分支最大的，加自己这一层，就是这个root下的最大值。
    以此类推，左右分别计算自己的最大值
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int max = 1;
        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        return max + std::max(left, right);
    }
};

int main()
{
    TreeNode* node1 = new TreeNode();
    TreeNode* node2 = new TreeNode();
    TreeNode* node3 = new TreeNode();
    TreeNode* node4 = new TreeNode();
    TreeNode* node5 = new TreeNode();
    TreeNode* node6 = new TreeNode();
    TreeNode* node7 = new TreeNode();

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node6->left = node7;


    Solution s;
    int max = s.maxDepth(node1);

    std::cout<< max << std::endl;

    return 0;
}