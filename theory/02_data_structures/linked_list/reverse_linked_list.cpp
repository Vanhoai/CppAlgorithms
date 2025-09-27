//
// File        : reverse_linked_list.cpp
// Author      : Hinsun
// Date        : 2025-09-27
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Reverse a Linked List
 * @details Given the head of a singly linked list, reverse the list, and return
 * the reversed list.
 *
 * Input:
 * 3
 * 5
 * 1 2 3 4 5
 * 7
 * 4 2 4 1 5 8 9
 * 1
 * 10
 *
 * Output:
 * 5 -> 4 -> 3 -> 2 -> 1
 * 9 -> 8 -> 5 -> 1 -> 4 -> 2 -> 4
 * 10
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

void reverse(Node<int> *&head) {
    Node<int> *prev = nullptr;
    Node<int> *next = nullptr;

    Node<int> *current = head;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
}

void reverseRecursive(Node<int> *&head) {
    if (isEmpty(head) || head->next == nullptr)
        return;

    Node<int> *first = head;
    Node<int> *rest = head->next;

    reverseRecursive(rest);
    first->next->next = first;
    first->next = nullptr;

    head = rest;
}

int main() {
    core::io();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        Node<int> *head = nullptr;
        FOR(i, 0, n - 1) {
            int value;
            cin >> value;
            addToTail(head, value);
        }

        reverse(head);
        printLinkedList(head);
    }

    return 0;
}