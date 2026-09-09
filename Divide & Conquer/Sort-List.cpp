// https://leetcode.com/problems/sort-list/description
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;

        while(fast && fast->next){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        slow_prev->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeTwoSortedLists(left, right);
    }
};