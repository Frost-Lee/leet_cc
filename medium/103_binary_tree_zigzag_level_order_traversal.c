#define LEVEL_CAPACITY 250
#define HEIGHT_CAPACITY 25

typedef struct {
    struct TreeNode* treeNodePtr;
    int height;
} QueueElement;
typedef struct QueueNode {
    QueueElement element;
    struct QueueNode* next;
} QueueNode;
typedef QueueNode* QueueNodePtr;

typedef struct {
    QueueNodePtr head;
    QueueNodePtr tail;
    int size;
} Queue;
typedef Queue* QueuePtr;

QueuePtr createQueue();
void enqueue(QueuePtr queue, QueueElement element);
QueueElement dequeue(QueuePtr queue);
void destroyQueue(QueuePtr queue);

QueuePtr createQueue() {
    QueuePtr result = (QueuePtr)malloc(sizeof(Queue));
    result->size = 0;
    result->head = NULL;
    result->tail = NULL;
    return result;
}

void enqueue(QueuePtr queue, QueueElement element) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    newNode->element = element;
    newNode->next = NULL;
    if (queue->size == 0) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size += 1;
}

QueueElement dequeue(QueuePtr queue) {
    // Assume the queue is not empty
    QueueElement result = queue->head->element;
    QueueNodePtr tempHead = queue->head;
    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }
    free(tempHead);
    queue->size -= 1;
    return result;
}

void destroyQueue(QueuePtr queue) {
    while (queue->head != NULL) {
        QueueNodePtr tempHead = queue->head;
        queue->head = queue->head->next;
        free(tempHead);
    }
    free(queue);
}

QueueElement getQueueElement(struct TreeNode* treeNodePtr, int height) {
    QueueElement result;
    result.treeNodePtr = treeNodePtr;
    result.height = height;
    return result;
}

void reverse(int* array, int size) {
    if (size <= 0) {return;}
    int head = 0, tail = size - 1;
    while (head < tail) {
        int temp = array[head];
        array[head ++] = array[tail];
        array[tail --] = temp;
    }
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * HEIGHT_CAPACITY);
    int levelSizes[HEIGHT_CAPACITY] = {};
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    QueuePtr queue = createQueue();
    enqueue(queue, getQueueElement(root, 0));
    while (queue->size > 0) {
        QueueElement newElement = dequeue(queue);
        if (*returnSize <= newElement.height) {
            levelSizes[*returnSize] = 0;
            result[(*returnSize) ++] = (int*)malloc(sizeof(int) * LEVEL_CAPACITY);
        }
        result[newElement.height][levelSizes[newElement.height] ++] = newElement.treeNodePtr->val;
        if (newElement.treeNodePtr->left != NULL) {
            enqueue(queue, getQueueElement(newElement.treeNodePtr->left, newElement.height + 1));
        }
        if (newElement.treeNodePtr->right != NULL) {
            enqueue(queue, getQueueElement(newElement.treeNodePtr->right, newElement.height + 1));
        }
    }
    for (int i = 1; i < *returnSize; i += 2) {
        reverse(result[i], levelSizes[i]);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i ++) {
        (*returnColumnSizes)[i] = levelSizes[i];
    }
    destroyQueue(queue);
    return result;
}
