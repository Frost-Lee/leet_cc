struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* result = NULL;
    bool shouldSetResult = true;
    struct ListNode* globalPrev = NULL;
    while (countNodes(head) >= k) {
        struct ListNode* tempPrev = NULL;
        struct ListNode* tempNext = NULL;
        struct ListNode* tempGlobalPrev = head;
        for (int i = 0; i < k; i ++) {
            tempNext = head->next;
            head->next = tempPrev;
            tempPrev = head;
            head = tempNext;
        }
        head = tempPrev;
        if (globalPrev != NULL) {
            globalPrev->next = head;
        }
        globalPrev = tempGlobalPrev;
        if (shouldSetResult) {
            result = head;
            shouldSetResult = false;
        }
        head = tempNext;
    }
    if (globalPrev != NULL) {
        globalPrev->next = head;
    }
    return result;
}

int countNodes(struct ListNode* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count ++;
    }
    return count;
}
