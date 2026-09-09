// https://leetcode.com/problems/rotate-list/description/
class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = length(head);
        k=k%len;
        if(k==0) return head;
        int to = len - k - 1;
        ListNode* temp = head;
        while(to-- && temp){
            temp = temp->next;
        }
        ListNode* nextt = temp->next;
        ListNode* next2 = temp->next;
        temp->next = NULL;
        while(next2->next){
            next2 = next2 -> next;
        }
        next2->next = head;
        head = nextt;
        return head;
    }
};