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

//同时遍历两个链表，并计算和，存储sum节点
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* list(head);
        int append = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = append;
            if (l1 != NULL) {
                sum += l1->val;
            }
            if (l2 != NULL) {
                sum += l2->val;
            }
            if (sum >= 10) {
                sum -= 10;
                append = 1;
            } else {
                append = 0;  
            }
            ListNode* node = new ListNode(sum);
            list->next = node;
            list = list->next;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        if (append != 0) {
            ListNode* node = new ListNode(append);
            list->next = node;
        }
        return head->next;
    }
};
