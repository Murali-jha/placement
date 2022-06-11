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




struct compare{
    bool operator()(ListNode* p1,ListNode* p2){
        return p1->val>p2->val;
    }
};


class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(auto it:lists){
            if(it){
                pq.push(it);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            dummy->next = new ListNode(temp->val);
            dummy = dummy->next;
            if(temp->next){
                pq.push(temp->next);
            }
            
        }
        return ans->next;
        
    }
};
