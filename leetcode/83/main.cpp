#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* now = head;
        ListNode* next = head->next;
        while (next != NULL)
        {
            if (now->val == next->val)
            {
                auto tmp = next;
                next = next->next;
                now->next = next;

                delete tmp;
                continue;
            }
            else
            {
                now = next;
                next = next->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;



    Solution s;
    auto res = s.deleteDuplicates(node1);

    while(res != NULL)
    {
        std::cout << res->val << std::endl;
        res = res->next;
    }


    return 0;
}