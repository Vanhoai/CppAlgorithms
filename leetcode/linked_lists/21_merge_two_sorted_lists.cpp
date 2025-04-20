#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode Node;

void print(Node *head) {
    Node *p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

Node *makeNode(int value) {
    Node *node = new Node(value);
    return node;
}

void addToTail(Node *&head, Node *node) {
    if (head == nullptr) {
        head = node;
    } else {
        Node *p = head;
        while (p->next != nullptr)
            p = p->next;
        p->next = node;
    }
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;

    Node *merged = nullptr;
    Node *tail = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            if (merged == nullptr) {
                merged = list1;
                tail = merged;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        } else {
            if (merged == nullptr) {
                merged = list2;
                tail = merged;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        if (merged == nullptr) {
            merged = list1;
            tail = merged;
        } else {
            tail->next = list1;
            tail = tail->next;
        }
        list1 = list1->next;
    }

    while (list2 != nullptr) {
        if (merged == nullptr) {
            merged = list2;
            tail = merged;
        } else {
            tail->next = list2;
            tail = tail->next;
        }
        list2 = list2->next;
    }

    return merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        Node *head1 = nullptr;
        Node *head2 = nullptr;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            addToTail(head1, makeNode(value));
        }

        for (int i = 0; i < m; i++) {
            int value;
            cin >> value;
            addToTail(head2, makeNode(value));
        }

        Node *merged = mergeTwoLists(head1, head2);
        Node *p = merged;
        while (p != nullptr) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    return 0;
}
