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
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        if(head==NULL || head->next==NULL)
            return head;
        int size = 0;
        ListNode* temp = head;
        ListNode* last;
        while(temp){
            last = temp;
            temp = temp->next;
            size++;
        }
        
        k  = k%size;
        if(k>0){
            last->next = head;
        }
        else{
            return head;
        }
        
        temp = head;
        
        int n = size - k - 1;
        while(n--){
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};
