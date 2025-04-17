#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *makeNode(int value) {
    ListNode *node = new ListNode(value);
    return node;
}

void addToTail(ListNode *&head, int value) {
    if (head == nullptr)
        head = makeNode(value);
    else {
        ListNode *prev = nullptr;
        ListNode *p = head;
        while (p != nullptr) {
            prev = p;
            p = p->next;
        }

        prev->next = makeNode(value);
    }
}

void connectCycle(ListNode *&head, int pos) {
    if (pos < 0)
        return;

    int idx = 0;
    ListNode *posNode = nullptr;

    ListNode *prev = nullptr;
    ListNode *p = head;
    while (p != nullptr) {
        if (idx == pos)
            posNode = p;

        prev = p;
        p = p->next;
        idx++;
    }

    prev->next = posNode;
}

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *low = head;
    ListNode *fast = head;

    while (low != nullptr && fast != nullptr) {
        low = low->next;
        if (fast->next == nullptr)
            return false;
        fast = fast->next->next;

        if (low == fast)
            return true;
    }

    return false;
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
        int n, pos;
        cin >> n >> pos;
        vector<int> a(n);
        FOR(i, 0, n - 1) cin >> a[i];

        ListNode *head = nullptr;
        FOR(i, 0, n - 1) addToTail(head, a[i]);
        connectCycle(head, pos);
        cout << hasCycle(head) << endl;
    }

    return 0;
}
