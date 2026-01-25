#include "TestHarness.h"
#include <unordered_map>

using namespace std;

class LRUCache {
    struct Node {
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    const int MAX_CAP_;
    unordered_map<int, Node*> store;
    Node *sentinel;

public:
    LRUCache(int capacity) : MAX_CAP_(capacity) {
        sentinel = new Node(-1, -1);
    }

    void insert(Node *node) {
        if (node == sentinel->next) return;
        node->prev = sentinel->next;
        if (sentinel->next) {
            sentinel->next->next = node;
        } else {
            sentinel->prev = node;
        }
        sentinel->next = node;
    }

    void remove(Node *node) {
        if (store.size() == 1) {
            sentinel->next = nullptr;
            sentinel->prev= nullptr;
            return;
        }
        Node *prev_node = node->prev;
        Node *next_node = node->next;
        if (prev_node) {
            prev_node->next = next_node;
        } else {
            sentinel->prev = next_node;
        }

        if (next_node) {
            next_node->prev = prev_node;
        } else {
            sentinel->next = prev_node;
        }
    }

    int get(int key) {
        if (store.find(key) != store.end()) {
            Node *node = store[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (store.find(key) != store.end()) {
            Node *node = store[key];
            remove(node);
            insert(node);
            node->val = value;
            return;
        }

        Node *new_node = new Node(key, value);
        store[key] = new_node;
        insert(new_node);

        if (store.size() > MAX_CAP_) {
            Node *node = sentinel->prev;
            remove(node);
            store.erase(node->key);
            delete node;
        }
    }
};

const int NULL_RET = -999;

int main() {

    // Test Case 2: Complex LRU Eviction Logic
    // Sequence:
    // 1.  put(1,1), put(2,2), put(3,3) -> State: [3, 2, 1] (MRU->LRU)
    // 2.  get(1), get(2)               -> State: [2, 1, 3]
    // 3.  get(4) -> -1
    // 4.  put(4,4)                     -> State: [4, 2, 1, 3] (Full Capacity 4)
    // 5.  get(1), get(2), get(3), get(4) -> State: [4, 3, 2, 1]
    // 6.  get(2)                       -> State: [2, 4, 3, 1] (1 is now LRU)
    // 7.  put(5,5)                     -> Evicts 1. State: [5, 2, 4, 3]
    // 8.  get(1)                       -> Returns -1
    // ... subsequent checks verify 5 exists and 1 is gone.

    std::vector<int> expected_complex = {
        NULL_RET, NULL_RET, NULL_RET, NULL_RET, // Init, put 1,2,3
        1, 2, -1, NULL_RET,                     // get 1,2, 4(miss), put 4
        1, 2, 3, 4, 2, NULL_RET,                // get 1,2,3,4, 2, put 5
        -1, 2, 3, 4, 5,                         // get 1(miss), 2,3,4,5
        2, 3, 4, NULL_RET,                      // get 2,3,4, put 6
        -1, 2, 3, 4, -1, 6                      // get 1(miss), 2,3,4, 5(miss), 6
    };

    runTest("Complex LRU Logic", []() {
        std::vector<int> results;
        LRUCache* obj = new LRUCache(4);
        results.push_back(NULL_RET); // Init

        obj->put(1, 1); results.push_back(NULL_RET);
        obj->put(2, 2); results.push_back(NULL_RET);
        obj->put(3, 3); results.push_back(NULL_RET);

        results.push_back(obj->get(1));
        results.push_back(obj->get(2));
        results.push_back(obj->get(4));

        obj->put(4, 4); results.push_back(NULL_RET);

        results.push_back(obj->get(1));
        results.push_back(obj->get(2));
        results.push_back(obj->get(3));
        results.push_back(obj->get(4));
        results.push_back(obj->get(2)); // Critical: moves 2 to MRU, making 1 LRU

        obj->put(5, 5); results.push_back(NULL_RET); // Should evict 1

        results.push_back(obj->get(1)); // Should be -1
        results.push_back(obj->get(2));
        results.push_back(obj->get(3));
        results.push_back(obj->get(4));
        results.push_back(obj->get(5));

        results.push_back(obj->get(2));
        results.push_back(obj->get(3));
        results.push_back(obj->get(4));

        obj->put(6, 6); results.push_back(NULL_RET); // Should evict 5 (LRU was 5)

        results.push_back(obj->get(1));
        results.push_back(obj->get(2));
        results.push_back(obj->get(3));
        results.push_back(obj->get(4));
        results.push_back(obj->get(5)); // Should be -1
        results.push_back(obj->get(6));

        delete obj;
        return results;
    }, expected_complex);

    // Test Case: ["LRUCache", [2], "put", [1, 10], "get", [1], "put", [2, 20], "put", [3, 30], "get", [2], "get", [1]]
    // Expected logic:
    // 1. Init(2)   -> null
    // 2. put(1,10) -> null      State: {1=10}
    // 3. get(1)    -> 10        State: {1=10} (1 is MRU)
    // 4. put(2,20) -> null      State: {1=10, 2=20} (2 is MRU)
    // 5. put(3,30) -> null      State: {2=20, 3=30} (1 is evicted as LRU)
    // 6. get(2)    -> 20        State: {3=30, 2=20} (2 is MRU)
    // 7. get(1)    -> -1        (1 was evicted)

    // Expected Vector: [null, null, 10, null, null, 20, -1]
    std::vector<int> expected = {NULL_RET, NULL_RET, 10, NULL_RET, NULL_RET, 20, -1};

    runTest("LeetCode Example 1", []() {
        std::vector<int> results;

        // 1. LRUCache(2)
        LRUCache* obj = new LRUCache(2);
        results.push_back(NULL_RET);

        // 2. put(1, 10)
        obj->put(1, 10);
        results.push_back(NULL_RET);

        // 3. get(1)
        results.push_back(obj->get(1));

        // 4. put(2, 20)
        obj->put(2, 20);
        results.push_back(NULL_RET);

        // 5. put(3, 30)
        obj->put(3, 30);
        results.push_back(NULL_RET);

        // 6. get(2)
        results.push_back(obj->get(2));

        // 7. get(1)
        results.push_back(obj->get(1));

        // Clean up memory (optional in test, but good practice)
        // Note: Your LRUCache currently lacks a destructor, so this only deletes the shell.
        delete obj;

        return results;
    }, expected);

    return 0;
}


