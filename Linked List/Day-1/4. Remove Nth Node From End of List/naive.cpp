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
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp  =temp->next;
        }
        size -= n;
        
        if(size==0)
            return head->next;
        
        temp = head;
        size--;
        while(size--){
            temp = temp->next;
        }
        
        if(temp->next && temp->next->next){
            temp->next = temp->next->next;
        }
        else{
            temp->next=NULL;
        }
        return head;
    }
};
