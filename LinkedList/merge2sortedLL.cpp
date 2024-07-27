#include <iostream>
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
    //--------------------------------------------------------------
    
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *t1 = list1;
        ListNode *t2 = list2;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
        }

        if (t1 == NULL)
            temp->next = t2;
        if (t2 == NULL)
            temp->next = t1;

        return dummy->next;
    }

    //----------------------------------------------------------
};