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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroup = dummy;

        while(1){
            ListNode* groupEnd = prevGroup;
            for(int i =0;i<k;i++){
                groupEnd= groupEnd->next;
                if(groupEnd==nullptr) return dummy->next;
            }
            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroup = groupEnd->next;

            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while(curr!=nextGroup){
                ListNode* temp = curr->next;
                curr->next= prev;
                prev= curr;
                curr=temp;
            }

            prevGroup->next= groupEnd;
            groupStart->next= nextGroup;
            prevGroup = groupStart;

        }
        return dummy->next;
    }
};