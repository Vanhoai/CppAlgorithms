#include <iostream>
#include <string>
using namespace std;

string simplifyPath(string path) {
    string result = "/";
    int i = 1;
    while (i < path.length()) {
        if (path[i] == '/') {
            i++;
            continue;
        }
        string dir = "";
        while (i < path.length() && path[i] != '/') {
            dir += path[i];
            i++;
        }
        if (dir == "..") {
            if (result.length() > 1) {
                result.pop_back();
                while (result.back() != '/')
                    result.pop_back();
            }
        } else if (dir != ".")
            result += dir + "/";
    }

    if (result.length() > 1)
        result.pop_back();

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string path;
        getline(cin, path);
        cout << simplifyPath(path) << endl;
    }

    return 0;
}
