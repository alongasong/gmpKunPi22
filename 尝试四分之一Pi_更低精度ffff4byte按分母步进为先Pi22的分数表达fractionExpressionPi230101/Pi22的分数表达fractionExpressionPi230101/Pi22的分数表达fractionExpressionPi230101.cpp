// Pi22的分数表达fractionExpressionPi230101.cpp :。
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
//#include <gmpxx.h> //此程序是用long long 和 long double 算: int 与float;
using namespace std;

#define kunPi60hex 0x3243f6a8885a308d
#define maxUnI      4294967295
#define maxUnIhex   0xffffffff
#define maxShortInt    0xffff
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

long double seekDeviationWuCha(UnI fz1, UnI  fm1, long double ldTmpPi)
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "Wucha:误差:" << tmp;
    return tmp;
}//seekWuCha

long double seekDeviationWuChaULL(ULL fz1, ULL  fm1, long double ldTmpPi) //重载了!注意
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "Wucha:误差:" << tmp;
    return tmp;
}//seekWuCha

int main()
{
    UnI nutfz3 = 3;
    UnI denomfM1 = 1;
    cout.precision(71);
    cout<<maxShortInt << endl;
    cout << getKunP_4a1() << endl;

    print16double_toStrPi(getKunP_4a1(), 60); cout << endl;

    //
    

    long double Dev_nutz3denoM1 = fabs(1.0 * seekDeviationWuCha(3, 1, getKunP_4a1()));

    long double tmp_tryPi;

    //---------------------------------
    long double KunPi01 = getKunP_4a1();
    long double minDev = 1.1;


    long double Deviat_real01; //每次的(每次运算)随时误差
    UnI tmpD01;
    int numI = 0;
    for (UnI dMM = 1; dMM <= 65535/*maxUnI */ ; ++dMM) { //for110ii Nuz = 3; Nuz <= maxUnI; ++Nuz) {//for110ii
        

        //UnI
            tmpD01 = (double) KunPi01*(double)dMM; //用乘法,分子大于分母,Pi大于3

            for (UnI Nuz = tmpD01/* - 1 */ ; Nuz<(1 + tmpD01); ++Nuz) {//for220jj// dMM = (tmpD01 - 1); dMM <= (1 + tmpD01); ++dMM) {//for220jj
            //long double
            tmp_tryPi = (double)Nuz/ (double)dMM;//尝试 得出一个 （大概率）带误差的 tryPi值
            Deviat_real01 = fabs(KunPi01 - tmp_tryPi); //算出 尝试tryPi与 realPi(KunPi)之间的 deviat_real

            if ( Deviat_real01 <minDev)  {//if3300
                ++numI;

                cout << endl <<"["<<numI<<":";
                cout << "Result分子iNu:" << dec << Nuz;
                cout << "_M:" << dec << dMM << "]";

                //cout << "得到Pi; " << hex << Nuz/ dMM;
                print16double_toStrPi((double(Nuz) / dMM), 62);
                cout << "] wuCha误差:" << dec << Deviat_real01;// << endl;
                minDev = Deviat_real01;


                }//if3300
            else { ; }//if3300else3300



            }//for220jj
            //             12345678
            if (0 == dMM% 100000000) printf(".");

        }//for110ii

        //==================================

    ////////////////

    std::cout << "End!!\n";
}//main