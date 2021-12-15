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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            ListNode *n = new ListNode(0);
            return n->next;
        }
        int i = 0;
        while(i < n && lists[i]==nullptr){
            i++;
        }
        if(i == n){
            return lists[i-1];
        }
        ListNode *res = lists[i];
        ListNode *node = res;
        i++;
        for( ; i < n; i++){
            node = res;
            while(lists[i]!= nullptr){
                int d = lists[i]->val;
                if(d <= node->val){
                    ListNode *temp = new ListNode(d);
                    temp->next = node;
                    res = temp;
                    node = temp;
                }
                else{
                    ListNode *temp;
                    while(node!=nullptr && node->val <= d){
                        temp = node;
                        node = node->next;
                    }
                    temp->next = new ListNode(lists[i]->val);
                    temp->next->next = node;
                    node = temp;
                }
                lists[i] = lists[i]->next;
                node = res;
            }
        }
        return res;
    }
};
