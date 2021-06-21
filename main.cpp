#include "Eigen\Dense"
#include <iostream>

// cosine distance
/**
 * @brief 
 * 
 * @param mat1 Matrix<float, amount, feature dimension>
 * @param mat2 同上
 * @return Eigen::Matrix<float, -1, -1> 
 */
Eigen::Matrix<float, -1, -1> cosineDistance(Eigen::Matrix<float, -1, -1> mat1,
                                            Eigen::Matrix<float, -1, -1> mat2)
{
    // TODO: 需要防止最小值为0。
    // 两个矩阵乘法（内积）
    std::cout << mat1 * mat2.transpose() << std::endl;
    // 矩阵逐行（向量）求模
    std::cout << mat1.rowwise().norm() << std::endl;
    std::cout << mat2.rowwise().norm() << std::endl;
    // 两个模向量的乘积
    std::cout << mat1.rowwise().norm() * mat2.rowwise().norm().transpose() << std::endl;
    // 矩阵除法，需要求逆，要变换乘方正。似乎还和单位向量有关。
    std::cout << (mat1.rowwise().norm() * mat2.rowwise().norm()) * (mat1.rowwise().norm() * mat2.rowwise().norm()).inverse() << std::endl;
    return Eigen::Matrix<float, -1, -1>();
}

int main(int argc, char const *argv[])
{
    Eigen::Matrix<float, 2, 2> m1;
    m1 <<   0, 1,
            1, 1;
    Eigen::Matrix<float, 3, 2> m2;
    m2 <<   0, 2,
            0, 3,
            0, 4;
    cosineDistance(m1, m2);
    return 0;
}