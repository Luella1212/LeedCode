/*************************************************************************
	> File Name: LeetCode237.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/28 16:49:12 2020
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
    return ;
}
