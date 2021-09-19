typedef struct Node * QueueElement;
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

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    QueuePtr bfs_queue = createQueue();
    enqueue(bfs_queue, root);
    while (bfs_queue->size > 0) {
        int level_node_count = bfs_queue->size;
        for (size_t i = 0; i < level_node_count; i ++) {
            struct Node *visited_node = dequeue(bfs_queue);
            if (i < level_node_count - 1) {
                visited_node->next = bfs_queue->head->element;
            }
            if (visited_node->left != NULL) {
                enqueue(bfs_queue, visited_node->left);
            }
            if (visited_node->right != NULL) {
                enqueue(bfs_queue, visited_node->right);
            }
        }
    }
    destroyQueue(bfs_queue);
    return root;
}
