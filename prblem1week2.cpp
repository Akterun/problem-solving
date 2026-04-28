#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* merge(ListNode* left, ListNode* right)
{
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while(left && right)
    {
        if(left->val <= right->val)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    while(left)
    {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }

    while(right)
    {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    return dummy->next;
}


ListNode* merge_sort(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;


    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = NULL;


    ListNode* left = merge_sort(head);
    ListNode* right = merge_sort(mid);

    return merge(left, right);
}

int main()
{
    int n;
    cin >> n;

    if(n == 0) return 0;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    head = merge_sort(head);

    // print
    temp = head;
    while(temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
