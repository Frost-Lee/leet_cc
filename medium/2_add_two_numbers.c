/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* appendNode(struct ListNode** prev, int val) {
    struct ListNode* rstNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    rstNode->val = val;
    rstNode->next = NULL;
    if (prev != NULL) {
        (*prev)->next = rstNode;
    }
    return rstNode;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode* dummyRoot = appendNode(NULL, 0);
    struct ListNode* thisNode = dummyRoot;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int l1Value = l1 != NULL ? l1->val : 0;
        int l2Value = l2 != NULL ? l2->val : 0;
        if (l1Value + l2Value + carry >= 10) {
            thisNode = appendNode(&thisNode, l1Value + l2Value + carry - 10);
            carry = 1;
        } else {
            thisNode = appendNode(&thisNode, l1Value + l2Value + carry);
            carry = 0;
        }
        if (l1 != NULL) {l1 = l1->next;}
        if (l2 != NULL) {l2 = l2->next;}
    }
    return dummyRoot->next;
}