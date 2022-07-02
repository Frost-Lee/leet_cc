struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast_pointer = head;
    struct ListNode *removal_pointer = head;
    struct ListNode *pre_removal_pointer = NULL;
    while (n > 0) {
        fast_pointer = fast_pointer->next;
        n -= 1;
    }
    while (fast_pointer != NULL) {
        fast_pointer = fast_pointer->next;
        pre_removal_pointer = removal_pointer;
        removal_pointer = removal_pointer->next;
    }
    struct ListNode *result = head;
    if (pre_removal_pointer != NULL) {
        pre_removal_pointer->next = removal_pointer->next;
        result = head;
    } else {
        result = removal_pointer->next;
    }
    return result;
}
