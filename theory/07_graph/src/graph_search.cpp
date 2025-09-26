//
// File        : graph_search.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#include <07_graph/graph_search.hpp>
#include <queue>

std::vector<int> GraphSearch::bfs(const int s) {
    std::queue<int> q;
    std::vector<int> path;

    visited[s] = true;
    q.push(s);
    path.push_back(s);
    while (!q.empty()) {
        int const u = q.front();
        q.pop();

        for (const int &v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                path.push_back(v);
            }
        }
    }

    return path;
}
