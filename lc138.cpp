/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // use map for old ptr to new ptr
        unordered_map<Node *, Node *> mp;

        Node *newhead = new Node(head->val);
        mp[head] = newhead;
        Node *temp1 = head->next;
        Node *temp2 = newhead;
        while (temp1)
        {
            Node *newnode = new Node(temp1->val);
            temp2->next = newnode;
            mp[temp1] = newnode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1 = head;
        temp2 = newhead;

        while (temp1)
        {
            temp2->random = mp[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newhead;
    }
};

// optimal: single pass
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        mp[nullptr] = nullptr;

        Node *cur = head;
        while (cur != nullptr)
        {
            if (mp.find(cur) == mp.end())
            {
                mp[cur] = new Node(0);
            }
            mp[cur]->val = cur->val;
            if (mp.find(cur->next) == mp.end())
            {
                mp[cur->next] = new Node(0);
            }
            mp[cur]->next = mp[cur->next];
            if (mp.find(cur->random) == mp.end())
            {
                mp[cur->random] = new Node(0);
            }
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};