typedef struct {
    struct TreeNode** array;
    int size;
    int capacity;
} Stack;
typedef Stack* StackPtr;

StackPtr createStack();
void push(StackPtr stack, struct TreeNode* element);
struct TreeNode* pop(StackPtr stack);
bool isEmpty(StackPtr stack);

StackPtr createStack() {
    StackPtr stack = (StackPtr)malloc(sizeof(Stack));
    const int initialCapacity = 8;
    stack->capacity = initialCapacity;
    stack->size = 0;
    stack->array = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * initialCapacity);
    return stack;
}

void push(StackPtr stack, struct TreeNode* element) {
    if (stack->size >= stack->capacity) {
        const int expandedCapacity = stack->capacity * 2;
        stack->array = realloc(stack->array, sizeof(struct TreeNode*) * expandedCapacity);
        stack->capacity = expandedCapacity;
    }
    stack->array[stack->size ++] = element;
}

struct TreeNode* pop(StackPtr stack) {
    // This method don't check whether the stack is empty.
    return stack->array[-- stack->size];
}

bool isEmpty(StackPtr stack) {
    return stack->size == 0;
}

void destroy(StackPtr stack) {
    free(stack->array);
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }
    StackPtr stack = createStack();
    long int lastValue = (long int)INT_MIN - 1;
    bool result = true;
    while (root != NULL) {
        push(stack, root);
        root = root->left;
    }
    while (!isEmpty(stack)) {
        struct TreeNode* poppedNode = pop(stack);
        if (poppedNode->val <= lastValue) {
            result = false;
            break;
        }
        lastValue = poppedNode->val;
        poppedNode = poppedNode->right;
        while (poppedNode != NULL) {
            push(stack, poppedNode);
            poppedNode = poppedNode->left;
        }
    }
    destroy(stack);
    return result;
}
