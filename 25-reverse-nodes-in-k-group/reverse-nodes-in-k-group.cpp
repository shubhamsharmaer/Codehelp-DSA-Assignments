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
    // base case -> if head == NULL , head -> next == NULL return head;
    // check if len < k then return head;
    // reverse LL using pos = 0, while(pos < k)
    // take a ansNode = NULL
    // if(nextNode != NULL) then
    //          recursive call -> func(nextNode, k)
    //          head -> next = ansNode;
    // return ans
    int getlen(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == NULL || head -> next == NULL) return head;

        int pos = 0;
        
        int len = getlen(head);
        if(len < k) return head;
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* nextNode = cur -> next;
        while(pos < k){
            // reverse
            nextNode = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nextNode;

            pos++;
        }
       
        ListNode* ansNode = NULL;
        if(nextNode != NULL){
            ansNode = reverseKGroup(nextNode, k);
            head -> next = ansNode;
        }   
        return prev;
    }
};