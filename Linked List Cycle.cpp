/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast && slow != nullptr) return true;
        }
        return false;
    }
};
