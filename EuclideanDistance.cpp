#include "EuclideanDistance.h"
/**
 * @brief 
 * 
 * @param mat1 Matrix<float, amount, feature dimension>
 * @param mat2 同上
 * @param exp 指数(exponent)，超参数。
 * @return Eigen::MatrixXf 距离矩阵(distance matrix)
 */
Eigen::MatrixXf pairwise_distance(Eigen::MatrixXf mat1, Eigen::MatrixXf mat2)
{
    int newlySize = mat1.rows();
    int existSize = mat2.rows();

    std::vector<Eigen::MatrixXf> allRowwiseResults;
    for (size_t row = 0; row < mat1.rows(); ++row)
    {
        // rowwiseResult =  mat2 - mat1.row
        Eigen::MatrixXf rowwiseResult = (mat2.rowwise() - mat1.row(row)).rowwise().norm();
        allRowwiseResults.push_back(rowwiseResult.transpose());
    }

    Eigen::MatrixXf distanceMatrix;
    distanceMatrix.resize(newlySize, existSize);
    for (size_t i = 0; i < allRowwiseResults.size(); i++)
    {
        distanceMatrix.row(i) = allRowwiseResults[i];
    }

    return distanceMatrix;
}