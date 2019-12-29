/**
 * Definition for a list node.
 * struct ListNode {
 *     int val;
 *     struct ListNode* next;
 * };
 */

struct ListNode* appendNode(struct ListNode* tail, int val) {
    struct ListNode* newTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    newTail->val = val;
    newTail->next = NULL;
    if (tail != NULL) {
        tail->next = newTail;
    }
    return newTail;
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

void reduce(struct ListNode** headPtr, int* hash, int* hashPosition, char conflict) {
    char thisChar;
    do {
        thisChar = (*headPtr)->val;
        hash[(*headPtr)->val] = 0;
        hashPosition[(*headPtr)->val] = 0;
        struct ListNode* oldHead = *headPtr;
        *headPtr = (*headPtr)->next;
        free(oldHead);
    } while (thisChar != conflict);
}


int lengthOfLongestSubstring(char * s){
    int currentPosition = 0, slen = strlen(s);
    int hash[129] = {};
    int hashPosition[129] = {};
    int max = 0, localMax = 0;
    struct ListNode* ucharCacheHead = appendNode(NULL, 128);
    struct ListNode* ucharCacheTail = ucharCacheHead;
    while (currentPosition + max - localMax < slen) {
        ucharCacheTail = appendNode(ucharCacheTail, *(s + currentPosition));
        if (hash[*(s + currentPosition)] == 0) {
            localMax += 1;
            if (localMax > max) {max = localMax;}
        } else {
            int conflictPosition = hashPosition[*(s + currentPosition)];
            localMax = (currentPosition - conflictPosition);
            reduce(&ucharCacheHead, hash, hashPosition, *(s + currentPosition));
        }
        hash[*(s + currentPosition)] = 1;
        hashPosition[*(s + currentPosition)] = currentPosition;
        currentPosition += 1;
    }
    freeList(ucharCacheHead);
    return max;
}