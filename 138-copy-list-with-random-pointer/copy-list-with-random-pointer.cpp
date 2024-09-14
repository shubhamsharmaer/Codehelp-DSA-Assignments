/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // make a map <node, node> mp
    // call helper(head, mp)
    // base case (head == null)
    // make newNode = new Node(head -> val)
    // mp[head] = newHead; --> map the old ptr to new ptr
    // if head -> random then newHead -> random = mp[head -> random]
    // return newHead;
    Node* helper(Node* head, unordered_map<Node*, Node*>& mp){
        // base case
        if(head == 0) return head;

        Node* newHead = new Node(head -> val);
        mp[head] = newHead;
        newHead -> next = helper(head -> next, mp);

        if(head -> random){
            newHead -> random = mp[head -> random];
        }

        return newHead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return helper(head, mp);
    }
};