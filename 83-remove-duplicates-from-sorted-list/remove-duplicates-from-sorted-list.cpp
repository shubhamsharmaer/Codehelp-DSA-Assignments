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
    // base case check for head == null, head -> next then return head
    // take temp node
    // while(temp != null)
    //          if(temp -> data == temp -> next -> data)
    //              then take a nextNode = temp -> next
    //              temp -> next = nextNode -> next
    //              nextNode -> next = null
    // return head;
    ListNode* deleteDuplicates(ListNode* head) {
        // base case
        if(head == NULL){
            return head;
        }
        if(head -> next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* nextNode;
        while(temp != NULL  && temp -> next != NULL){
            if(temp -> val == temp -> next -> val){
                nextNode = temp -> next;
                temp -> next = nextNode -> next;
                nextNode -> next = NULL;
                delete nextNode;
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
};