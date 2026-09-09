// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* helper(ListNode* head, int k){
        if(!head) return head;
        ListNode* temp = head;
        while(k > 1){
            temp = temp->next;
            k--;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = next;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        if(left == 1) return helper(head, right - left + 1);
        int counter = 1;
        ListNode* temp = head;
        ListNode* start = head;
        while(counter!=left - 1){
            temp = temp->next;
            counter++;
        }
        if(counter == left - 1) start = temp;
        start -> next = helper(start->next, right - left + 1);
        return head;
    }
};