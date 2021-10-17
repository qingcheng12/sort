/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 *  21. 合并两个有序链表
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * * * /

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = new ListNode(0);
        ListNode* res = result;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                res->next = l2;
                l2 = l2->next;
            } else {
                res->next = l1;
                l1 = l1->next;
            }
            res = res->next;
        }

        res->next = (l1 == nullptr) ? l2 : l1;

        return result->next;
    }
};