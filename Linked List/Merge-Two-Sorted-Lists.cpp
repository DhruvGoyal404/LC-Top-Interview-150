// https://leetcode.com/problems/merge-two-sorted-lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* dummy2 = dummy;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                dummy->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            } else {
                dummy->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            dummy = dummy->next;
        }
        while(temp1 && !temp2){
            dummy->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            dummy = dummy->next;
        } 
        while(!temp1 && temp2) {
            dummy->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            dummy = dummy->next;
        }
        return dummy2->next;
    }
};