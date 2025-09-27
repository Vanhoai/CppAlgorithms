//
// File        : intersection.cpp
// Author      : Hinsun
// Date        : 2025-09-27
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Intersection of Two Linked Lists
 * @details Given the heads of two singly linked-lists headA and headB, return
 * the node at which the two lists intersect. If the two linked lists have no
 * intersection at all, return null.
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

int countNodes(Node<int> *head) {
    int count = 0;
    Node<int> *current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

Node<int> *intersectionNodeByDiff(const int diff, Node<int> *headA,
                                  Node<int> *headB) {

    Node<int> *currentA = headA;
    Node<int> *currentB = headB;

    // Move the pointer of the longer list by 'diff' nodes
    FOR(i, 0, diff - 1) {
        if (currentA == nullptr)
            return nullptr;

        currentA = currentA->next;
    }

    // Traverse both lists together until we find the intersection point
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA == currentB)
            return currentA;

        currentA = currentA->next;
        currentB = currentB->next;
    }

    return nullptr;
}

Node<int> *intersectionNode(Node<int> *headA, Node<int> *headB) {
    if (isEmpty(headA) || isEmpty(headB))
        return nullptr;

    int countA = countNodes(headA);
    int countB = countNodes(headB);

    if (countA > countB) {
        const int diff = countA - countB;
        return intersectionNodeByDiff(diff, headA, headB);
    } else {
        const int diff = countB - countA;
        return intersectionNodeByDiff(diff, headB, headA);
    }
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
    Node<int> *node9 = makeNode(9);
    Node<int> *node10 = makeNode(10);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node4;

    node4->next = node9;
    node9->next = node10;

    Node<int> *intersection = intersectionNode(head, node5);
    if (intersection != nullptr)
        cout << intersection->value;
    else
        cout << "NO INTERSECTION";

    return 0;
}