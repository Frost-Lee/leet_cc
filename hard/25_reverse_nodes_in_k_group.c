struct ListNode *reverseTopK(struct ListNode *head, int k, struct ListNode **seg_head, struct ListNode **seg_tail) {
    struct ListNode *prev = NULL, *next = NULL;
    size_t length = 0;
    *seg_tail = head;
    while (length < k) {
        if (head == NULL) {
            return reverseTopK(prev, length, seg_head, seg_tail);
        }
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        length += 1;
    }
    *seg_head = prev;
    (*seg_tail)->next = head;
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *seg_head = NULL, *seg_tail = NULL;
    struct ListNode *old_seg_tail = NULL;
    struct ListNode *result = NULL;
    while (head != NULL) {
        struct ListNode *x = result;
        head = reverseTopK(head, k, &seg_head, &seg_tail);
        if (old_seg_tail != NULL) {
            old_seg_tail->next = seg_head;
        }
        old_seg_tail = seg_tail;
        if (result == NULL) {
            result = seg_head;
        }
    }
    return result;
}
