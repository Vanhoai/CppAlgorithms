//
// File        : core.cpp
// Author      : Hinsun
// Date        : 2025-09-26
// Copyright   : (c) 2025 Tran Van Hoai
// License     : MIT
//

#include <core/core.hpp>
#include <vector>

namespace core {

int sum_vector(const std::vector<int> &nums) {
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i)
        sum += nums[i];

    return sum;
}

}   // namespace core
