#include <iostream>
#include "Matcher.h"
#include "HungarianMatcher.h"
#include "GreedyMatcher.h"

int main(int argc, char const *argv[])
{
    // // test hungari_assign
    // int newlySize = 3;
    // int existSize = 4;
    // Eigen::Matrix<float, -1, -1> posit_dists;
    // posit_dists.resize(newlySize, existSize);
    // posit_dists(0, 0) = 0.3;
    // posit_dists(0, 1) = 1;
    // posit_dists(0, 2) = 1;
    // posit_dists(0, 3) = 0.4;
    // posit_dists(1, 0) = 0.1;
    // posit_dists(1, 1) = 1;
    // posit_dists(1, 2) = 3;
    // posit_dists(1, 3) = 0.4;
    // posit_dists(2, 0) = 0.1;
    // posit_dists(2, 1) = 1;
    // posit_dists(2, 2) = 1;
    // posit_dists(2, 3) = 1;
    // // show similar matrix
    // std::cout << posit_dists << std::endl;

    Matcher *matcher = new GreedyMatcher();
    Eigen::Matrix<float, 2, 2> m1;
    m1 << 0, 1,
        1, 1;
    Eigen::Matrix<float, 3, 2> m2;
    m2 << 0, 2,
        0, 3,
        0, 4;
    matcher->cosine_distance(m1, m2);
    Eigen::Matrix<float, -1, -1> res;
    res = matcher->pairwise_distance(m1, m2);
    std::vector<int> mat;
    mat = matcher->matcher(res, 3);
    for (size_t i = 0; i < mat.size(); i++)
    {
        std::cout << "newly[" << i << "]"
                  << "->"
                  << "existed[" << mat[i] << "]" << std::endl;
    }

    return 0;
}