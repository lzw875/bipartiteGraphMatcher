#pragma once
#include "Eigen\Dense"
#include <iostream>
#include <vector>

class Matcher // test
{
public: //相似度计算函数
    /**
     * @brief 
     * 
     * @param mat1 Matrix<float, amount, feature dimension>
     * @param mat2 同上
     * @return Eigen::Matrix<float, -1, -1> newly与existed两两计算余弦距离的距离矩阵
     */
    Eigen::Matrix<float, -1, -1> cosine_distance(Eigen::Matrix<float, -1, -1> mat1, Eigen::Matrix<float, -1, -1> mat2) const;

    /**
     * @brief 
     * 
     * @param mat1 Matrix<float, amount, feature dimension>
     * @param mat2 同上
     * @return Eigen::Matrix<float, -1, -1> newly与existed两两计算欧式距离的距离矩阵
     */
    Eigen::Matrix<float, -1, -1> pairwise_distance(Eigen::Matrix<float, -1, -1> mat1, Eigen::Matrix<float, -1, -1> mat2) const;

public: //匹配函数
    virtual std::vector<int> matcher(Eigen::Matrix<float, -1, -1> &dists, float thresh) = 0;

    virtual ~Matcher() = default;
};