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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // take ans vec
        vector<int> ans = {-1,-1}; // storing minD and maxD
        ListNode* prev = head;
        ListNode* cur = head -> next;
        ListNode* nxt = head -> next -> next;
        if(!prev || !cur || !nxt) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDis = INT_MAX;
        int i = 1;
        while(nxt){
            bool isCP = ((cur -> val < prev -> val && cur -> val < nxt -> val) || 
                (cur -> val > prev -> val && cur -> val > nxt -> val)) ? true : false;

            // check for fitst CP
            if(isCP && firstCP == -1){
                // for first CP both last and first CP are on same pos
                firstCP = i;
                lastCP = i;
            }
            else if(isCP){
                // all next CP will come under this else
                // cacl minDis = i - lastCP
                minDis = min(minDis, i - lastCP);
                lastCP = i; // update lastCP pos
            }
            ++i;
            prev = prev -> next;
            cur = cur -> next;
            nxt = nxt -> next;
        }

        // cal maxDis
        if(lastCP == firstCP){
            return ans;
        }
        else{
            ans[0] = minDis;
            ans[1] = lastCP - firstCP;
        }
        return ans;

        
    }
};