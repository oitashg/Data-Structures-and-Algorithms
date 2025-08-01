#include<iostream>
using namespace std;

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
    //----------------------------------------------------

    ListNode *reverseSLL(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverseSLL(head->next);

        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    //------------------------------------------------------
};