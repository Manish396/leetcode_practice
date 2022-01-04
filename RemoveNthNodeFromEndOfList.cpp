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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        int p1 = 0, p2 = 0;
        ListNode* curr = head;
        ListNode* nth = head;
        while(curr->next!=NULL){
            p1++;
            if(p1 - p2 > n){
                p2++;
                nth = nth->next;
            }
            curr = curr->next;
        }
        if(nth == head and p1 - p2 != n) return head->next;
        ListNode* temp = nth->next;
        if(temp != NULL)
            nth->next = temp->next;
        delete(temp);
        return head;
    }
};
