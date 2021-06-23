#include "Matcher.h"


Eigen::MatrixXf Matcher::cosine_distance(Eigen::MatrixXf mat1, Eigen::MatrixXf mat2) const
{
    // TODO: 考虑mat1, mat2 为空的情况。

    // 需要防止最小值为0，出现NAN或INF等现象。
    float inf = 1e-7;
    Eigen::MatrixXf inf1(mat1.rows(), mat1.cols());
    Eigen::MatrixXf inf2(mat2.rows(), mat2.cols());
    inf1 = Eigen::MatrixXf::Ones(mat1.rows(), mat1.cols()) * inf;
    inf2 = Eigen::MatrixXf::Ones(mat2.rows(), mat2.cols()) * inf;
    mat1 += inf1;
    mat2 += inf2;

    Eigen::Matrix<float, -1, -1> innerProduct = mat1 * mat2.transpose();
    Eigen::Matrix<float, -1, -1> modulus = mat1.rowwise().norm() * mat2.rowwise().norm().transpose();

    Eigen::MatrixXf ret(innerProduct.rows(), innerProduct.cols());

    for (int i = 0; i < innerProduct.rows(); i++)
    {
        for (int j = 0; j < innerProduct.cols(); j++)
        {
            ret(i, j) = innerProduct(i, j) / modulus(i, j);
        }
    }
    std::cout << std::endl;
    std::cout << ret << std::endl;
    std::cout << std::endl;
    return ret;
}

Eigen::MatrixXf Matcher::pairwise_distance(Eigen::MatrixXf mat1, Eigen::MatrixXf mat2) const
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
    std::cout << std::endl;
    std::cout << distanceMatrix << std::endl;
    std::cout << std::endl;

    return distanceMatrix;
}