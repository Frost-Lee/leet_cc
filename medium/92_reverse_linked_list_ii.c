struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    size_t index = 1;
    struct ListNode *old_head = head;
    struct ListNode *prev = NULL, *next = NULL;
    struct ListNode *start = NULL, *start_prev = NULL;
    while (index <= right) {
        next = head->next;
        if (index == left - 1) {
            start_prev = head;
        } else if (index == left) {
            start = head;
        } else if (index > left) {
            head->next = prev;
        }
        prev = head;
        head = next;
        index += 1;
    }
    if (start_prev != NULL) {
        start_prev->next = prev;
    }
    start->next = next;
    if (left == 1) {
        return prev;
    } else {
        return old_head;
    }
}
