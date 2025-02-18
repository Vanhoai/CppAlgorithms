#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Dictionary
 *
 * input:
 *      T, K, M, N
 *      1 ≤ T ≤ 10
 *      1 ≤ K ≤ 100
 *      1 ≤ M, N ≤ 3
 *
 * output: print all words can be build
 *
 * @example
 *      input:
 *          1
 *          4 3 3
 *          GEEKS FOR QUIZ GO
 *          G I Z
 *          U E K
 *          Q S E
 *      output:
 *          GEEKS QUIZ
 */

int n, m, k;
char A[1001][1001];
bool visited[1001][1001];
set<string> res;
set<string> dict;
string word;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input() {
    cin >> k >> n >> m;

    for (int i = 0; i < k; i++) {
        string w;
        cin >> w;
        dict.insert(w);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            A[i][j] = x;
        }
    }

    memset(visited, true, sizeof(visited));
}

void backtracking(int i, int j) {
    if (dict.find(word) != dict.end())
        res.insert(word);

    for (int b = 0; b < 8; b++) {
        int ix = i + dx[b];
        int jy = j + dy[b];

        if (ix >= 1 && ix <= n && jy >= 1 && jy <= m && visited[ix][jy]) {
            visited[ix][jy] = false;
            word += A[ix][jy];
            backtracking(ix, jy);
            word.pop_back();
            visited[ix][jy] = true;
        }
    }
}

void bfs(int i, int j) {
    word += A[i][j];
    if (dict.find(word) != dict.end())
        cout << word << endl;

    for (int b = 0; b < 8; b++) {
        int ix = i + dx[b];
        int jy = j + dy[b];

        if (ix >= 1 && ix <= n && jy >= 1 && jy <= m && visited[ix][jy]) {
            visited[ix][jy] = false;
            bfs(ix, jy);
            visited[ix][jy] = true;
        }
    }

    word.pop_back();
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                word = "";
                backtracking(i, j);
            }
        }

        for (auto it : res)
            cout << it << " ";

        cout << endl;
    }

    return 0;
}