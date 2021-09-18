#include <iostream>
#include <fstream>
using namespace std;
template <class T> class Solution {
    T* A;
    int items, n, heapifyCalls;
    int getParent(int i) { return (i - 1) / 2; }
public:
    Solution(T* A, int n);
    void swapElements(int i, int j);
    void insertElement(T k);
    void maxHeapify(int i);
    void BuildMaxHeap();
    T extractMax();
    void printSolution(ofstream &out);
};
template <class T> Solution<T>::Solution(T* A, int n) {
    this->A = A;
    this->n = n;
    this->heapifyCalls = 0;
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
template <class T> void Solution<T>::maxHeapify(int i) {
    heapifyCalls++;
    int min = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < items && A[min] > A[left]) min = left;
    if (right < items && A[min] > A[right]) min = right;
    if (min != i) {
        swapElements(i, min);
        if (items > 1) maxHeapify(min);
    }
}
template <class T> T Solution<T>::extractMax() {
    T minValue = A[0];
    swapElements(0, items - 1);
    items--;
    if (items > 0) maxHeapify(0);
    return minValue;
}
template <class T> void Solution<T>::printSolution(ofstream &out) {
    out << heapifyCalls << " ";
    for (int i = 0; i < items; i++)
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
            string op;
            for (int j = 0; j < n; j++) {
                in >> op;
                if (op[1] == ':')
                    S->insertElement(stoi(op.substr(op.find(':') + 1, op.length() - op.find(':'))));
                else S->extractMax();
            }
            S->printSolution(out);
        } else if (type == "double") {
            double *A = new double[n], item;
            Solution<double> *S = new Solution<double>(A, n);
            string op;
            for (int j = 0; j < n; j++) {
                in >> op;
                if (op[1] == ':')
                    S->insertElement(stod(op.substr(op.find(':') + 1, op.length() - op.find(':'))));
                else S->extractMax();
            }
            S->printSolution(out);
        } else if (type == "char") {
            char *A = new char[n], item;
            Solution<char> *S = new Solution<char>(A, n);
            string op;
            for (int j = 0; j < n; j++) {
                in >> op;
                if (op[1] == ':')
                    S->insertElement(op[2]);
                else S->extractMax();
            }
            S->printSolution(out);
        } else {
            bool *A = new bool[n], item;
            Solution<bool> *S = new Solution<bool>(A, n);
            string op;
            for (int j = 0; j < n; j++) {
                in >> op;
                if (op[1] == ':')
                    S->insertElement(stoi(op.substr(op.find(':') + 1, op.length() - op.find(':'))));
                else S->extractMax();
            }
            S->printSolution(out);
        }
    }
}
