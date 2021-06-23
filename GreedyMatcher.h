#pragma once
#include <vector>
#include "Matcher.h"
#include "Eigen\Dense"
class GreedyMatcher final : public Matcher
{
public:
    std::vector<int> matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh);
};