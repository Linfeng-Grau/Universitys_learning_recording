#include <iostream>
#include <cmath>
using namespace std;

// 计算等额本金
double logDEBJ(double DKJE, double MLV, int ZYF) {
    double YBJ = DKJE / ZYF;
    double RP = DKJE;
    double ZLX1 = 0;

    for (int month = 0; month < ZYF; ++month) {
        double LV = RP * MLV;
        double YHKE = YBJ + LV;
        ZLX1 += LV;
        RP -= YBJ;
        cout << "第" << (month + 1) << "月" << ", 还款额:" << YHKE << ", 本金:" << YBJ << ", 利息:" << LV << "\n";
    }
    return ZLX1;
}

// 计算等额本息
double logDEBX(double DKJE, double MLV, int ZYF) {
    double YHKE = DKJE * MLV * pow((1 + MLV), ZYF) / ((pow((1 + MLV), ZYF) - 1));
    double ZLX2 = ZYF * YHKE - DKJE;

    for (int month = 0; month < ZYF; ++month) {
        double LVP = DKJE * MLV;
        double YBJ2 = YHKE - LVP;
        DKJE -= YBJ2;
        cout << "第" << (month + 1) << "月" << ", 还款额: " << YHKE << ", 本金:" << YBJ2 << ", 利息:" << LVP << "\n";
    }
    return ZLX2;
}

int main() {
    double DKJE;
    double NLV;
    int DKNX;
    int ZYF;
    double ZLX1, ZLX2;

    cout << "请输入贷款金额(元): ";
    cin >> DKJE;
    cout << "请输入贷款年限: ";
    cin >> DKNX;
    cout << "请输入年利率(例0.05表示5%): ";
    cin >> NLV;
    cout << "--------------------------------------\n提供两种还款方式:  等额本金   等额本息\n--------------------------------------\n";
    ZYF = DKNX * 12;

    double MLV = NLV / 12;

    cout << "贷款总额: " << DKJE << "元\n";
    cout << "贷款年限: " << DKNX << "年\n";
    cout << "年利率: " << NLV * 100 << "%" << endl;

    cout << "\n采用等额本金:\n";
    ZLX1 = logDEBJ(DKJE, MLV, ZYF);

    cout << "\n采用等额本息:\n";
    ZLX2 = logDEBX(DKJE, MLV, ZYF);

    cout << "--------------------------------------\n";
    cout << "贷款总额：" << DKJE << "元\n";
    cout << "贷款年限：" << DKNX << "年\n";
    cout << "年利率：" << NLV * 100 << "%\n";
    cout << "等额本金总利息是：" << ZLX1 << "元\n";
    cout << "等额本息总利息是：" << ZLX2 << "元";
    cout << "\n--------------------------------------\n";
}