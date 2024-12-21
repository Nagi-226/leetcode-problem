#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int count[26] = {0}; // 记录每个字母出现的次数
    int visited[26] = {0}; // 记录字母是否已经在结果中
    char* stack = (char*)malloc(len + 1);
    int top = 0; // 栈顶指针

    // 统计每个字母出现的次数
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        char c = s[i];
        count[c - 'a']--; // 当前字母的剩余次数减一

        if (visited[c - 'a']) {
            continue; // 如果字母已经在结果中，跳过
        }

        // 如果栈顶字母大于当前字母，并且栈顶字母在后面还会出现，则弹出栈顶字母
        while (top > 0 && stack[top - 1] > c && count[stack[top - 1] - 'a'] > 0) {
            visited[stack[top - 1] - 'a'] = 0;
            top--;
        }

        // 将当前字母压入栈中，并标记为已访问
        stack[top++] = c;
        visited[c - 'a'] = 1;
    }

    stack[top] = '\0'; // 结束字符串
    return stack;
}

