/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *current = &dummy;
    int carry = 0;

    while (l1 || l2) {
        int x = (l1) ? l1->val : 0;
        int y = (l2) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        sum = sum % 10;

        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        current->next = newNode;
    }

    return dummy.next;
}