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
    // get len of node
    // cal actualrotate = len % k
    // if  actualrotate == 0 return head;
    // take nodes -> newlastNode = head, newHead = newlastNode -> next, it = newlastNode
    // for(i < actualrotate) newlastNode = newlastNode -> next
    int getlen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head) return 0;

       int len = getlen(head);
       int actualrotate = (k % len);
       if(actualrotate == 0) return head;

    //    newlast position of node
        int newlastNodepos = len - actualrotate - 1;
        ListNode* newlastNode = head;

        for(int i = 0; i < newlastNodepos; i++){
            newlastNode = newlastNode -> next;
        }
        ListNode* newHead = newlastNode -> next;
        newlastNode -> next = NULL;
        ListNode* it = newHead;
        while(it -> next){
            it = it -> next;
        }
        it -> next = head;
        return newHead;
    }
};