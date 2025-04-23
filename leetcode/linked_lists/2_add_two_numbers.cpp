#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addToTail(ListNode *&head, int value) {
    ListNode *newNode = new ListNode(value);
    if (!head) {
        head = newNode;
    } else {
        ListNode *current = head;
        while (current->next)
            current = current->next;

        current->next = newNode;
    }
}

void print(ListNode *head) {
    ListNode *current = head;
    while (current) {
        cout << current->val;
        if (current->next != nullptr)
            cout << "->";
        current = current->next;
    }

    cout << endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int remain = 0;

    while (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val + remain;
        remain = sum / 10;
        sum %= 10;

        ListNode *newNode = new ListNode(sum);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {
        int sum = l1->val + remain;
        remain = sum / 10;
        sum %= 10;

        ListNode *newNode = new ListNode(sum);
        tail->next = newNode;
        tail = newNode;

        l1 = l1->next;
    }

    while (l2 != nullptr) {
        int sum = l2->val + remain;
        remain = sum / 10;
        sum %= 10;

        ListNode *newNode = new ListNode(sum);
        tail->next = newNode;
        tail = newNode;

        l2 = l2->next;
    }

    if (remain != 0) {
        ListNode *newNode = new ListNode(remain);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
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
        ListNode *l1 = nullptr, *l2 = nullptr;

        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            addToTail(l1, val);
        }
        for (int i = 0; i < m; ++i) {
            int val;
            cin >> val;
            addToTail(l2, val);
        }

        ListNode *result = addTwoNumbers(l1, l2);
        print(result);
    }

    return 0;
}
