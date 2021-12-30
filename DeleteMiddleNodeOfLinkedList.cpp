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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return NULL;
        }
        if(head->next->next == NULL){
            delete(head->next);
            head->next = NULL;
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* prev = head;
        while(temp2!= NULL and temp2->next != NULL){
            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
        prev->next = temp1->next;
        delete(temp1);
        return head;
    }
};
