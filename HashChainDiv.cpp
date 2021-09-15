#include <iostream>
#include <fstream>
using namespace std;

template <class T> class Solution {
    T* hashTable;
    int N;
public:
    Solution(int N);
    int divisionMethod(int i);
    void printSolution(ofstream &out);
    void add(int i);
};
template <class T> Solution<T>::Solution(int N) {
    this->N = N;
    this->hashTable = new T[N];
    for (int i = 0; i < N; i++)
        hashTable[i] = 0;
}
template <class T> int Solution<T>::divisionMethod(int i) {
    return i % N;
}
template <class T> void Solution<T>::add(int i) {
    hashTable[divisionMethod(i)]+=1;
}
template <class T> void Solution<T>::printSolution(ofstream &out) {
    for (int i = 0; i < N; i++)
        out << hashTable[i] << " ";
    out << endl;
}

int main(int argc, char const *argv[]) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    for (int i = 0; i < 100; i++) {
        string type;
        int n, m;
        in >> type; 
        in >> n;
        in >> m;
        if (type == "int") {
            int *A = new int[m], item;
            Solution<int> *S = new Solution<int>(n);
            for (int j = 0; j < m; j++) {
                in >> item;
                S->add(item);
            }
            S->printSolution(out);
        } else if (type == "double") {
            double *A = new double[m], item;
            Solution<double> *S = new Solution<double>(n);
            for (int j = 0; j < m; j++) {
                in >> item;
                S->add(item);
            }
            S->printSolution(out);
        } else if (type == "char") {
            int *A = new int[m];
            char item;
            Solution<int> *S = new Solution<int>(n);
            for (int j = 0; j < m; j++) {
                in >> item;
                S->add((int)item);
            }
            S->printSolution(out);
        } else {
            bool *A = new bool[m], item;
            Solution<bool> *S = new Solution<bool>(n);
            for (int j = 0; j < m; j++) {
                in >> item;
                S->add(item);
            }
            S->printSolution(out);
        }
    }
}