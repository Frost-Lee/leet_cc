struct ListNode *front = NULL;

bool isPalindromeRecursive(struct ListNode *end) {
    if (end == NULL) {
        return true;
    }
    if (!isPalindromeRecursive(end->next) || front->val != end->val) {
        return false;
    }
    front = front->next;
    return true;
}

bool isPalindrome(struct ListNode* head) {
    front = head;
    return isPalindromeRecursive(head);
}
