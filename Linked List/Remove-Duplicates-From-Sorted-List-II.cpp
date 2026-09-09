// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int val = curr->val;
                while (curr != nullptr && curr->val == val) curr = curr->next;
                if (prev != nullptr) prev->next = curr;
                else head = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};