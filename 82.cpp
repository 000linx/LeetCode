#include <iostream>
#include <map>
#include <vector>

/*链表*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(0), next(next){};
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head == NULL){

            return head;
        }

        ListNode *top = new ListNode(0, head);
        ListNode *node = top;
        
        while (node->next && node->next->next)
        {
            if (node->next->val == node->next->next->val)
            {
                int x = node->next->val; 
                while (node->next && node->next->val == x)
                {
                    node->next = node->next->next;
                }  
            }
            else
                node = node->next;
        }

        return top->next;
    }
};
