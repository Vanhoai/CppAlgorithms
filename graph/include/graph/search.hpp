#pragma once

namespace graph {
class GraphSearch {
public:
    void bfs();
    void dfs();
    bool hasPath(int start, int end);
};
};  // namespace graph