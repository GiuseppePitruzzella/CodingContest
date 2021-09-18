#include <iostream>
#include <fstream>
using namespace std;
template <class T> class Solution {
    T* A;
    int n, items;
    int getParent(int i) { return (i - 1) / 2; }
public:
    Solution(T* A, int n);
    void swapElements(int i, int j);
    void insertElement(T k);
    void printBinaryHeap(ofstream &out);
};
template <class T> Solution<T>::Solution(T* A, int n) {
    this->A = A;
    this->n = n;
    this->items = items;
}
template <class T> void Solution<T>::swapElements(int i, int j) {
    T item = A[i];
    A[i] = A[j];
    A[j] = item;
}
template <class T> void Solution<T>::insertElement(T k) {
    A[items] = k;
    int i = items;
    items++;
    while (i > 0 && A[getParent(i)] > A[i]) {
        swapElements(i, getParent(i));
        i = getParent(i);
    }
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
            int *A = new int[n], item;
            Solution<int> *S = new Solution<int>(A, n);
            for (int j = 0; j < n; j++) {
                in >> item;
                S->insertElement(item);
            }
            S->printBinaryHeap(out);
        } else if (type == "double") {
            double *A = new double[n], item;
            Solution<double> *S = new Solution<double>(A, n);
            for (int j = 0; j < n; j++) {
                in >> item;
                S->insertElement(item);
            }
            S->printBinaryHeap(out);
        } else if (type == "char") {
            char *A = new char[n], item;
            Solution<char> *S = new Solution<char>(A, n);
            for (int j = 0; j < n; j++) {
                in >> item;
                S->insertElement(item);
            }
            S->printBinaryHeap(out);
        } else {
            bool *A = new bool[n], item;
            Solution<bool> *S = new Solution<bool>(A, n);
            for (int j = 0; j < n; j++) {
                in >> item;
                S->insertElement(item);
            }
            S->printBinaryHeap(out);
        }
    }
}
