#include <iostream>
#include <algorithm>

/*链表*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        for (auto x = head; x->next != NULL; x = x->next->next){
            int result = std::__gcd(x->val, x->next->val);
            x->next = new ListNode(result, x->next);
            return head;
        }
    }   
};