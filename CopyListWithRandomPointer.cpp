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
    Node* copyRandomList(Node* head) {
        Node* brandNew = new Node(0); 
        Node* temp = head;
        Node* t = brandNew;
        vector<Node*>vec(1001);
        map<Node*, Node*>mp;
        int i = 0;
        while(temp!=NULL){
            int data = temp->val;
            Node* newNode = new Node(data);
            vec[i++] = temp->random;
            t->next = newNode;
            t = t->next;
            mp[temp] = newNode;
            temp = temp->next;
        }
        
        t = brandNew->next;
        i = 0;
        while(t!=NULL){
            t->random = mp[vec[i++]];
            t = t->next;
        }
        return brandNew->next;
    }
};
