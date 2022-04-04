/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(l1->val + l2->val);
        ListNode* head = curr;
        l1 = l1->next, l2 = l2->next;
        while(l1 != nullptr && l2 != nullptr){
            curr->next = new ListNode(l1->val+l2->val);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr){
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }
        
        curr = head;
        while(curr != nullptr){
            if(curr->val > 9){
                curr->val -= 10;
                if(curr->next != nullptr) curr->next->val++;
                else curr->next = new ListNode(1);
            }
            curr = curr->next;
        }
        
        return head;
    }
};
