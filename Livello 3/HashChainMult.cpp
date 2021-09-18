#include <iostream>
#include <fstream>
using namespace std;

template <class T> class Solution {
    T* hashTable;
    int N;
    float c;
public:
    Solution(int N);
    int multMethod(T i);
    void printSolution(ofstream &out);
    void add(T i);
};
template <class T> Solution<T>::Solution(int N) {
    c = 0.61803;
    this->N = N;
    this->hashTable = new T[N];
    for (int i = 0; i < N; i++)
        hashTable[i] = 0;
}
template <class T> int Solution<T>::multMethod(T i) {
    return int(N * (i * c - int(i * c)));
}
template <class T> void Solution<T>::add(T i) {
    hashTable[multMethod(i)]+=1;
}
template <class T> void Solution<T>::printSolution(ofstream &out) {
    for (int i = 0; i < N; i++)
        out << hashTable[i] << " ";
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
            Solution<int> *S = new Solution<int>(n);
            for (int j = 0; j < m; j++) {
                in >> item;
                S->add(item);
            }
            S->printSolution(out);
        }
    }
}