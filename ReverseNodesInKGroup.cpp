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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int arr[k];
		int p = 0;
		ListNode *res = new ListNode(0);
		ListNode *node = res;
		while(head!=nullptr){
			if(p < k){
				arr[p] = head->val;
				p++;
			}
			if(p == k){
				for(int it = p-1; it>=0; it--){
					res->next = new ListNode(arr[it]);
					res = res->next;
				}
				p = 0;
			}
			head = head->next;
		}
		if(p>0){
			for(int it = 0; it < p; it++){
				res->next = new ListNode(arr[it]);
				res = res->next;
			}
		}
		return node->next;
    }
};
