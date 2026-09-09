// https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* temp2 = temp;
        int carry = 0;
        while(l1 && l2){
            int value = l1->val + l2->val+carry;
            carry = value / 10;
            value %= 10;
            temp->next = new ListNode(value);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1){
            while(l2){
                int value = l2->val+carry;
                carry = value / 10;
                value %= 10;
                temp->next = new ListNode(value);
                temp = temp->next;
                l2 = l2 ->next;
            }
        }
        if(!l2){
            while(l1){
                int value = l1->val+carry;
                carry = value / 10;
                value %= 10;
                temp->next = new ListNode(value);
                temp = temp->next;
                l1 = l1 ->next;
            }
        }
        if(carry){
            temp->next = new ListNode(1);
            temp = temp->next;
        }
        return temp2->next;
    }
};