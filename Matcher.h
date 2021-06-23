#pragma once
#include "Eigen\Dense"
#include <iostream>
#include <vector>

class Matcher // test
{
public:
    Eigen::Matrix<float, -1, -1> cosineDistance(Eigen::Matrix<float, -1, -1> mat1,
                                                Eigen::Matrix<float, -1, -1> mat2);
    virtual std::vector<int> matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh) = 0;
    virtual ~Matcher() = default;
};