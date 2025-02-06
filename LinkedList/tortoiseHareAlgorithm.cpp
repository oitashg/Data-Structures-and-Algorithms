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
    //----------------Tortoise-Hare Algorithm-----------------
    //-------------------Find middle of LL--------------------

    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        // when length of ll is odd, fast will end at last node and for even length it will end at null
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    //------------------Detect cycle in LL----------------------------

    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    //---------------------Find length of loop in LL------------------------------------

    int findLength(ListNode *slow, ListNode *fast)
    {
        int cnt = 1;
        fast = fast->next;

        while (slow != fast)
        {
            cnt++;
            fast = fast->next;
        }

        return cnt;
    }

    int lengthOfLoop(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return findLength(slow, fast);
        }

        return 0;
    }

    //----------------------------------------------------------------
};