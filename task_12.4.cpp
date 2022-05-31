#include <iostream>
#include <fstream>
#include <cmath>

int main() {

    unsigned n;
    std::cout << "n=";
    std::cin >> n;

    int* m = new int[n];
    double* p = new double[n];
    for (unsigned i = 0; i < n; i++) {
        std::cout << "m[" << i << "]=";
        std::cin >> m[i];
    }

    std::ifstream f1("t54_in.txt");
    if (f1.bad()) {
        std::cout << "Input File can't be read!";
    }

    unsigned i = 0;
    while (!f1.eof()) {
        if (f1 >> p[i]) {

            std::clog << i << "-th number =" << p[i] << std::endl;
            i++;
        }
        if (i >= n) break;
    }
    f1.close();

    if (i < n) {
        std::cout << "Not enough data in file";
    }

    std::ofstream f2("t54_out.txt");

    for (unsigned i = 0; i < n; ++i) {
        double z = pow(p[i], m[i]);
        f2 << z << "\n";
    }
    f2.close();

    delete[] m;
    delete[] p;
}