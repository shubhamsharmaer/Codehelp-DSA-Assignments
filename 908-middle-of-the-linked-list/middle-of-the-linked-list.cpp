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
    // USED Slow & Fast Algorithm
    //      take slow and fast node
    //      if fast can move 2 steps forward then move slow with one step
    //      when fast = NULL slow will be at middle
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};