// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    int length(ListNode* head){
        int k = 0;
        ListNode* temp = head;
        while(temp){
            k++;
            temp = temp->next;
        }
        return k;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        int toRemove = len - n - 1;

        if(n == len){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        while(toRemove--){
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};