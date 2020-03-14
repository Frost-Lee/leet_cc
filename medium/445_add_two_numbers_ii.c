int listLen(struct ListNode* list) {
    int len = 0;
    while (list != NULL) {
        list = list->next;
        len ++;
    }
    return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1->val == 0 && l2->val == 0) {
        return l1;
    }
    int* container1 = (int*)malloc(sizeof(int) * listLen(l1));
    int* container2 = (int*)malloc(sizeof(int) * listLen(l2));
    int container1Index = 0, container2Index = 0;
    while (l1 != NULL) {
        container1[container1Index ++] = l1->val;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        container2[container2Index ++] = l2->val;
        l2 = l2->next;
    }
    struct ListNode* result = NULL;
    int carry = 0;
    container1Index --;
    container2Index --;
    while (container1Index >= 0 || container2Index >= 0 || carry != 0) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        int sum = 0;
        if (container1Index >= 0 && container2Index >= 0) {
            sum = container1[container1Index] + container2[container2Index] + carry;
        } else if (container1Index >= 0) {
            sum = container1[container1Index] + carry;
        } else if (container2Index >= 0) {
            sum = container2[container2Index] + carry;
        } else {
            sum = carry;
        }
        carry = sum / 10;
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
        container1Index --;
        container2Index --;
    }
    free(container1);
    free(container2);
    return result;
}
