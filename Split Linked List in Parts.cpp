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
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int len = getLength(head);
        vector<ListNode*> vec(k, nullptr);
        ListNode* curr = head;
        if(k >= len)
        {
            for(int i=0;i<len;i++)
            {
                vec[i] = curr;
                ListNode* tmp = curr->next;
                curr->next = nullptr;
                curr = tmp;
            }
            return vec;
        }
        int chunkSize = len/k;
        int rem = len%k;
        for(int i=0;i<k;i++)
        {
            int carry = (rem > 0);
            vec[i] = curr;
            for(int j=0; j < chunkSize+carry-1 && curr; j++)
            {
                curr = curr->next;
            }
            if(curr)
            {
                ListNode* tmp = curr->next;
                curr->next = nullptr;
                curr = tmp;
            }
            rem--;
        }
        return vec;

        
    }
};
