#include "graph/search.hpp"

#include <gtest/gtest.h>

namespace graph {

class GraphSearchTest : public ::testing::Test {
protected:
    GraphSearch graphSearch;
};

TEST_F(GraphSearchTest, TestHasPath) {
    int start = 0;
    int end = 1;
    EXPECT_EQ(graphSearch.hasPath(start, end), false);
}

};  // namespace graph