class Solution {
public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
         if(list1 == nullptr) return list2;
         if(list2 == nullptr) return list1;
         ListNode* curr = new ListNode();
         ListNode* head = curr;
         while(list1 || list2){
             if(list1 && (!list2 || list1->val < list2->val)){
                 curr->val = list1->val;
                 list1 = list1->next;
             }else{
                 curr->val = list2->val;
                 list2 = list2->next;
             }
             if(list1 || list2){
                 curr->next = new ListNode();
                 curr = curr->next;
             }
         }
        return head;
    }
};
