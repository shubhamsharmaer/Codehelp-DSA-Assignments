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
    // h1 h2, temp = h2 
    // while(h2 && h2 -> next) --> h1 -> next = h2 -> next; h2 -> next = h2 -> next -> next;
    //                         --> h1 = h1 -> next; h2 = h2 -> next;
    // h1 -> next = temp
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head -> next == NULL) return head;
        
        ListNode* h1 = head;
        ListNode* h2 = head -> next;
        ListNode* temp = h2;
        while(h2 && h2 -> next){
            h1 -> next = h2 -> next;
            h2 -> next = h2 -> next -> next;
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        h1 -> next = temp;

        return head;
        
    }
};