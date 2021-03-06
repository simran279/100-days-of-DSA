/*
Given a linked list, remove the n-th node from the end of list and return its head.
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode(0);
        dummy->next= head;

        ListNode* fast= dummy;
        ListNode* slow= dummy;

        for(int i=1; i<=n+1; i++){
            fast= fast->next;
        }
        while(fast != NULL){
            slow= slow->next;
            fast= fast->next;
        }

        slow->next= slow->next->next;
        return dummy->next;
}
