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
    // Node* helper(Node* head, unordered_map<Node*, Node*>& mp){
    //     // base case
    //     if(head == 0) return head;

    //     Node* newHead = new Node(head -> val);
    //     mp[head] = newHead;
    //     newHead -> next = helper(head -> next, mp);

    //     if(head -> random){
    //         newHead -> random = mp[head -> random];
    //     }

    //     return newHead;
    // }
    // M2 Optimized SC --> O(1)

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*, Node*> mp;
        // return helper(head, mp);

        if(head == NULL) return head;

        // Step 1: Clone A --> A'
        Node* it = head;
        while(it){
            Node* clonenode = new Node(it -> val);
            clonenode -> next = it -> next;
            it -> next = clonenode;
            it = it -> next -> next;
        }

        // Step 2: Assign random ptrs
        it = head;
        while(it){
            Node* clonenode = it -> next;
            clonenode -> random = it -> random ? it -> random -> next : NULL;
            it = it -> next -> next;
        }

        // Step 3: De-attach A & A'
        it = head;
        Node* clonehead = it -> next;
        while(it){
            Node* clonenode = it -> next;
            it -> next = it -> next -> next;
            if(clonenode -> next){
                clonenode -> next = clonenode -> next -> next;
            }
            it = it -> next;
        }
        return clonehead;
    }
};