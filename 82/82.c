#include <stdio.h>
#include <stdlib.h>


// 删除排序链表中的所有重复数字的节点
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // 创建一个虚拟头节点，方便处理头节点删除的情况
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;  // prev指向当前链表的有效节点
    
    while (head != NULL) {
        // 如果当前节点与下一个节点的值相同，跳过所有重复节点
        if (head->next != NULL && head->val == head->next->val) {
            // 找到所有相同的节点
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;  // 跳过重复节点
            }
            // 跳过重复的节点，指向下一个不重复的节点
            prev->next = head->next;
        } else {
            // 当前节点与下一个节点不同，继续向后移动
            prev = prev->next;
        }
        // 向后移动
        head = head->next;
    }
    
    // 返回结果链表，虚拟头节点的 next 即是处理后的链表头
    struct ListNode* result = dummy->next;
    free(dummy);  // 释放虚拟头节点
    return result;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// 辅助函数：创建一个链表
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    for (int i = 0; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
    }
    struct ListNode* result = head->next;
    free(head);  // 释放虚拟头节点
    return result;
}

