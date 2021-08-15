bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
       return false;
    }
    struct ListNode *fast = head->next, *slow = head;
    while (fast != NULL && slow != NULL) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
    }
    return false;
}
