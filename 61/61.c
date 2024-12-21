/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体

// 获取链表的长度
int getLength(struct ListNode* head) {
    int length = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// 主旋转函数
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // 获取链表的长度
    int length = getLength(head);
    
    // 由于旋转是循环的，k的值可以通过对长度取模来减少
    k = k % length;
    
    // 如果k为0，表示旋转后链表不变
    if (k == 0) {
        return head;
    }

    // 找到倒数第k个节点，断开链表
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    // 移动fast指针k步
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
    
    // 移动fast和slow指针直到fast到达链表末尾
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow指向的新尾节点
    struct ListNode* newHead = slow->next;
    slow->next = NULL;  // 断开链表
    fast->next = head;  // 将尾部连接到头部
    
    return newHead;
}