struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *odd_current = head, *even_current = head->next, *even_head = head->next;
    while (even_current != NULL && even_current->next != NULL) {
        odd_current->next = even_current->next;
        odd_current = odd_current->next;
        even_current->next = odd_current->next;
        even_current = even_current->next;
    }
    odd_current->next = even_head;
    return head;
}
