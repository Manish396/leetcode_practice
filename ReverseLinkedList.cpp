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
    ListNode* reverseList(ListNode* head) {
        int arr[50004];
        int p = 0;
        ListNode* res = new ListNode(0);
        ListNode* node = res;
        while(head!=nullptr){
            arr[p] = head->val;
            head = head->next;
            p++;
        }
        for(int i = p-1; i>=0; i--){
            res->next = new ListNode(arr[i]);
            res = res->next;
        }
        return node->next;
    }
};
