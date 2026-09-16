#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int>> matrix;

//上三角矩阵压缩存储
vector<int> tr_convert(matrix mat) 
{
    int n = mat.size();
    vector<int> compressed; 
    
    compressed.reserve(n * (n + 1) / 2);
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            compressed.push_back(mat[i][j]);
        }
    }
    
    return compressed;
}

matrix tr_convert(vector<int> ve) 
{
    int size = ve.size();
    int n = (int)((-1 + sqrt(1 + 8 * size)) / 2);
    
    matrix mat(n, vector<int>(n, 0));
    
    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            mat[i][j] = ve[index++];
        }
    }
    
    return mat;
}

void printMatrix(const matrix& mat) 
{
    int n = mat.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const vector<int>& vec) 
{
    for (int i = 0; i < vec.size(); i++) 
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() 
{
    //4×4的上三角矩阵进行测试
    matrix testMatrix = 
    {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {0, 0, 8, 9},
        {0, 0, 0, 10}
    };
    
    cout << "原始上三角矩阵:" << endl;
    printMatrix(testMatrix);
    
    //压缩函数
    vector<int> compressed = tr_convert(testMatrix);
    cout << "压缩后的数组(大小为" << compressed.size() << "): ";
    printVector(compressed);
    
    //验证压缩后的大小公式
    int n = testMatrix.size();
    cout << "根据公式 n*(n+1)/2 计算的大小: " << n * (n + 1) / 2 << endl;
    
    //压缩函数
    matrix restoredMatrix = tr_convert(compressed);
    cout << "解压缩后的矩阵:" << endl;
    printMatrix(restoredMatrix);
    
    //验证解压缩后的是否相同
    bool isEqual = true;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (testMatrix[i][j] != restoredMatrix[i][j]) 
            {
                isEqual = false;
                break;
            }
        }
        if (!isEqual) break;
    }
    
    if (isEqual) 
    {
        cout << "验证成功：原始矩阵和解压缩后的矩阵相同" << endl;
    } 
    else 
    {
        cout << "验证失败：原始矩阵和解压缩后的矩阵不相同" << endl;
    }
    
    //测试另一个
    cout << "\n--- 测试3x3矩阵 ---" << endl;
    matrix testMatrix2 = 
    {
        {1, 2, 3},
        {0, 4, 5},
        {0, 0, 6}
    };
    
    cout << "原始上三角矩阵:" << endl;
    printMatrix(testMatrix2);
    
    vector<int> compressed2 = tr_convert(testMatrix2);
    cout << "压缩后的数组(大小为" << compressed2.size() << "): ";
    printVector(compressed2);
    
    cout << "根据公式 n*(n+1)/2 计算的大小: " << 3 * (3 + 1) / 2 << endl;
    
    matrix restoredMatrix2 = tr_convert(compressed2);
    cout << "解压缩后的矩阵:" << endl;
    printMatrix(restoredMatrix2);
    
    return 0;
}
