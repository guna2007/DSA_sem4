// merge 2 lists tc - nk

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
    // merge 2 lists
    ListNode *merge2(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }

        if (list1)
            curr->next = list1;
        else
            curr->next = list2;

        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        ListNode *curr = NULL;
        for (int i = 0; i < k; i++)
        {
            if (!lists[i])
                continue;
            curr = merge2(curr, lists[i]);
        }
        return curr;
    }
};

// using heap nlogk

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
    static bool comp(ListNode *const &n1, ListNode *const &n2)
    {
        // Return true if n1's priority is lower than n2's (for a min-heap)
        return n1->val > n2->val;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, decltype(&comp)> minheap(comp);
        ListNode dummy(0);
        ListNode *curr = &dummy;

        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
                minheap.push(lists[i]);
        }

        while (!minheap.empty())
        {
            ListNode *temp = minheap.top();
            minheap.pop();
            curr->next = temp;
            if (temp->next != NULL)
                minheap.push(temp->next);
            curr = curr->next;
        }

        return dummy.next;
    }
};
