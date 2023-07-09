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
class Solution
{
    int getLength(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* getTail(ListNode* head)
    {
        if(head == nullptr) return nullptr;
        while(head->next)
        {
            head = head->next;
        }
        return head;
    }

    ListNode* ithNode(ListNode* head, int index)
    {
        if(index < 0) return nullptr;
        while(index && head->next)
        {
            head = head->next;
            index--;
        }
        return head;
    }

public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr || head->next == nullptr) return head;
        int n = getLength(head);
        k %= n;
        if(k == 0) return head;
        ListNode* tail = getTail(head);
        ListNode* preHead = ithNode(head, n - k - 1);
        ListNode* newHead = preHead->next;
        preHead->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
