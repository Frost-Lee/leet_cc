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

typedef struct {
    StackPtr stack;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* iterator = (BSTIterator*)malloc(sizeof(BSTIterator));
    iterator->stack = createStack();
    while (root != NULL) {
        push(iterator->stack, root);
        root = root->left;
    }
    return iterator;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* resultNode = pop(obj->stack);
    struct TreeNode* nextNode = resultNode->right;
    while (nextNode != NULL) {
        push(obj->stack, nextNode);
        nextNode = nextNode->left;
    }
    return resultNode->val;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    return !isEmpty(obj->stack);
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack->array);
    free(obj->stack);
    free(obj);
}
