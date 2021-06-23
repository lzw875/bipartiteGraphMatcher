#pragma once
#include "Eigen\Dense"
#include "Matcher.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>

class HungarianMatcher final : public Matcher
{
    private:
    std::map<int, int> assigned;    //key is col, value is row
    /**
     * @brief 
     * 
     * @param dists 
     * @param row 
     * @param thresh 
     * @return true 
     * @return false 
     */
    bool moveNext(Eigen::Matrix<float, -1, -1> &dists, int& row, float thresh=0.5);
    
public:
    /**
     * @brief 
     * 
     * @param dists 距离矩阵，相同目标距离近，不同目标距离远。
     * @param rows 行的数量
     * @param cols 列的数量
     * @param thresh 阈值，小于阈值才能进行匹配
     * @return std::vector<int> 
     */
    std::vector<int> matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh=0.5);
    
};