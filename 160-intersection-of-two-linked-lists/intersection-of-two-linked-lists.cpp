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
    // take ptr at both head;
    // loop while(next != null (both)) -> if(A == B) return A;
    //  if(A -> next == null) then
    //                  take int blen 
    //                  then loop(blen--) -> B = B -> next;
    //                  else case (opp the node) 
    // loop (headA != headB) 
    //                  headA next
    //                  headB next
    // return headA;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;

        while(A -> next != NULL && B -> next != NULL){
            if(A == B){
                return A;
            }
            A = A -> next;
            B = B -> next;
        }

        if(A -> next == NULL){
            // means B is bigger
            // take a int to cal len
            int bLen = 0;
            while(B -> next != NULL){
                bLen++;
                B = B -> next;
            }
            while(bLen--){
                headB = headB -> next;
            }
        }
        else {
            // means B is bigger
            // take a int to cal len
            int aLen = 0;
            while(A -> next != NULL){
                aLen++;
                A = A -> next;
            }
            while(aLen--){
                headA = headA -> next;
            }
        }

        while(headA != headB){
            headA = headA -> next;
            headB = headB -> next;
        }
        return headB;
    }
};