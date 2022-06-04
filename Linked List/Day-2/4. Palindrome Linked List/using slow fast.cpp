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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp  =slow->next;
        ListNode* curr = NULL;
        
        while(temp){
            ListNode* next = temp->next;
            temp->next = curr;
            curr = temp;
            temp = next;
        }
        
        slow->next = curr;
        slow = slow->next;
        ListNode* start = head;
        while(slow){
            if(slow->val!=start->val)
                return false;
            
            slow = slow->next;
            start = start->next;
        }
        return true;
    }
};
