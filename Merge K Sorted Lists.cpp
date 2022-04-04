class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        int sz = lists.size();
        for(int i=0;i<sz;i++){
            while(lists[i] != nullptr){
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(!pq.size()) return nullptr;
        ListNode* curr = new ListNode(pq.top());
        pq.pop();
        ListNode* head = curr;
        while(pq.size()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }
        return head;
    }
};
