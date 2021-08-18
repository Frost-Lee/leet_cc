struct ListNode *middleNode(struct ListNode *head, struct ListNode **tail) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL) {
        *tail = fast;
        fast = fast->next;
        if (fast == NULL) {
            return slow;
        } else {
            *tail = fast;
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

void reverseList(struct ListNode *head) {
    if (head == NULL) {
        return;
    }
    struct ListNode *current = head, *next = head->next;
    current->next = NULL;
    while (next != NULL) {
        struct ListNode *newNext = next->next;
        next->next = current;
        current = next;
        next = newNext;
    }
}

void reorderList(struct ListNode* head) {
    if (head == NULL) {
        return;
    }
    struct ListNode *tail = NULL;
    struct ListNode *middle = middleNode(head, &tail);
    reverseList(middle);
    while (head != tail && head != NULL & tail != NULL) {
        struct ListNode *tailNext = tail->next;
        struct ListNode *headNext = head->next;
        head->next = tail;
        head = headNext;
        tail->next = head;
        tail = tailNext;
    }
}
