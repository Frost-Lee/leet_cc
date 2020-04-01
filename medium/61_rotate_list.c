struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) {return NULL;}
    int listLength = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        listLength ++;
    }
    tail->next = head;
    for (int i = 0; i < listLength - k % listLength - 1; i ++) {
        head = head->next;
    }
    struct ListNode* newHead = head->next;
    head->next = NULL;
    return newHead;
}
