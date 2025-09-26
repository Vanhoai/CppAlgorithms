//
// File        : core.hpp
// Author      : Hinsun
// Date        : 2025-09-23
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#ifndef CORE_HPP
#define CORE_HPP

#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace core {

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

// Please change the input and output path according to your project structure
const std::string INPUT_PATH =
    "/Users/hinsun/Workspace/Algorithms/CppAlgorithms/input.txt";
const std::string OUTPUT_PATH =
    "/Users/hinsun/Workspace/Algorithms/CppAlgorithms/output.txt";

inline void io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    freopen(core::INPUT_PATH.c_str(), "r", stdin);
    freopen(core::OUTPUT_PATH.c_str(), "w", stdout);
}

inline ll gcd(const ll a, const ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

int sum_vector(const std::vector<int> &nums);

}   // namespace core

#endif   // CORE_HPP
