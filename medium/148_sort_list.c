struct ListNode *split_list(struct ListNode *head) {
    struct ListNode *middle = head;
    while (head != NULL) {
        head = head->next;
        if (head != NULL) {
            head = head->next;
        }
        struct ListNode *previous_middle = middle;
        middle = middle->next;
        if (head == NULL) {
            previous_middle->next = NULL;
        }
    }
    return middle;
}

struct ListNode *merge_list(struct ListNode *left, struct ListNode *right) {
    struct ListNode dummy_head;
    struct ListNode *result = &dummy_head, *current_node = &dummy_head;
    while (left != NULL && right != NULL) {
        if (left->val > right->val) {
            current_node->next = right;
            right = right->next;
            current_node = current_node->next;
        } else {
            current_node->next = left;
            left = left->next;
            current_node = current_node->next;
        }
    }
    current_node->next = (left != NULL) ? left : right;
    return result->next;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *middle = split_list(head);
    if (middle == NULL) {
        return head;
    }
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(middle);
    return merge_list(left, right);
}
