typedef struct {
    int index;
    int value;
} HeapNode;
typedef HeapNode* HeapNodePtr;

typedef struct {
    HeapNodePtr array;
    int size;
    int capacity;
} Heap;
typedef Heap * HeapPtr;

HeapPtr buildHeap(HeapNodePtr elements, int size);
void destroyHeap(HeapPtr heap);
void pushHeap(HeapPtr heap, HeapNode newElement);
HeapNode popHeap(HeapPtr heap);
void percolateUp(HeapPtr heap, int index);
void percolateDown(HeapPtr heap, int index);

HeapPtr buildHeap(HeapNodePtr elements, int size) {
    HeapPtr result = (HeapPtr)malloc(sizeof(Heap));
    result->size = size;
    result->array = (HeapNodePtr)malloc(sizeof(HeapNode) * (size + 1));
    result->capacity = size + 1;
    for (int i = 0; i < size; i ++) {
        result->array[i + 1] = elements[i];
    }
    for (int i = size / 2; i > 0; i --) {
        percolateDown(result, i);
    }
    return result;
}

void destroyHeap(HeapPtr heap) {
    free(heap->array);
    free(heap);
}

void pushHeap(HeapPtr heap, HeapNode newElement) {
    if (heap->size >= heap->capacity - 1) {
        heap->array = realloc(heap->array, sizeof(HeapNode) * heap->capacity * 2);
        heap->capacity *= 2;
    }
    heap->array[++ heap->size] = newElement;
    percolateUp(heap, heap->size);
}

HeapNode popHeap(HeapPtr heap) {
    HeapNode result = heap->array[1];
    heap->array[1] = heap->array[heap->size --];
    percolateDown(heap, 1);
    return result;
}

void percolateUp(HeapPtr heap, int index) {
    HeapNode targetNode = heap->array[index];
    int i = 0;
    for (i = index; i / 2 >= 1 && heap->array[i / 2].value > targetNode.value; i /= 2) {
        heap->array[i] = heap->array[i / 2];
    }
    heap->array[i] = targetNode;
}

void percolateDown(HeapPtr heap, int index) {
    HeapNode targetNode = heap->array[index];
    int i = index, childIndex = index;
    for (i = index; i * 2 <= heap->size; i = childIndex) {
        childIndex = i * 2;
        if (childIndex < heap->size && heap->array[childIndex + 1].value < heap->array[childIndex].value) {
            childIndex += 1;
        }
        if (targetNode.value > heap->array[childIndex].value) {
            heap->array[i] = heap->array[childIndex];
        } else {
            break;
        }
    }
    heap->array[i] = targetNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    HeapPtr heap = buildHeap(NULL, 0);
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode* resultTail = result;
    struct ListNode** listCurrentPositionPointers = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    int resultSize = 0;
    for (int i = 0; i < listsSize; i ++) {
        if (lists[i] != NULL) {
            HeapNode newNode;
            newNode.index = i;
            newNode.value = lists[i]->val;
            pushHeap(heap, newNode);
            listCurrentPositionPointers[i] = lists[i];
        } else {
            listCurrentPositionPointers[i] = NULL;
        }
    }
    while (heap->size > 0) {
        resultTail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        resultTail = resultTail->next;
        HeapNode topNode = popHeap(heap);
        resultTail->val = topNode.value;
        resultTail->next = NULL;
        if (listCurrentPositionPointers[topNode.index]->next != NULL) {
            listCurrentPositionPointers[topNode.index] = listCurrentPositionPointers[topNode.index]->next;
            HeapNode newNode = topNode;
            newNode.value = listCurrentPositionPointers[topNode.index]->val;
            pushHeap(heap, newNode);
        }
    }
    free(listCurrentPositionPointers);
    destroyHeap(heap);
    return result->next;
}
