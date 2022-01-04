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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode* prev, *curr, *next;
        prev = nullptr, curr = head, next = head->next;
        while(next) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        curr->next = prev;
        
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true; 
        auto midNode = middleNode(head);
        auto q = reverse(midNode);
        auto p = head;
        while(p and q) {
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        
        return true;
    }
};
