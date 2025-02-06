#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * int is_lower_own(char c)
 * int is_upper_own(char c)
 * int is_alpha_own(char c)
 * int is_digit_own(char c)
 * char to_lower_own(char c)
 * char to_upper_own(char c)
 * int strlen(string c)
 * string str_lwr_own(string s)
 * string str_upr_own(string s)
 * strcmp_own(string s1, string s2)
 * long long atoll_own(string s)
 */

int is_lower_own(char c) { return c >= 'a' && c <= 'z'; }

int is_upper_own(char c) { return c >= 'A' && c <= 'Z'; }

int is_alpha_own(char c) { return is_lower_own(c) || is_upper_own(c); }

int is_digit_own(char c) { return c >= '0' && c <= '9'; }

char to_lower_own(char c) {
    if (is_upper_own(c))
        return c - 'A' + 'a';
    else
        return c;
}

char to_upper_own(char c) {
    if (is_lower_own(c))
        return c - 'a' + 'A';
    else
        return c;
}

int strlen(string c) { return c.size(); }

string str_lwr_own(string s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = to_lower_own(s[i]);

    return s;
}

string str_upr_own(string s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = to_upper_own(s[i]);

    return s;
}

int strcmp_own(string s1, string s2) {
    if (s1.size() != s2.size())
        return s1.size() - s2.size();

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }

    return 0;
}

ll atoll_own(string s) {
    ll res = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        int digit = s[i] - '0';
        res += digit * pow(10, size - i - 1);
    }

    return res;
}

int main() {
    SETUP;

    return 0;
}