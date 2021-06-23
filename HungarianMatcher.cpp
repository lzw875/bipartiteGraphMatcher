#include "HungarianMatcher.h"


bool HungarianMatcher::moveNext(Eigen::Matrix<float, -1, -1> &dists, int& row, float thresh)
{
    // 递归实现
    int proposal_col = -1;
    float min = dists.row(row).minCoeff(&proposal_col);
    if(min >= thresh)
    {
        return false;
    }
    dists(row, proposal_col) = thresh;
    if (assigned.find(proposal_col) != assigned.end())
    {
        int pre_row = assigned[proposal_col];
        if(moveNext(dists, pre_row, thresh))
        {
            assigned[proposal_col] = row;
            return true;
        }
        else return false;
    }
    assigned[proposal_col] = row;
    return true;
}

std::vector<int> HungarianMatcher::matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh)
{
    int rows = dists.rows();
    int cols = dists.cols();
    std::vector<int> ret(rows, -1);
    for (int row = 0; row < rows; ++row)
    {
        int col;
        while(true)
        {
            float min = dists.row(row).minCoeff(&col);
            if(min >= thresh)
                break;
            dists(row, col) = thresh;
            if(assigned.find(col) == assigned.end())
            {
                assigned[col] = row;
                break;
            }
            int pre_row = assigned[col];
            if(moveNext(dists, pre_row, thresh))
            {
                assigned[col] = row;
                break;
            }
        }
    }
    for (std::map<int, int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
    {
        ret[it->second] = it->first;
    }
    return ret;
}