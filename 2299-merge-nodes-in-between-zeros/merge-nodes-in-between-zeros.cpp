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
    // take slow, fast (head -> next), lastNode = 0
    // while(fast) jb tk fast ha
    //          if fast -> val != 0 hai to sum += fast -> val
    //          else --> slow -> val = sum
    //               --> lastNode = slow
    //               --> slow = slow -> next
    //               --> sum = 0
    //          fast = fast -> next
    // take temp = lastNode -> next
    // while(temp) --> *nxt = temp -> next
    //             --> delete temp then temp = next
    // return head;
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;

        ListNode* slow = head;
        ListNode* fast = head -> next;
        ListNode* lastNode = 0;
        int sum = 0;

        while(fast){
            if(fast -> val != 0){
                sum += fast -> val;
            }
            else{
                slow -> val = sum;
                lastNode = slow;
                slow = slow -> next;
                sum = 0;
            }
            fast = fast -> next;
        }
        ListNode* temp = lastNode -> next;
        lastNode -> next = NULL;
        
        // delete old list NOT DELETING NODES TO IMPROVE TIME COMPLEXITY
        // while(temp){
        //     ListNode* nxt = temp -> next;
        //     delete temp;
        //     temp = nxt;
        // }
        
        return head;
    }
};