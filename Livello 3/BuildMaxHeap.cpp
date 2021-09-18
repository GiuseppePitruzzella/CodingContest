#include <iostream>
#include <fstream>
using namespace std;
template <class T> class Solution {
    T* A;
    int n;
public:
    Solution(T* A, int n);
    void swapElements(int i, int j);
    void MaxHeapify(int i);
    void BuildMaxHeap();
    void printBinaryHeap(ofstream &out);
};
template <class T> Solution<T>::Solution(T* A, int n) {
    this->A = A;
    this->n = n;
}
template <class T> void Solution<T>::swapElements(int i, int j) {
    T _ = A[i];
    A[i] = A[j];
    A[j] = _;
}
template <class T> void Solution<T>::MaxHeapify(int i) {
    int max = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < n && A[max] < A[left]) max = left;
    if (right < n && A[max] < A[right]) max = right;
    if (max != i) {
        swapElements(i, max);
        MaxHeapify(max);
    }
}
template <class T> void Solution<T>::BuildMaxHeap() {
    for (int i = (n / 2) - 1; i >= 0; i--) MaxHeapify(i);
} 
template <class T> void Solution<T>::printBinaryHeap(ofstream &out) {
    for (int i = 0; i < n; i++)
        out << A[i] << " ";
    out << endl;
}
/*
        _.-"""-._
    _.-""         ""-._
  :"-.               .-":
  '"-_"-._       _.-".-"'
    ||T+._"-._.-"_.-"|
    ||:   "-.|.-" : ||
    || .   ' :|  .  ||
    ||  .   '|| .   ||
    ||   ';.:||'    ||
    ||    '::||     ||
    ||      )||     ||
    ||     ':||     ||
    ||   .' :||.    ||
    ||  ' . :||.'   ||
    ||.'-  .:|| -'._||
  .-'": .::::||:. : "'-.
  :"-.'::::::||::'  .-":
   "-."-._"--:"  .-".-"
      "-._"-._.-".-"
          "-.|.-"

       J     A     X
*/ 
int main(int argc, char const *argv[]) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    for (int i = 0; i < 100; i++) {
        string type;
        int n;
        in >> type; 
        in >> n;
        if (type == "int") {
            int *A = new int[n], _;
            for (int j = 0; j < n; j++) {
                in >> _;
                A[j] = _;
            }
            Solution<int> *S = new Solution<int>(A, n);
            S->BuildMaxHeap();
            S->printBinaryHeap(out);
        } else if (type == "double") {
            double *A = new double[n], _;
            for (int j = 0; j < n; j++) {
                in >> _;
                A[j] = _;
            }
            Solution<double> *S = new Solution<double>(A, n);
            S->BuildMaxHeap();
            S->printBinaryHeap(out);
        } else if (type == "char") {
            char *A = new char[n], _;
            for (int j = 0; j < n; j++) {
                in >> _;
                A[j] = _;
            }
            Solution<char> *S = new Solution<char>(A, n);
            S->BuildMaxHeap();
            S->printBinaryHeap(out);
        } else {
            bool *A = new bool[n], _;
            for (int j = 0; j < n; j++) {
                in >> _;
                A[j] = _;
            }
            Solution<bool> *S = new Solution<bool>(A, n);
            S->BuildMaxHeap();
            S->printBinaryHeap(out);
        }
    }
}
