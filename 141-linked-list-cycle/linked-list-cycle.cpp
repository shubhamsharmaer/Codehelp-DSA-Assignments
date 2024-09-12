/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Slow & Fast Method
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }

            if(fast == slow) return true;
        } 

        return false;


        // MAP Method
        // make a map
        // traverse till temp != NULL
        //      -> if map[temp] == false then map[temp] = true;
        //      -> else return true;
        // at last outside of while reuturn false;
        // map<ListNode*, bool> visited;
        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(visited[temp] == false){
        //         visited[temp] = true;
        //     }
        //     else{
        //         return true;
        //     }
        //     temp = temp -> next;
        // }
        // return false;
    }
};