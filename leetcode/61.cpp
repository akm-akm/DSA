// Rotate List

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *t = head;
        ListNode *a = head;
        int l = 0;
        while (t != nullptr)
        {
            l = l + 1;
            t = t->next;
        }
        if (l == 0 || l == 1)
        {
            return head;
        }
        if (k >= l)
        {
            k = k % l;
        }
        if (k == 0)
        {
            return head;
        }

        for (int i = 1; i <= l - k; head = head->next, i++)
        {
            // te->next = new ListNode(head->val);
            if (i == l - k)
            {
                t = head->next;
                head->next = nullptr;
                break;
            }

            //  te = te->next;
        }
        // t is new head so save it
        ListNode *kp = t;
        while (t->next != nullptr)
        {
            if (t->next == nullptr)
            {
                t->next = a;
                break;
            }
            t = t->next;
        }

        return kp;
    }
};