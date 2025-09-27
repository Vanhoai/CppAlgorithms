//
// File        : core.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#include <core/core.hpp>
#include <vector>

namespace core {

Node<int> *makeNode(const int value) { return new Node<int>(value); }

bool isEmpty(Node<int> *head) { return head == nullptr; }

void addToHead(Node<int> *&head, const int value) {
    Node<int> *newNode = makeNode(value);

    if (isEmpty(head)) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void addToTail(Node<int> *&head, const int value) {
    Node<int> *newNode = makeNode(value);

    if (isEmpty(head)) {
        head = newNode;
        return;
    }

    Node<int> *current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = newNode;
}

void printLinkedList(Node<int> *head) {
    Node<int> *current = head;

    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr)
            std::cout << " -> ";
        current = current->next;
    }

    std::cout << "\n";
}

}   // namespace core
