// Pi22的分数表达fractionExpressionPi230101.cpp :。
// Gmp高精计算:在c/c++语言环境,使用gmp库的gmpxx.h,如何调用高精度的圆周率Pi,比如调用201位圆周率Pi,或者调用129位十六进制的圆周率Pi等等
// 这里先算PI(以后再改成Pi/4 : 
//Pi(圆周率)的分数近似:
//https://qin.laya.com/tech_projects_approxpi.html //可惜没有提供源码,下面是本人复现的源码:41313989@QQ.com
//附加资料:
// https://oeis.org/A002485
//https://oeis.org/A002485/b002485.txt 分子
//https://oeis.org/A002486/b002486.txt 分母
//                       12345678901234567890
//unsigned long long     18446744073709551615 (共20位)
//unsigned int                     4294967295 (共10位)
//                                 1234567890
//


#include <iostream>
#include <gmpxx.h> //此程序是用高精度gmp库;long long 和 long double 算: int 与float;
using namespace std;

#define kunPi60hex 0x3243f6a8885a308d
#define maxUnI      4294967295
#define maxUnIhex   0xffffffff
#define maxUShortInt    0xffff
#define maxUSI          0xffff

typedef unsigned short int UShortInt;//0~0xffff
typedef unsigned short int USI;
typedef unsigned long long ULL;
typedef unsigned long long ULL;
typedef unsigned int UnI;
typedef long double LD;

//------------------------------------------
void print16double_toStrPi(long double ldA, int N) {

    ULL tmpUll01 = 0;
    for (int i = 0; i < N; ++i) {
        ldA *= 2;
        tmpUll01 = ldA;
        //        cout << hex << tmpUll01 << endl;
    }
    cout << hex << tmpUll01;
}//printdouble_toStr

long double getKunPi(unsigned long long ull_kunpi = 0x3243f6a8885a308d) {
    long double ldtmp;
    ldtmp = ull_kunpi;
    for (int i = 0; i < 60; ++i) { ldtmp /= 2.0; }
    return ldtmp;
}//
long double getKunP_4a1(unsigned long long ull_kunpi = 0x3243f6a8885a308d) {
    long double ldtmp;
    ldtmp = ull_kunpi;
    for (int i = 0; i < 62; ++i) { ldtmp /= 2.0; }
    return ldtmp;
}//

long double getKunCompletePi(unsigned long long ull_kunpi = 0x3243f6a8885a308d) {
    long double ldtmp;
    ldtmp = ull_kunpi;
    for (int i = 0; i < 60; ++i) { ldtmp /= 2.0; }
    return ldtmp;
}//

long double seekDeviationWuCha(UnI fz1, UnI  fm1, long double ldTmpPi)
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "DeviationWucha:误差:" << tmp;
    return tmp;
}//seekWuCha

long double seekDeviationWuChaULL(ULL fz1, ULL  fm1, long double ldTmpPi) //重载了!注意
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "DeviationWucha:误差:" << tmp;
    return tmp;
}//seekWuCha

long double seekDeviationWuCh_USI(USI fz1, USI  fm1, long double ldTmpPi)
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "DeviationWucha:误差:" << tmp;
    return tmp;
}//seekWuCha

int main()
{
    UnI nutfz3 = 3;
    UnI denomfM2 = 1;
    USI nutfz1usi = 1;
    USI denomfM1usi = 1;
    cout.precision(71);
    cout<<maxUShortInt << endl;

   

    
    

    


    //------------------------------------------------------------
    // 
    // 设置所需的默认精度
    mpf_set_default_prec(1024);

    // 初始化你的数
    const char* pi_201_decimal = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
//    const char* pi_1001 = "3."   "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";//"8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
    mpf_class Pi201(pi_201_decimal);

    const char* pi_129_hex = "0x3.243F6A8885A308D313198A2E03707344A4093822299F31D0082EFA98EC4E6C89452821E638D01377";

    // 使用前201位的π
    // 输出这些数
    std::cout.precision(201);  // 设置输出的精度
    std::cout << "pi_201_decimal: " << pi_201_decimal << std::endl;
    std::cout << "Pi201: " << Pi201 << std::endl;
    //    std::cout << "piHex:" << Pi129hex << std::endl;

    
    //=============================================================
    //
    
    long double KunPiComplete = getKunCompletePi();
    KunPiComplete = Pi201.get_d();
    cout << KunPiComplete << endl;
    print16double_toStrPi(KunPiComplete, 60); cout << endl;

    long double Dev_nutz3denoM1 = fabs(1.0 * seekDeviationWuCha(3, 1, KunPiComplete));

    long double tmp_tryPi_4a;

    //---------------------------------
    //long double KunPi_4a01 = getKunCompletePi();
    long double minDev = 1.1;


    long double Deviat_real01; //每次的(每次运算)随时误差
    int numI = 0;
    USI tmpD01;
    for (UShortInt dMM = 1; dMM <= 0xffff /*65535*//*maxUShortInt */ ; ++dMM) { //for110ii Nuz = 3; Nuz <= maxUnI; ++Nuz) {//for110ii
        

        //UnI
            tmpD01 = (double)KunPiComplete *(double)dMM; //预算预期的分子,用乘法, 求(Pi/4),分子小于分母

            for (/*UShortInt*/ unsigned int Nuz = tmpD01; Nuz <= (1 + tmpD01); ++Nuz) // dMM = (tmpD01 - 1); dMM <= (1 + tmpD01); ++dMM) {//for220jj
            {//for220jj
            //long double
            tmp_tryPi_4a = (long double)Nuz/ (double)dMM;//尝试 得出一个 （大概率）带误差的 tryPi值
            Deviat_real01 = fabs(KunPiComplete - tmp_tryPi_4a); //算出 尝试tryPi与 realPi(KunPi)之间的 deviat_real

            if ( Deviat_real01 <minDev)  {//if3300
                ++numI;

                cout << endl <<"["<<numI<<":";
                cout << "Result分子iNu:" << dec << Nuz;
                cout << "_M:" << dec << dMM << "]";

                //cout << "得到Pi; " << hex << Nuz/ dMM;
                print16double_toStrPi((double(Nuz) / dMM), 60);// 62);
                cout << "] wuCha误差:" << dec << Deviat_real01;// << endl;
                minDev = Deviat_real01; //记录此次循环最小误差,准备下次收敛


                }//if3300
            else { ; }//if3300else3300



            }//for220jj
            //              12345678
            if (0 == (dMM % 1000)) {  printf("."); /* cout << dMM; */ }
            if (0xffff == dMM) break;

        }//for110ii

        //==================================

    ////////////////

    std::cout << "End!!\n";
}//main