struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *previous_reverse_head = NULL, *reverse_head = head;
    int current_index = 1;
    while (current_index < left) {
        previous_reverse_head = reverse_head;
        reverse_head = reverse_head->next;
        current_index += 1;
    }
    struct ListNode *previous = NULL, *current = reverse_head;
    while (current_index <= right) {
        struct ListNode *temp_next = current->next;
        current->next = previous;
        previous = current;
        current = temp_next;
        current_index += 1;
    }
    reverse_head->next = current;
    if (previous_reverse_head != NULL) {
        previous_reverse_head->next = previous;
        return head;
    } else {
        return previous;
    }
}
