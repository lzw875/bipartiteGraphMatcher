#include <iostream>
#include "Eigen\Dense"
#include "EuclideanDistance.h"

int main(int argc, char const *argv[])
{
    Eigen::Matrix<float, 2, 2> m1;
    m1 << 0, 1,
        1, 1;
    Eigen::Matrix<float, 3, 2> m2;
    m2 << 0, 2,
        0, 3,
        0, 4;
    std::cout << pairwise_distance(m1, m2);
    return 0;
}