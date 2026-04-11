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
public:
    ListNode *rev(ListNode *curr, int k, ListNode *&nextblock)
    {
        ListNode *prev = NULL;
        int cnt = 0;
        while (cnt < k)
        {
            cnt++;
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        nextblock = curr;
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevtail = dummy;

        while (curr)
        {
            ListNode *temp = curr;
            int cnt = 0;
            while (temp && cnt < k)
            {
                cnt++;
                temp = temp->next;
            }

            if (cnt < k)
            {
                // link directly
                prevtail->next = curr;
                break;
            }

            // now rev and link
            ListNode *nextblock = NULL;
            ListNode *revhead = rev(curr, k, nextblock); // prev in rev

            prevtail->next = revhead;

            prevtail = curr;
            curr = nextblock;
        }
        return dummy->next;
    }
};
