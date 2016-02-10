//save pointers to a vector, though not as fast as other submits, strictly one pass
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)return head;
        vector<ListNode *> ptrs;
        ListNode* tmp=head;
        while(tmp){
            ptrs.push_back(tmp);
            tmp=tmp->next;
        }
        int size=ptrs.size();
        if(size==1)return NULL;
        if(n==size)return ptrs[1];
        ptrs[size-n-1]->next=ptrs[size-n]->next;
        return head;
    }
};
