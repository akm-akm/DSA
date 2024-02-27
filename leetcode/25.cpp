// Reverse Nodes in k-Group

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseRecursive(ListNode *curr, ListNode *prev = nullptr)
{
    if (curr == nullptr)
        return prev;
    ListNode *next = curr->next;
    curr->next = prev;
    return reverseRecursive(next, curr);
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        ListNode *t, *ans;
        int c = 1;
        for (int i = 1; i <= k; i++, head = head->next)
        {
            t = head;
            if (c == k)
            {
                t = reverseRecursive(t);
                c = 1;
            }
            t = t->next;

            c = c + 1;
        }
    }
};