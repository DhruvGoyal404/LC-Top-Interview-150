// https://leetcode.com/problems/partition-list/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* dummy3 = dummy1;
        ListNode* dummy4 = dummy2;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val < x){
                dummy1->next = new ListNode(temp->val);
                dummy1 = dummy1->next;
            } else {
                dummy2->next = new ListNode(temp->val);
                dummy2 = dummy2->next;
            }
            temp = temp->next;
        }
        dummy1->next = dummy4->next;
        return dummy3->next;
    }
};