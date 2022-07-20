class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prv = nullptr, *next = nullptr, *curr = head;
        while(curr){
            next = curr->next;
            curr->next = prv;
            prv = curr;
            curr = next;
        }
        return prv;
   }
};