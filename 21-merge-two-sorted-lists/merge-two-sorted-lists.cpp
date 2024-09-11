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
    // base condn -> if left == 0 return right or right == 0 return left
    // take Node* ansNode  = new Node(-1);
    // take Node* mptr = ansNode;
    // loop while(left && right)
    //              if(left -> val <= right -> val) then 
    //              else
    // add left node if any (left) mptr -> next = left
    // add right node if any (left) mptr -> next = right
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        // base case
        if(left == 0) return right;
        if(right == 0) return left;
        
        ListNode* ansNode = new ListNode(-1);
        ListNode* mptr = ansNode;

        while(left && right){
            if(left -> val <= right -> val){
                mptr -> next = left;
                mptr = left;
                left = left -> next;
            }
            else{
                mptr -> next = right;
                mptr = right;
                right = right -> next;
            }
        }

        if(left){
            mptr -> next = left;
        }
        if(right){
            mptr -> next = right;
        }

        return ansNode -> next;
    }
};