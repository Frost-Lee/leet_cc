struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
       return NULL;
    }
    struct ListNode *fast = head->next, *slow = head;
    int cycle_length = 1;
    while (fast != NULL && slow != NULL) {
        if (fast == slow) {
            fast = head;
            slow = head;
            while (cycle_length > 0) {
                fast = fast->next;
                cycle_length -= 1;
            }
            while (fast != slow) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            cycle_length += 1;
        }
    }
    return NULL;
}
