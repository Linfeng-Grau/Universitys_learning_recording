#include <iostream>
#include <vector>
using namespace std;

struct Trituple 
{
    int row, col, value;
    
    Trituple() : row(0), col(0), value(0) {}
    Trituple(int r, int c, int v) : row(r), col(c), value(v) {}
};

struct sMatrix 
{
    vector<Trituple> data; 
    int rows, cols, nums; 
    
    sMatrix() : rows(0), cols(0), nums(0) {}
    sMatrix(int r, int c, int n) : rows(r), cols(c), nums(n) {}
};


sMatrix sm_add(sMatrix sm1, sMatrix sm2) 
{
    sMatrix result(sm1.rows, sm1.cols, 0); 
    
    int i = 0, j = 0; 
    
    while (i < sm1.nums && j < sm2.nums) 
    {
        Trituple t1 = sm1.data[i];
        Trituple t2 = sm2.data[j];
        
        if (t1.row < t2.row || (t1.row == t2.row && t1.col < t2.col)) 
        {
            result.data.push_back(t1);
            result.nums++;
            i++;
        }
        else if (t1.row > t2.row || (t1.row == t2.row && t1.col > t2.col)) 
        {

            result.data.push_back(t2);
            result.nums++;
            j++;
        } 
        else 
        {
            int sum = t1.value + t2.value;
            if (sum != 0) 
            {
                result.data.push_back(Trituple(t1.row, t1.col, sum));
                result.nums++;
            }
            i++;
            j++;
        }
    }
    
    while (i < sm1.nums)
    {
        result.data.push_back(sm1.data[i]);
        result.nums++;
        i++;
    }
    
    while (j < sm2.nums) 
    {
        result.data.push_back(sm2.data[j]);
        result.nums++;
        j++;
    }
    
    return result;
}

sMatrix createMatrix(int rows, int cols, const vector<vector<int>>& fullMatrix) 
{
    sMatrix sm(rows, cols, 0);
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (fullMatrix[i][j] != 0) 
            {
                sm.data.push_back(Trituple(i, j, fullMatrix[i][j]));
                sm.nums++;
            }
        }
    }
    
    return sm;
}

void printSparseMatrix(const sMatrix& sm) 
{
    cout << "稀疏矩阵 (" << sm.rows << "x" << sm.cols << "), 非零元素个数: " << sm.nums << endl;
    cout << "行\t列\t值" << endl;
    for (int i = 0; i < sm.nums; i++) 
    {
        cout << sm.data[i].row << "\t" << sm.data[i].col << "\t" << sm.data[i].value << endl;
    }
    cout << endl;
}

vector<vector<int>> toFullMatrix(const sMatrix& sm) 
{
    vector<vector<int>> full(sm.rows, vector<int>(sm.cols, 0));
    
    for (int i = 0; i < sm.nums; i++) 
    {
        full[sm.data[i].row][sm.data[i].col] = sm.data[i].value;
    }
    
    return full;
}

void printFullMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


int main() 
{
    //创建两个4x4的稀疏矩阵
    vector<vector<int>> fullMatrix1 = 
    {
        {1, 0, 0, 2},
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {5, 0, 0, 6}
    };
    
    vector<vector<int>> fullMatrix2 = 
    {
        {0, 1, 0, 0},
        {2, 0, 0, 3},
        {0, 0, 4, 0},
        {0, 5, 0, 6}
    };
    
    cout << "完整矩阵A:" << endl;
    printFullMatrix(fullMatrix1);
    
    cout << "完整矩阵B:" << endl;
    printFullMatrix(fullMatrix2);
    
    //转换为稀疏矩阵
    sMatrix sm1 = createMatrix(4, 4, fullMatrix1);
    sMatrix sm2 = createMatrix(4, 4, fullMatrix2);
    
    cout << "稀疏矩阵A:" << endl;
    printSparseMatrix(sm1);
    
    cout << "稀疏矩阵B:" << endl;
    printSparseMatrix(sm2);
    
    //计算稀疏矩阵的和
    sMatrix result = sm_add(sm1, sm2);
    
    cout << "稀疏矩阵A+B的结果:" << endl;
    printSparseMatrix(result);
    
    //验证
    vector<vector<int>> fullResult = toFullMatrix(result);
    cout << "完整矩阵A+B的结果:" << endl;
    printFullMatrix(fullResult);
    
    //测试包含抵消元素的情况
    cout << "--- 测试包含抵消元素的情况 ---" << endl;
    vector<vector<int>> fullMatrix3 = 
    {
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 4}
    };
    
    vector<vector<int>> fullMatrix4 = 
    {
        {-1, 0, 0, 0},
        {0, -2, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, -4}
    };
    
    cout << "完整矩阵C:" << endl;
    printFullMatrix(fullMatrix3);
    
    cout << "完整矩阵D:" << endl;
    printFullMatrix(fullMatrix4);
    
    sMatrix sm3 = createMatrix(4, 4, fullMatrix3);
    sMatrix sm4 = createMatrix(4, 4, fullMatrix4);
    
    sMatrix result2 = sm_add(sm3, sm4);
    
    cout << "稀疏矩阵C+D的结果:" << endl;
    printSparseMatrix(result2);
    
    vector<vector<int>> fullResult2 = toFullMatrix(result2);
    cout << "完整矩阵C+D的结果:" << endl;
    printFullMatrix(fullResult2);
    
    return 0;
}
