//
// File        : graph_search_test.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#include <07_graph/graph_search.hpp>
#include <gtest/gtest.h>

class GraphSearchTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(GraphSearchTest, BFSTest) {
    const std::vector<std::pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    GraphSearch graph(edges);
    const std::vector expected = {1, 2, 3, 4};
    EXPECT_EQ(graph.bfs(1), expected);
}