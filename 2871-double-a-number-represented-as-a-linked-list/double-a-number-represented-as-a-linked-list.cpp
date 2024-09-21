/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // With Recursion --> go to righmost node at X, A--B--C--X
    // if !head return --> backtrack one step to C
    // RE Call (head -> next, carry)
    // case soln --> int prod = head -> val * 2 + carry
    //               head -> val = prod % 10; carry = prod / 10; 
    void helper(ListNode* head, int& carry){
        if(!head) return;
        // RE Call
        helper(head -> next, carry);
        int prod = head -> val * 2 + carry;
        head -> val = prod % 10;
        carry = prod / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        helper(head, carry);
        if(carry != 0){
            ListNode* temp = new ListNode(carry);
            temp -> next = head;
            head = temp;
        }
        return head;
    }
};