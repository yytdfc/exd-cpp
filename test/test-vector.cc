#include "exd.hpp"
#include "random.hpp"
#include <array>
#include <chrono>
#include <eigen3/Eigen/Core>
using namespace Eigen;
using namespace exd;
using namespace std;
using namespace chrono;
using Random = effolkronium::random_static;

const int n = 10;
template <typename T>
void mul(T& a, T& b, T& c) {
  // c = a · b
  for (size_t i = 0; i != n; ++i) {
    for (size_t j = 0; j != n; ++j) {
      a[i][j] = Random::get<double>(0, 1);
      b[i][j] = Random::get<double>(0, 1);
      c[i][j] = 0;
    }
  }
  for (size_t k = 0; k != n; ++k) {
    for (size_t i = 0; i != n; ++i) {
      for (size_t j = 0; j != n; ++j) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void mul_vector() {
  vector<vector<double>> a(n, vector<double>(n));
  vector<vector<double>> b(n, vector<double>(n));
  vector<vector<double>> c(n, vector<double>(n));
  mul(a, b, c);
}

void mul_std_array() {
  array<array<double, n>, n> a;
  array<array<double, n>, n> b;
  array<array<double, n>, n> c;
  mul(a, b, c);
}

void mul_array() {
  double a[n][n];
  double b[n][n];
  double c[n][n];
  mul(a, b, c);
}

void mul_new() {
  double** a = new double*[n];
  double** b = new double*[n];
  double** c = new double*[n];
  for (int i = 0; i != n; ++i) {
    a[i] = new double[n];
    b[i] = new double[n];
    c[i] = new double[n];
  }
  mul(a, b, c);
  for (int i = 0; i != n; ++i) {
    delete[] a[i];
    delete[] b[i];
    delete[] c[i];
  }
  delete[] a;
  delete[] b;
  delete[] c;
}

void mul_new2() {
  double** a = new double*[n];
  double** b = new double*[n];
  double** c = new double*[n];
  a[0] = new double[n * n];
  b[0] = new double[n * n];
  c[0] = new double[n * n];
  for (int i = 1; i != n; ++i) {
    a[i] = a[i - 1] + n;
    b[i] = b[i - 1] + n;
    c[i] = c[i - 1] + n;
  }
  mul(a, b, c);
  delete[] a[0];
  delete[] b[0];
  delete[] c[0];
  delete[] a;
  delete[] b;
  delete[] c;
}

void mul_eigen() {
  auto a = Matrix<double, n, n>::Random();
  auto b = Matrix<double, n, n>::Random();
  // auto c = Matrix<double, n, n>::Random();
  // auto c = Matrix<double, n, n>::Zero();
  // Matrix<double, n, n> c;
  auto c = a * b;
  // cout << c << endl;
}

void tic_toc(void f(), string name) {
  auto start = system_clock::now();
  f();
  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  cout << name << " using "
       << double(duration.count()) * microseconds::period::num /
              microseconds::period::den
       << " s." << endl;
}
int main() {
  // tic_toc(mul_vector, "vector");
  tic_toc(mul_new, "new");
  // tic_toc(mul_new2, "new2");
  // tic_toc(mul_array, "array");
  // // tic_toc(mul_std_array, "std_array");
  tic_toc(mul_eigen, "eigen");
}
