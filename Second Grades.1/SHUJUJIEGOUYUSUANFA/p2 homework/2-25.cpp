#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//计算两个对称矩阵压缩格式的乘积
vector<int> mul(vector<int> ve1, vector<int> ve2) 
{
    int len = ve1.size();
    int n = (int)((-1 + sqrt(1 + 8 * len)) / 2);
    
    vector<int> result(n * (n + 1) / 2, 0);
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            int sum = 0;
            for (int k = 0; k < n; k++) 
            {
                int a_ik;
                if (i >= k) 
                {
                    a_ik = ve1[i * (i + 1) / 2 + k];
                } 
                else 
                {
                    a_ik = ve1[k * (k + 1) / 2 + i];
                }
                
                int b_kj;
                if (k >= j) 
                {
                    b_kj = ve2[k * (k + 1) / 2 + j];
                } 
                else 
                {
                    b_kj = ve2[j * (j + 1) / 2 + k];
                }
                
                sum += a_ik * b_kj;
            }
            
            result[i * (i + 1) / 2 + j] = sum;
        }
    }
    
    return result;
}

void printCompressedMatrix(const vector<int>& compressed, int n) 
{
    cout << "压缩格式: ";
    for (int i = 0; i < compressed.size(); i++) 
    {
        cout << compressed[i] << " ";
    }
    cout << endl;
    
    cout << "完整矩阵:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i >= j) 
            {
                cout << compressed[i * (i + 1) / 2 + j] << " ";
            } 
            else 
            {
                cout << compressed[j * (j + 1) / 2 + i] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() 
{
    //例如3x3单位矩阵
    vector<int> identity1 = {1, 0, 1, 0, 0, 1};

    vector<int> identity2 = {1, 0, 1, 0, 0, 1};
    
    cout << "测试用例1: 两个3x3单位矩阵相乘" << endl;
    cout << "矩阵A:" << endl;
    printCompressedMatrix(identity1, 3);
    cout << "矩阵B:" << endl;
    printCompressedMatrix(identity2, 3);
    
    vector<int> result1 = mul(identity1, identity2);
    cout << "结果矩阵C = A * B:" << endl;
    printCompressedMatrix(result1, 3);
    
    //例如3x3对称矩阵
    vector<int> matrix1 = {1, 2, 4, 3, 5, 6};
    
    vector<int> matrix2 = {1, 0, 1, 0, 0, 1};
    
    cout << "测试用例2: 一般3x3对称矩阵与单位矩阵相乘" << endl;
    cout << "矩阵A:" << endl;
    printCompressedMatrix(matrix1, 3);
    cout << "矩阵B (单位矩阵):" << endl;
    printCompressedMatrix(matrix2, 3);
    
    vector<int> result2 = mul(matrix1, matrix2);
    cout << "结果矩阵C = A * B:" << endl;
    printCompressedMatrix(result2, 3);
    
    //例如两个2x2对称矩阵
    vector<int> matrix3 = {2, 1, 3};
    
    vector<int> matrix4 = {1, 2, 4};
    
    cout << "测试用例3: 两个2x2对称矩阵相乘" << endl;
    cout << "矩阵A:" << endl;
    printCompressedMatrix(matrix3, 2);
    cout << "矩阵B:" << endl;
    printCompressedMatrix(matrix4, 2);
    
    vector<int> result3 = mul(matrix3, matrix4);
    cout << "结果矩阵C = A * B:" << endl;
    printCompressedMatrix(result3, 2);
    
    return 0;
}
