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
    void deleteNode(ListNode* node) {
        
    // method 1 
        // while(node->next->next)
        //    { node->val = node->next->val;
        //      node = node->next; 
        //    }
        //  node->val = node->next->val;
        //  node->next = NULL;  
        *node = *node->next;   
    }
};
