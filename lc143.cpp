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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;

        ListNode *curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }

        int half = st.size() / 2;

        curr = head;
        for (int i = 0; i < half; i++)
        {
            ListNode *next = curr->next;
            ListNode *back = st.top();
            st.pop();

            curr->next = back;
            back->next = next;

            curr = next;
        }
        // key: i forgetten getting infinte loop
        curr->next = nullptr;
    }
};

// optimal soln

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
    void reorderList(ListNode *head)
    {
        // find middle
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse 2nd half
        ListNode *curr = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;

        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect them
        ListNode *first = head;
        ListNode *second = prev;

        while (second)
        {
            ListNode *next1 = first->next;
            ListNode *next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};
