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
    ListNode* mergeNodes(ListNode* head) {
        head= head->next;
        if(head== NULL){
            return head;
        }

        ListNode* temp= head;
        int s=0;
        while(temp->val!=0){
            s+=temp->val;
            temp= temp->next;
        }

        head->val= s;
        head->next = mergeNodes(temp);
        return head;
    }
};