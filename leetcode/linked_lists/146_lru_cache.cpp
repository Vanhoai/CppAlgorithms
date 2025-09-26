#include <iostream>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;

        explicit Node(int k = 0, int v = 0)
            : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int size;
    int capacity;
    Node *head, *tail;
    std::unordered_map<int, Node *> cache;

    // Add node right after head
    void addNode(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // Remove an existing node from the linked list
    static void removeNode(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move certain node to the head
    void moveToHead(Node *node) {
        removeNode(node);
        addNode(node);
    }

    // Pop the current tail
    Node *popTail() {
        Node *lastNode = tail->prev;
        removeNode(lastNode);
        return lastNode;
    }

public:
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node *curr = head;
        while (curr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        // Key found, move the node to head (mark as recently used)
        Node *node = it->second;
        moveToHead(node);

        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            Node *newNode = new Node(key, value);

            cache[key] = newNode;
            addNode(newNode);

            ++size;

            if (size > capacity) {
                // Pop the tail (least recently used)
                Node *tail_node = popTail();
                cache.erase(tail_node->key);
                delete tail_node;
                --size;
            }
        } else {
            Node *node = it->second;
            node->value = value;
            moveToHead(node);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    LRUCache cache(2);
    cache.put(1, 1);                          // cache is {1=1}
    cache.put(2, 2);                          // cache is {1=1, 2=2}
    std::cout << cache.get(1) << std::endl;   // return 1

    // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cache.put(3, 3);

    std::cout << cache.get(2) << std::endl;   // returns -1 (not found)

    // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cache.put(4, 4);

    std::cout << cache.get(1) << std::endl;   // return -1 (not found)
    std::cout << cache.get(3) << std::endl;   // return 3
    std::cout << cache.get(4) << std::endl;   // return 4

    return 0;
}
