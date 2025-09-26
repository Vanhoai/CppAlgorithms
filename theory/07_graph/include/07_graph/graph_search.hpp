//
// File        : graph_search.hpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#ifndef CPPALGORITHMS_GRAPH_SEARCH_HPP
#define CPPALGORITHMS_GRAPH_SEARCH_HPP

#include <core/core.hpp>
#include <vector>

class GraphSearch {
    std::vector<int> adj[core::DEG];
    std::vector<bool> visited;

public:
    explicit GraphSearch(const std::vector<std::pair<int, int>> &edges) {
        visited.resize(core::DEG + 1, false);

        for (const auto &[u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    std::vector<int> bfs(int s);
};

#endif   // CPPALGORITHMS_GRAPH_SEARCH_HPP
