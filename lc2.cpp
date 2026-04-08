class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        ListNode *prev = NULL;

        int carry = 0;

        while (c1 && c2)
        {
            int val = c1->val + c2->val + carry;
            carry = val / 10;
            c1->val = val % 10;

            prev = c1;
            c1 = c1->next;
            c2 = c2->next;
        }

        while (c1)
        {
            int val = c1->val + carry;
            carry = val / 10;
            c1->val = val % 10;

            prev = c1;
            c1 = c1->next;
        }

        while (c2)
        {
            int val = c2->val + carry;
            carry = val / 10;

            prev->next = new ListNode(val % 10);
            prev = prev->next;

            c2 = c2->next;
        }

        if (carry)
        {
            prev->next = new ListNode(carry);
        }

        return l1;
    }
};

// better code
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};
