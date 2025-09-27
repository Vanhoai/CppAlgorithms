//
// File        : detect_cycle.cpp
// Author      : Hinsun
// Date        : 2025-09-27
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Floyd's Cycle-Finding Algorithm
 * @details Detects cycles in a linked list using the Tortoise and Hare
 * algorithm.
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

bool hasCycle(Node<int> *head) {
    if (isEmpty(head) || head->next == nullptr)
        return false;

    Node<int> *slow = head;
    Node<int> *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    core::io();

    Node<int> *head = nullptr;
    Node<int> *node1 = makeNode(1);
    Node<int> *node2 = makeNode(2);
    Node<int> *node3 = makeNode(3);
    Node<int> *node4 = makeNode(4);
    Node<int> *node5 = makeNode(5);
    Node<int> *node6 = makeNode(6);
    Node<int> *node7 = makeNode(7);
    Node<int> *node8 = makeNode(8);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    // Make a cycle for testing
    node8->next = node4;

    if (hasCycle(head))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}