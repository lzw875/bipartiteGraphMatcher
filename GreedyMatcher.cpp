#include "GreedyMatcher.h"

/**
 * @brief 
 * 
 * @param dists 距离矩阵，相同目标距离近，不同目标距离远。
 * @param thresh 阈值，小于阈值才能进行匹配
 * @return std::vector<int> 
 */
std::vector<int> GreedyMatcher::matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh)
{
    int rows = dists.rows();
    int cols = dists.cols();
    std::vector<int> ret(rows, -1);
    for (int row = 0; row < rows; ++row)
    {
        int col;
        float min = dists.row(row).minCoeff(&col);
        if(min >= thresh)
            continue;
        ret[row] = col;
        dists.col(col).fill(thresh);
    }
    return ret;
}