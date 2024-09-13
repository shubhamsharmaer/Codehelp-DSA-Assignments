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
    // base case (head & next vala null)
    // ek case solve kro -> findmid (using slow & fast)
    //                   -> left = head; right = mid -> next
    //                   -> mid -> next = null
    // RE call -> left = mainfun(left); same with right
    // apply mergelogic -> newNode = mergeList(left, right)
    // Use mptr vala logic in mergeing
    ListNode* mergeList(ListNode* left, ListNode* right){
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
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast && fast -> next){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        // base case
        if(head == NULL || head -> next == NULL) return head;

        // mid
        ListNode* mid = findmid(head);
        // break
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        // RE Call
        left = sortList(left);
        right = sortList(right);

        // merge logic
        ListNode* mergelist = mergeList(left,right);
        return mergelist;
    }
};