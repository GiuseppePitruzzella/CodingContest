#include <iostream>
#include <fstream>
using namespace std;

class Solution {
    int* items;
    int N, W;
public:
    Solution(int* A, int N, int W);
    void insertionSort(int *items, int n);
    void knapsackProblem(ofstream &out);
    void printSolution();
};
Solution::Solution(int* items, int N, int W) {
    this->N = N;
    this->W = W;
    this->items = items;
}
void Solution::insertionSort(int* items, int N) {
    int i, key, j;
    for (i = 1; i < N; i++) {
        key = items[i];
        j = i - 1;
        while (j >= 0 && items[j] > key) {
            items[j + 1] = items[j];
            j = j - 1;
        }
        items[j + 1] = key;
    }
}
void Solution::knapsackProblem(ofstream &out) {
    insertionSort(items, N);
    int valueInKnapsack = 0;
    for (int i = N - 1; i >= N - W; i--)
        valueInKnapsack += items[i];
    out << valueInKnapsack << endl;
}
void Solution::printSolution() {
    cout << "N = " << N << endl;
    cout << "W = " << W << endl;
    for (int i = 0; i < N; i++)
        cout << items[i] << " ";
    cout << endl;
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
        int N;
        int W;
        int _;
        in >> N;
        in >> W;
        int *A = new int[N];
        for (int j = 0; j < N; j++) {
            in >> _;
            A[j] = _;
        }
        Solution *S = new Solution(A, N, W);
        S->knapsackProblem(out);
    }
    return 0;
}
