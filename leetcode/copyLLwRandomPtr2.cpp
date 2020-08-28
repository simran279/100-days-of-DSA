/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
Example :
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
            //LINEAR TIME, CONSTANT SPACE TRICKY
        if(!head)
            return NULL;
        Node* curr= head;

        while(curr){
            Node* temp= curr->next;
            curr->next= new Node(curr->val);
            curr->next->next= temp;
            curr= temp;
        }
        curr= head;
        while(curr){
            if(curr->random)
                curr->next->random= curr->random->next;
            curr= curr->next->next;
        }
        curr= head;
        Node* temp2= head->next;
        Node* cloneHead= temp2;
        while(curr && temp2){
            if(curr->next){
                curr->next= curr->next->next;
                curr= curr->next;
            }
            if(temp2->next){
                temp2->next= temp2->next->next;
                temp2= temp2->next;
            }
        }
        return cloneHead;

    }
};
