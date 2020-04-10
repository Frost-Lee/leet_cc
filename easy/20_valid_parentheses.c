typedef struct {
    char value;
} StackNode;
typedef StackNode* StackNodePtr;

typedef struct {
    StackNodePtr array;
    int size;
    int capacity;
} Stack;
typedef Stack* StackPtr;

StackPtr createStack();
void push(StackPtr stack, StackNode element);
StackNode pop(StackPtr stack);
StackNode peek(StackPtr stack);
bool isEmpty(StackPtr stack);

StackPtr createStack() {
    StackPtr stack = (StackPtr)malloc(sizeof(Stack));
    const int initialCapacity = 8;
    stack->capacity = initialCapacity;
    stack->size = 0;
    stack->array = (StackNodePtr)malloc(sizeof(StackNode) * initialCapacity);
    return stack;
}

void push(StackPtr stack, StackNode element) {
    if (stack->size >= stack->capacity) {
        const int expandedCapacity = stack->capacity * 2;
        stack->array = realloc(stack->array, sizeof(struct TreeNode*) * expandedCapacity);
        stack->capacity = expandedCapacity;
    }
    stack->array[stack->size ++] = element;
}

StackNode pop(StackPtr stack) {
    // This method don't check whether the stack is empty.
    return stack->array[-- stack->size];
}

StackNode peek(StackPtr stack) {
    return stack->array[stack->size - 1];
}

bool isEmpty(StackPtr stack) {
    return stack->size == 0;
}

void destroy(StackPtr stack) {
    free(stack->array);
    free(stack);
}


bool isPairable(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isStackable(char a, char b) {
    return (a == '(' || a == '[' || a == '{') && (b == '(' || b == '[' || b == '{');
}


bool isValid(char * s) {
    StackPtr stack = createStack();
    while (*s != '\0') {
        StackNode newNode;
        newNode.value = *s;
        if (isEmpty(stack)) {
            push(stack, newNode);
        } else {
            if (isPairable(peek(stack).value, *s)) {
                pop(stack);
            } else if (isStackable(peek(stack).value, *s)) {
                push(stack, newNode);
            } else {
                return false;
            }
        }
        s += 1;
    }
    return isEmpty(stack);
}
