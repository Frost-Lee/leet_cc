struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pointer_a = headA, *pointer_b = headB;
    while (pointer_a != pointer_b) {
        pointer_a = pointer_a == NULL ? headB : pointer_a->next;
        pointer_b = pointer_b == NULL ? headA : pointer_b->next;
    }
    return pointer_a;
}
