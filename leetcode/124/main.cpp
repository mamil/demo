#include <iostream>
#include <algorithm>
#include <utility>
#include <limits.h>

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

class Solution {
public:
    /**
        对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:
        1. 其左右子树中所构成的和路径值较大的那个加上该节点的值后向父节点回溯构成最大路径
        2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径
        **/

    int ret = INT_MIN; // 这里要最小值，不然可能会比其它路径大
    int maxPathSum(TreeNode* root) {
       getMax(root);

       return ret;
    }

    int getMax(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0 ;
        }
        int left = std::max(0, getMax(root->left)); // 获取左子树能达到的最大值，如果< 0,那还不如不包含左子树
        int right = std::max(0, getMax(root->right));

        ret = std::max(ret, root->val + right + left); // 判断现在这一层是不是最大值

        return std::max(left, right) + root->val; //不能走回头路，所以只能往上层推导的时候，只能left -> root,或者right -> root，不可能left,root,right都有
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
    TreeNode* node8 = new TreeNode();


    node1->val = -10;
    node2->val = 9;
    node3->val = 20;
    node1->left = node2;
    node1->right = node3;

    node4->val = 15;
    node5->val = 7;
    node3->left = node4;
    node3->right = node5;


    Solution s;
    int max = s.maxPathSum(node1);

    std::cout<< max << std::endl;

    node1->val = -3;
    node1->left = nullptr;
    node1->right = nullptr;

    s.ret = INT_MIN;
    max = s.maxPathSum(node1);
    std::cout<< max << std::endl;

    node1->val = 1;
    node1->left = node2;
    node1->right = node3;
    node2->val = -2;
    node2->left = node4;
    node2->right = node5;
    node3->val = -3;
    node3->left = node6;
    node3->right = nullptr;
    node4->val = 1;
    node4->left = node7;
    node4->right = nullptr;
    node5->val = 3;
    node5->left = nullptr;
    node5->right = nullptr;
    node6->val = -2;
    node6->left = nullptr;
    node6->right = nullptr;
    node7->val = -1;
    node7->left = nullptr;
    node7->right = nullptr;

    s.ret = INT_MIN;
    max = s.maxPathSum(node1);
    std::cout<< max << std::endl;

    std::cout<< INT_MIN  << std::endl;


    return 0;
}