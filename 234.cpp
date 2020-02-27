/*************************************************************************
	> File Name: 234.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/27 15:56:58 2020
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int get_length(struct ListNode *head) {
    int n = 0;
    while (head) n += 1, head = head->next;
    return n;
}

struct ListNode *get_node(struct ListNode *head, int ind) {//获取后半段代码的第一个节点
    while (ind--) head = head->next;
    return head;
}

struct ListNode *reverse(struct ListNode *head) {//翻转后半段链表
    struct ListNode ret, *p = head, *q;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head) {
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(get_node(head, (len + 1) / 2));
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
