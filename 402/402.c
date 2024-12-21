#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k == len) return "0"; // 如果移除的位数等于数字的长度，返回 "0"
    
    char* stack = (char*)malloc(len + 1);
    int top = 0; // 栈顶指针
    
    for (int i = 0; i < len; i++) {
        while (top > 0 && stack[top - 1] > num[i] && k > 0) {
            top--; // 弹出栈顶元素
            k--;
        }
        stack[top++] = num[i]; // 将当前数字压入栈中
    }
    
    // 如果还有未移除的位数，继续从栈顶移除
    top -= k;
    
    // 去除前导零
    int idx = 0;
    while (idx < top && stack[idx] == '0') {
        idx++;
    }
    
    // 如果栈为空，返回 "0"
    if (idx == top) return "0";
    
    // 构建结果字符串
    stack[top] = '\0';
    return stack + idx;
}

