class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        int mid = n/2;
        ListNode* m = head;
        while(mid--){
            m = m->next;
        }
        return m;
    }
};
