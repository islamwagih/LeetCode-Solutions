class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> addrs;
        while(head){
           if(head->next && addrs.find(head->next) != addrs.end()){
                return head->next;
            }
            cout<<head->val<<' ';
            addrs.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
