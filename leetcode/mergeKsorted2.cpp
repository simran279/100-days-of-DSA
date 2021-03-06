/*
Given an array of linked-lists lists, each linked list is sorted in ascending order.
Merge all the linked-lists into one sort linked-list and return it.
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(int i=0; i<lists.size(); i++){
            ListNode* head= lists[i];
            while(head){
                v.push_back(head->val);
                head= head->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        for(int i=0; i<v.size(); i++){
            curr->next= new ListNode(v[i]);
            curr= curr->next;
        }
        curr= dummy->next;
        delete dummy;
        return curr;
    }
};
