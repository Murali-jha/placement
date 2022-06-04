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
        int sum = 0;
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        
        while(l1 || l2 || carry){
            if(l1!=NULL){
                sum += (l1->val);
                l1 = l1->next;
            }
            
            if(l2!=NULL){
                sum += (l2->val);
                l2 = l2->next;
            }
            
            sum += carry;
            
            int x = sum%10;
            carry = sum/10;
            
            prev->next = new ListNode(x);
            prev = prev->next;
            sum=0;
        }
        
        return dummy->next;
    }
};
