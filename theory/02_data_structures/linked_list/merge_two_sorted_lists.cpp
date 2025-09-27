//
// File        : merge_two_sorted_lists.cpp
// Author      : Hinsun
// Date        : 2025-09-27
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

/**
 * @brief Merge Two Sorted Lists
 * @details Merges two sorted linked lists and returns it as a new sorted list.
 * The new list is made by splicing together the nodes of the first two lists.
 *
 * Input:
 * 2
 * 4 5
 * 1 9 10 12
 * 2 3 7 11 15
 * 3 3
 * 1 2 4
 * 1 3 4
 *
 * Output:
 * 1 -> 2 -> 3 -> 7 -> 9 -> 10 -> 11 -> 12 -> 15
 * 1 -> 1 -> 2 -> 3 -> 4 -> 4
 */

#include <core/core.hpp>
#include <iostream>

using namespace std;
using namespace core;

Node<int> *mergeTwoSortedLists(Node<int> *l1, Node<int> *l2) {
    Node<int> *head = nullptr;

    if (isEmpty(l1))
        return l2;

    if (isEmpty(l2))
        return l1;

    Node<int> *current1 = l1;
    Node<int> *current2 = l2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->value < current2->value) {
            addToTail(head, current1->value);
            current1 = current1->next;
        } else {
            addToTail(head, current2->value);
            current2 = current2->next;
        }
    }

    while (current1 != nullptr) {
        addToTail(head, current1->value);
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        addToTail(head, current2->value);
        current2 = current2->next;
    }

    return head;
}

int main() {
    core::io();

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        Node<int> *l1 = nullptr, *l2 = nullptr;
        FOR(i, 0, n - 1) {
            int value;
            cin >> value;
            addToTail(l1, value);
        }

        FOR(i, 0, m - 1) {
            int value;
            cin >> value;
            addToTail(l2, value);
        }

        Node<int> *mergedList = mergeTwoSortedLists(l1, l2);
        printLinkedList(mergedList);
    }

    return 0;
}