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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next; // modified as for even length ll we want the first middle node.

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if l1 is NULL then ans is l2
        if (l1==NULL) {
            return l2;
        }
        if (l2==NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *middle = findMiddle(head);
        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = nullptr;

        left = sortList(head);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};