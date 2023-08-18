//先算PI再改成Pi/4ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include <iostream>
//#include <gmpxx.h>
using namespace std;

#define atanPi (4.0*atan(1.0))
#define kunPi60hex 0x3243f6a8885a308d
typedef unsigned long long ULL;
typedef unsigned int UnI;
typedef long double LD;
UnI maxUnI = 4294967295;

static long double getKunPi(unsigned long long ld_kunpi= 0x3243f6a8885a308d){
    long double ldtmp;
    ldtmp = ld_kunpi;
    for (int i = 0; i < 60; ++i) { ldtmp /= 2; }
    return ldtmp;
}//


void print16double_toStrPi(double A, int N) {

    ULL tmpUll01 = 0;
    for (int i = 0; i < N; ++i) {
        A *= 2;
        tmpUll01 = A;
//        cout << hex << tmpUll01 << endl;
    }
    cout  << hex << tmpUll01;
}//printdouble_toStr


long double seekWuChaULL(ULL fz1, ULL  fm1, long double ldTmpPi)
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "Wucha:误差:" << tmp;
    return tmp;
}//seekWuCha

long double seekWuCha(UnI fz1, UnI  fm1, long double ldTmpPi)
{
    long double tmp = (double)fz1 / (double)fm1;
    cout << "[TmpPi临时Pi:" << tmp << endl;
    tmp = fabs(ldTmpPi - tmp);
    cout << "Wucha:误差:" << tmp;
    return tmp;
}//seekWuCha

int main()
{
/*    UnI fzui2549 = 2549491779;
    UnI fmui81 = 811528438;
    long double fz2549fm = (double)fzui2549 / fmui81; 
    cout << "[fz2549:";
    cout.precision(20);
    print16double_toStrPi(fz2549fm, 60);
    cout << endl;
    seekWuCha(fzui2549, fmui81, (4.0*(atan(1.0))) );
    cout << endl;*/

    cout.precision(16);
//    cout << fz2549fm << endl;
 //   cout << hex << fz2549 << endl;
//    print16double_toStrPi(fz2549fm, 60);


    ULL fzULL6167950454 = 6167950454;
    //                    4294967295
    ULL fmULL1963319607 = 1963319607;

    print16double_toStrPi( ((double)fzULL6167950454 / (double)fmULL1963319607), 60);
    long double fz616fm196 = (double)fzULL6167950454 / (double)fmULL1963319607; ////把这个当真Pi 3.141592653589793
    long double Pi616 = fz616fm196;
    //3243f6a8885a3000
    cout << endl << "fz616把这个数当真Pi对标:";
    print16double_toStrPi( Pi616, 60); cout << endl;
    cout << "Real真Pi:";
    seekWuChaULL(fzULL6167950454, fmULL1963319607, atanPi);
    cout << endl;

/*
    UnI fz657408909 = 657408909;
        UnI fm209259755 = 209259755;
        print16double_toStrPi((double)fz657408909 / fm209259755, 60);
        cout << "fz657408909:" << endl;
        seekWuCha(fz657408909, fm209259755, atanPi);    //误差0
        cout << endl;*/

        /*
        UnI fz411557987 = 411557987;
        UnI fm131002976 = 131002976;
        cout << endl << "i181fz411: ";
        print16double_toStrPi((double)fz411557987 / fm131002976, 60); //i181: 3243f6a8885a3000
        */

        cout << endl << "i180fz245: ";
        UnI fz245850922 = 245850922;
        UnI fm78256799 = 78256799;
        print16double_toStrPi((double)fz245850922 / fm78256799, 60);//i180: 3243f5d101f35800
        long double fz245_fm78 = (double)fz245850922 / fm78256799;


        long double wuChafz61679_fz245 = fabs(Pi616 - fz245_fm78);
        cout << endl << "wuCha误差fz616fz245之间:";
        cout << wuChafz61679_fz245 << endl;
        //fz245这里才出现误差

        //从 fz245850922 向后找 误差更小的分数
        //外循环是 大数分子，分子跨度大，步长大，fm细密 做内循环检测


        
        long double tmp_wChPi;
        long double wuChaifzi_real;
        /*
        UnI fz165707065 = 165707065;
        UnI fm52746197 = 52746197;

        long double wCh_fz165fm527 = seekWuCha(fz165707065, fm52746197, Pi616);*/

        UnI fz80143857 = 80143857;
        UnI fm25510582 = 25510582;
        long double wCh_fz801fm2551 = seekWuCha(fz80143857, fm25510582, getKunPi());// atanPi);// Pi616);
        cout << "wCh_fz8014fm255:" << wCh_fz801fm2551 << endl;


        //---------------------------
        UnI fz74724506 = 3;// 69305155;// 74724506;
        UnI fm23785549 = 1;// 22060516;// 23785549;
        long double wCh_fz7472fm2378 = fabs(1.0 * seekWuCha(fz74724506, fm23785549, getKunPi())  );// atanPi));//
//        wCh_fz7472fm2378 = 0.1;
        long double minWuCha = 1.1;
        for (UnI ifzi = 3/* 42208400*/ /*fz80143857*/ /*fz165707065*/ /*fz245850922*/; ifzi < 4294967295; ++ifzi) {//for110

            //先找 fenMu ifzi的 近似分子:
            UnI tmpFM01 = (double)ifzi /atanPi;

            for (UnI jfmj = (tmpFM01-1); jfmj <= 1 + tmpFM01;  ++jfmj) {//for2200jfmj
                //long double
                tmp_wChPi = (double)ifzi / (double)jfmj;//尝试 分子/尝试分母== 尝试 (大概率带误差wucha 的tmpPi)
                //long double 
                wuChaifzi_real = fabs(atanPi - (tmp_wChPi));   //看这个 尝试带误差的 tmpPi和 “真Pi” 的 实际误差

                //
                if (    ( minWuCha>wuChaifzi_real) &&  (wuChaifzi_real < wCh_fz7472fm2378 /*wuChafz61679_fz245 *//*wCh_fz801fm2551*//*wCh_fz165fm527*/)  )  
                {//wuChafz61679_fz245) {//if3300输出
                    cout << endl;
                    cout << "Result分子iFZi:" <<dec<< ifzi;
                    cout << ":FmJj" << dec<<jfmj << "]";

                    //cout << "得到Pi; " << hex << ifzi / jfmj;
                    print16double_toStrPi(( double(ifzi) / jfmj), 60);
                    cout << "] wuCha误差:" <<dec<< wuChaifzi_real << endl;
                    minWuCha = wuChaifzi_real;

                }
                else {//否则不输出
                    ;
                }
                //

            }//for2200jfmj

            //             1234567
            if (0 == ifzi % 10000000) printf(".");

        }//for110




    std::cout << "Hello World!\n";
}//