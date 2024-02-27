// Remove Nth Node From End of List
#include <iostream>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int c = 1;
        ListNode *temp = head;

        while (head->next != nullptr)
        {
            c++;
        }
        head = temp;
        if (c==1)
        {
            return temp->next;
        }
      
        for (int i = 2; i <= c - n; i++)
        {
            head = head->next;
        }
        head = head->next->next;
        delete (head->next);
        return temp;
    }
};