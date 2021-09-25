typedef struct {
    struct TreeNode *tree_node;
    size_t tree_parent_node_offset;
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



size_t tree_size(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return tree_size(root->left) + tree_size(root->right) + 1;
}

char* serialize(struct TreeNode* root) {
    size_t result_size = sizeof(size_t) + tree_size(root) * (sizeof(int) + sizeof(size_t) * 2);
    char *result = (char *)malloc(result_size);
    memset(result, 0, result_size);
    size_t size = tree_size(root), offset = 0;
    memcpy(result, &size, sizeof(size_t));
    offset += sizeof(size_t);
    if (root == NULL) {
        return result;
    }
    QueuePtr node_queue = createQueue();
    QueueElement root_element;
    root_element.tree_node = root;
    root_element.tree_parent_node_offset = 0;
    enqueue(node_queue, root_element);
    while (node_queue->size > 0) {
        QueueElement node = dequeue(node_queue);
        memcpy(result + offset, &(node.tree_node->val), sizeof(int));
        if (node.tree_parent_node_offset != 0) {
            memcpy(result + node.tree_parent_node_offset, &offset, sizeof(size_t));
        }
        offset += sizeof(int);
        if (node.tree_node->left != NULL) {
            QueueElement left_node;
            left_node.tree_node = node.tree_node->left;
            left_node.tree_parent_node_offset = offset;
            enqueue(node_queue, left_node);
        }
        offset += sizeof(size_t);
        if (node.tree_node->right != NULL) {
            QueueElement right_node;
            right_node.tree_node = node.tree_node->right;
            right_node.tree_parent_node_offset = offset;
            enqueue(node_queue, right_node);
        }
        offset += sizeof(size_t);
    }
    destroyQueue(node_queue);
    return result;
}

struct TreeNode *deserialize_recursive(char *data, size_t offset) {
    
    size_t left_offset, right_offset;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memcpy(&(node->val), data + offset, sizeof(int));
    memcpy(&left_offset, data + offset + sizeof(int), sizeof(size_t));
    memcpy(&right_offset, data + offset + sizeof(int) + sizeof(size_t), sizeof(size_t));
    node->left = left_offset == 0 ? NULL : deserialize_recursive(data, left_offset);
    node->right = right_offset == 0 ? NULL : deserialize_recursive(data, right_offset);
    return node;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    size_t size, offset = 0;
    memcpy(&size, data, sizeof(size_t));
    if (size == 0) {
        return NULL;
    }
    return deserialize_recursive(data, sizeof(size_t));
}
