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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>num1;
        vector<int>num2;
        vector<int>num3;
        while(l1!=NULL){
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        ListNode* res = new ListNode(0);
        int carry = 0;
        while(!num1.empty() and !num2.empty()){
            int sum = (num1.back() + num2.back() + carry);
            carry = sum/10;
            num3.insert(num3.begin(), sum%10);
            // cout << sum << " ";
            num1.pop_back();
            num2.pop_back();
        }
        while(!num1.empty()){
            int sum = (num1.back() + carry);
            carry = sum/10;
            num3.insert(num3.begin(), sum%10);
            num1.pop_back();
        }
        while(!num2.empty()){
            int sum = (num2.back() + carry);
            carry = sum/10;
            num3.insert(num3.begin(), sum%10);
            num2.pop_back();
        }
        if(carry){
            num3.insert(num3.begin(), carry);
        }
        ListNode* temp = res;
        for(auto it: num3){
            temp->next = new ListNode(it);
            temp = temp->next;
        }
        return res->next;
    }
};
