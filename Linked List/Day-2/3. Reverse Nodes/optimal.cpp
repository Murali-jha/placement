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
        
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        int size = 0;
        ListNode* temp  =head;
        while(temp){
            size++;
            temp = temp->next;
        }
        
        size  =size/k;
        temp  =head;
        while(size--){
            int n = k;
            ListNode* curr = NULL;
            ListNode* tempHead = temp;
            while(n--){
                ListNode* next  = temp->next;
                temp->next = curr;
                curr=temp;
                temp = next;
            }
            
            tempHead->next = temp;
            dummy->next = curr;
            dummy = tempHead;
        }
        return ans->next;
    }
};
