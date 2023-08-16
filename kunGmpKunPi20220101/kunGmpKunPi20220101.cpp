<<<<<<< HEAD
﻿// kunGmpKunPi20220101.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Paper20220101附加代码，需要完整论文及代码……请联系： 41313989@qq.com 或 hongkun@umass.edu
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <gmpxx.h>

using namespace std;

const string MSG_USAGE = "Usage:\nKun_pi n <file>\n\nwhere <file> is one of:\n\t- A legal file name for saving pi value or\n\t- BLANK, will just compute without saving.\n\nThe n is an integer number specifying the pi digits to compute\n\nExample:\nKun_pi 1024 Pi.txt\n";

char* FILENAME;
unsigned int DIGITS;

struct PQT
{
    mpz_class P, Q, T;
};

class Chudnovsky
{
    // Declaration
    mpz_class A, B, C, D, E, C3_24; // GMP Integer
    int PREC, N;                    // Integer
    double DIGITS_PER_TERM;         // Long
    clock_t t0, t1, t2;             // Time
    PQT compPQT(int n1, int n2);    // Computer PQT (by BSA)

public:
    Chudnovsky();  // Constructor
    void compPi(); // Compute PI
};

/*
 * Constructor
 */
Chudnovsky::Chudnovsky()
{
    // Constants
    // DIGITS = 1000;   // prompt for user input
    A = 13591409;
    B = 545140134;
    C = 640320;
    D = 426880;
    E = 10005;
    DIGITS_PER_TERM = 14.1816474627254776555; // = log(53360^3) / log(10)
    C3_24 = C * C * C / 24;
    N = DIGITS / DIGITS_PER_TERM;
    PREC = DIGITS * log2(10);
}

/*
 * Compute PQT (by Binary Splitting Algorithm)
 */
PQT Chudnovsky::compPQT(int n1, int n2)
{
    int m;
    PQT res;

    if (n1 + 1 == n2)
    {
        res.P = (2 * n2 - 1);
        res.P *= (6 * n2 - 1);
        res.P *= (6 * n2 - 5);
        res.Q = C3_24 * n2 * n2 * n2;
        res.T = (A + B * n2) * res.P;
        if ((n2 & 1) == 1)
            res.T = -res.T;
    }
    else
    {
        m = (n1 + n2) / 2;
        PQT res1 = compPQT(n1, m);
        PQT res2 = compPQT(m, n2);
        res.P = res1.P * res2.P;
        res.Q = res1.Q * res2.Q;
        res.T = res1.T * res2.Q + res1.P * res2.T;
    }

    return res;
}

/*
 * Compute PI
 */
void Chudnovsky::compPi()
{
    cout << "**** PI Computation ( " << DIGITS << " digits )" << endl;

    // Time (start)
    t0 = clock();

    // Compute Pi
    PQT PQT = compPQT(0, N);
    mpf_class pi(0, PREC);
    pi = D * sqrt((mpf_class)E) * PQT.Q;
    pi /= (A * PQT.Q + PQT.T);

    // Time (end of computation)
    t1 = clock();
    cout << "TIME (COMPUTE): "
        << (double)(t1 - t0) / CLOCKS_PER_SEC
        << " seconds." << endl;

    // Output
    if (FILENAME != NULL)
    {
        ofstream ofs(FILENAME);
        ofs.precision(DIGITS + 1);
        ofs << pi << endl;

        // Time (end of writing)
        t2 = clock();

        // Get file size
        ifstream in(FILENAME, ios::binary | ios::ate);

        cout << "TIME (WRITE)  : "
            << (double)(t2 - t1) / CLOCKS_PER_SEC
            << " seconds." << endl
            << "FILE SAVED    : " << FILENAME
            << " ( " << in.tellg() << " BYTES )" << endl;
    }
    cout.precision(100);
    cout << pi << endl;
//    cout << "[16进制H:" << hex << pi << endl;
    //
    // --------------------------------------------------
      // 转换为十进制字符串
  
     // 输出为十进制
    std::cout << "Decimal representation: " << std::endl;
    mp_exp_t expo;
    std::string D = pi.get_str(expo, 10, 100);
        //mpf_get_str(nullptr, 10, 0, pi.get_mpf_t());
    for (int i = 0; i < D.size(); i++) {
        std::cout << D[i];
        if ((i + 1) % 20 == 0) {
            std::cout << std::endl;
        }
    }

    // 输出为十六进制
    cout << endl;
    cout << "[16进制H:" << hex << pi;// << endl;
    std::cout << std::endl << "Hexadecimal representation: " << std::endl;
    std::string H = pi.get_str(expo, 16, 100);
        //mpf_get_str(nullptr, 16, 0, pi.get_mpf_t());
    for (int i = 0; i < H.size(); i++) {
        std::cout << H[i];
        if ((i + 1) % 8 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;


    //=====================================================

}//void Chudnovsky::compPi(

char tmpFilenam01[] = { "aPi20220101.txt" };
int main(int argc, char **argv)
{
    if (argc <= 1 || argc > 3)
    {
        cerr << MSG_USAGE;
        DIGITS = 100;// 99;//Default Digits=99
        FILENAME = tmpFilenam01;

//        return 1;
    }
    else {//if110else110
//        cout << "Compute pi(π) by Binary Splitting Algorithm with GMP libarary."<< endl;

        DIGITS = stoi(argv[1]);
        FILENAME = argv[2];
    }//if110else110
    cout << "Compute pi(π) by Binary Splitting Algorithm with GMP libarary."
        << endl;

    try
    {
        // Instantiation
        Chudnovsky objMain;

        // Compute PI
        objMain.compPi();
    }
    catch (...)
    {
        cout << "ERROR!" << endl;
        return -1;
    }
    std::cout << "Hello World!\n";
}//main

// 输出:FILE SAVED    : aPi20220101.txt ( 103 BYTES ) //
/*3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068
Decimal representation :
31415926535897932384
62643383279502884197
16939937510582097494
45923078164062862089
98628034825342117068

[16 ? ? H : 3.243f6a8885a308d313198a2e03707344a4093822299f31d0082efa98ec4e6c89452821e638d01377be5466cf34e90e88
Hexadecimal representation :
3243f6a8
885a308d
313198a2
e0370734
4a409382
2299f31d
0082efa9
8ec4e6c8
9452821e
638d0137
7be5466c
f34e90e8
8

//我们把
“
3243f6a8885a308d
”
这个16进制数
命名为Kun数,或“新密率3243f6a”数
*/
=======
// kunGmpKunPi20220101.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}//main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
>>>>>>> fb94fb715ab00ea7f616f793c450051ed2c1728f
