#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct ListNode {
    ListNode(){};
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pre;
//         for (pre = NULL; head; swap(head, pre))
//         {
//             swap(pre, head->next);
//         }
//         return pre;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
//         ListNode* p1 = head;
//         ListNode* p2 = head->next;
//         ListNode* p3 = p2->next;

//         while(p3)
//         {
//             p2->next = p1;
//             p1 = p2;
//             p2 = p3;
//             p3 = p3->next;
//         }
//         p2->next = p1;
//         head->next = NULL;
//         return p2;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pre = NULL;
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre; // 注意返回什么
    }
};

int main()
{
    ListNode* node1 = new ListNode();
    ListNode* node2 = new ListNode();
    ListNode* node3 = new ListNode();

    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 3;
    node3->next = NULL;

    Solution s;
    ListNode* node = s.reverseList(node1);

    std::cout<< node->val << std::endl;
    while (node->next != NULL)
    {
        node = node->next;
        std::cout<< node->val << std::endl;

    }

    return 0;
}