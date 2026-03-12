//
// File        : core.hpp
// Author      : Hinsun
// Date        : 2025-09-23
//

// This file will be included in all other files in the project. It contains
// common definitions and utilities that are used throughout the project.

#ifndef CORE_HPP
#define CORE_HPP

#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace core {

// Define some common macros and type aliases for convenience

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef std::pair<int, int> pi;
typedef std::vector<int> vi;
typedef std::vector<pi> vii;
typedef std::vector<vi> vvi;

constexpr int MOD = static_cast<int>(1e9) + 7;
constexpr int INF = static_cast<int>(1e9) + 1;
constexpr int DEG = 10001;

// Define some common utility functions
inline void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

inline ll gcd(const ll a, const ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

}   // namespace core

#endif   // CORE_HPP
