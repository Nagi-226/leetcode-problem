/**
 * Note: The returned array must be malloced, assume caller calls free().
 */




int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int sLen = strlen(s);
    int wordLen = strlen(words[0]); // words 中每个字符串的长度
    int totalLen = wordLen * wordsSize; // 串联子串的总长度

    // 如果 s 的长度小于串联子串的总长度，直接返回空结果
    if (sLen < totalLen) {
        *returnSize = 0;
        return NULL;
    }

    // 分配结果数组
    int* result = (int*)malloc(sLen * sizeof(int));
    *returnSize = 0;

    // 构建 words 的哈希表
    int* wordCount = (int*)calloc(50000, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        int hash = 0;
        for (int j = 0; j < wordLen; j++) {
            hash = hash * 31 + words[i][j];
        }
        wordCount[hash]++;
    }

    // 遍历 s 中所有可能的子串
    for (int i = 0; i <= sLen - totalLen; i++) {
        int* currentCount = (int*)calloc(50000, sizeof(int));
        bool isValid = true;

        for (int j = 0; j < wordsSize; j++) {
            int startIndex = i + j * wordLen;
            int hash = 0;
            for (int k = 0; k < wordLen; k++) {
                hash = hash * 31 + s[startIndex + k];
            }
            currentCount[hash]++;

            if (currentCount[hash] > wordCount[hash]) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            result[(*returnSize)++] = i;
        }

        free(currentCount);
    }

    free(wordCount);

    return result;
}