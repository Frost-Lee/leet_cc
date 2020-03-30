#define MAXVAL 1000

void depthFirstSearch(struct Node *node, bool* visited, struct Node** container);
struct Node* cloneNode(struct Node* node);

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {return NULL;}
    bool visited[MAXVAL] = {};
    struct Node* nodes[MAXVAL] = {};
    depthFirstSearch(s, visited, nodes);
    for (int i = 0; i < MAXVAL; i ++) {
        if (visited[i]) {
            for (int j = 0; j < nodes[i]->numNeighbors; j ++) {
                nodes[i]->neighbors[j] = nodes[nodes[i]->neighbors[j]->val];
            }
        }
    }
    return nodes[s->val];
}

void depthFirstSearch(struct Node *node, bool* visited, struct Node** container) {
    if (visited[node->val]) {
        return;
    }
    container[node->val] = cloneNode(node);
    visited[node->val] = true;
    for (int i = 0; i < node->numNeighbors; i ++) {
        depthFirstSearch(node->neighbors[i], visited, container);
    }
}

struct Node* cloneNode(struct Node* node) {
    struct Node* clonedNode = (struct Node*)malloc(sizeof(struct Node));
    clonedNode->val = node->val;
    clonedNode->numNeighbors = node->numNeighbors;
    clonedNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    for (int i = 0; i < clonedNode->numNeighbors; i ++) {
        clonedNode->neighbors[i] = node->neighbors[i];
    }
    return clonedNode;
}
