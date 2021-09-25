struct QueueNode {
    int value;
    struct QueueNode *next;
};
typedef struct QueueNode QueueNode;
typedef QueueNode * QueueNodePtr;

typedef struct {
    size_t queue_size;
    size_t queue_capacity;
    QueueNodePtr head;
    QueueNodePtr tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->queue_size = 0;
    queue->queue_capacity = k;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL || obj->queue_size >= obj->queue_capacity) {
        return false;
    }
    QueueNodePtr node = (QueueNodePtr)malloc(sizeof(QueueNode));
    node->next = NULL;
    node->value = value;
    if (obj->queue_size == 0) {
        obj->head = node;
    } else {
        obj->tail->next = node;
    }
    obj->tail = node;
    obj->queue_size += 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL || obj->queue_size == 0) {
        return false;
    }
    QueueNodePtr old_head = obj->head;
    obj->head = obj->head->next;
    obj->queue_size -= 1;
    if (obj->queue_size == 0) {
        obj->tail = NULL;
    }
    free(old_head);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj == NULL || obj->queue_size == 0) {
        return -1;
    }
    return obj->head->value;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj == NULL || obj->queue_size == 0) {
        return -1;
    }
    return obj->tail->value;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj == NULL || obj->queue_size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj == NULL || obj->queue_size == obj->queue_capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL) {
        return;
    }
    while (obj->head != NULL) {
        QueueNodePtr old_head = obj->head;
        obj->head = obj->head->next;
        free(old_head);
    }
    free(obj);
}
