// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    void reverseLinkedList(ListNode* temp){
        if(!temp) return;
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* ahead = temp->next;
        while(curr!=nullptr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL){
            ListNode* kThNode = getKthNode(temp, k);
            if(kThNode == nullptr){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head) head = kThNode;
            else prevLast->next = kThNode;
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};