struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* result = (head != NULL && head->next != NULL) ? head->next : head;
    struct ListNode* prev = NULL;
    while (head != NULL && head->next != NULL) {
        struct ListNode* nextHead = head->next->next;
        if (prev != NULL) {
            prev->next = head->next;
        }
        prev = head;
        head->next->next = head;
        head->next = nextHead;
        head = nextHead;
    }
    return result;
}
