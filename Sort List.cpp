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
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;
        while(left && right)
        {
            if(left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }else
            {
                 tail->next = right;
                 right = right->next;
            }
            tail = tail->next;
        }
        if(left) tail->next = left;
        else if(right) tail->next = right;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* tmp = right->next;
        right->next = nullptr;
        right = tmp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    ListNode* sortListUsingHeap(ListNode* head) {
        if(head == nullptr) return head;
        priority_queue<int> sorter;

        while(head)
        {
            sorter.push(-head->val);
            head = head->next;
        }
        head = new ListNode(-sorter.top());
        ListNode* curr = head;
        sorter.pop();
        while(sorter.size())
        {
            curr->next = new ListNode(-sorter.top());
            sorter.pop();
            curr = curr->next;
        }
        return head;
    }
};
