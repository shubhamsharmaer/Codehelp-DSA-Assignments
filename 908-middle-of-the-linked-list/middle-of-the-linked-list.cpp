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
    int getlen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int n = getlen(head);   
        int middlepos = (n/2) + 1;
        int currpos = 1;
        ListNode* temp = head;
        while(currpos != middlepos){
            temp = temp -> next;
            currpos++;
        }
        return temp;
    }
};