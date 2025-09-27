//
// File        : operators.cpp
// Author      : Hinsun
// Date        : 2025-09-27
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Demonstrates operator overloading for a singly linked list in C++.
 *
 * This file contains the implementation of a singly linked list with overloaded
 * operators for assignment, addition, and output. The linked list supports deep
 * copying and concatenation of two lists.
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

void addToPosition(Node<int> *&head, const int value, const int position) {
    if (position == 0 || isEmpty(head)) {
        addToHead(head, value);
        return;
    }

    Node<int> *node = makeNode(value);
    Node<int> *temp = head;
    for (int i = 0; i < position - 1 && temp->next != nullptr; i++)
        temp = temp->next;

    node->next = temp->next;
    temp->next = node;
}

void removeHead(Node<int> *&head) {
    if (isEmpty(head))
        return;

    Node<int> *temp = head;
    head = head->next;

    delete temp;
}

void removeTail(Node<int> *&head) {
    if (isEmpty(head))
        return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<int> *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void removeNodeInPosition(Node<int> *&head, const int position) {
    if (isEmpty(head))
        return;

    if (position == 0)
        return removeHead(head);

    Node<int> *temp = head;
    for (int i = 0; i < position - 1 && temp->next != nullptr; i++)
        temp = temp->next;

    if (temp->next == nullptr)
        return;

    Node<int> *nodeDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeDelete;
}

void print(Node<int> *head) {
    if (isEmpty(head))
        return;

    const Node<int> *temp = head;
    while (temp != nullptr) {
        std::cout << temp->value;
        temp = temp->next;

        if (temp != nullptr)
            std::cout << " -> ";
    }

    std::cout << "\n";
}

int main() {
    core::io();

    Node<int> *head = nullptr;
    addToTail(head, 10);
    addToTail(head, 20);
    addToTail(head, 30);
    addToTail(head, 40);
    addToHead(head, 0);
    addToPosition(head, 50, 3);

    removeHead(head);
    removeTail(head);

    print(head);
    removeNodeInPosition(head, 4);
    print(head);

    return 0;
}
