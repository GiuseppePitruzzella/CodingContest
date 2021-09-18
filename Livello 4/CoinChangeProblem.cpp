#include <iostream>
#include <fstream>
using namespace std;

class Solution {
    int* coins;
    int N, W;
public:
    Solution(int* coins, int N, int W);
    void insertionSort(int *coins, int n);
    void CoinChangeProblem(ofstream &out);
    void printSolution();
};
Solution::Solution(int* coins, int N, int W) {
    this->N = N; // Numero di tagli di monete
    this->W = W; // Resto
    this->coins = coins; // Array dei tagli di monete
}

void Solution::CoinChangeProblem(ofstream &out) {
    int** M = new int*[N + 1];
    for (int i = 0; i < N + 1; i++) M[i] = new int[W];
    for (int i = 0; i < N + 1; i++) M[i][0] = 1;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < W; j++) {
            if (coins[i] > j) M[i][j] = M[i - 1][j];
            else M[i][j] = M[i - 1][j] + M[i][j - coins[i]];
        }
    }
    out << M[N][W - 1] << endl;
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
        in >> W;
        in >> N;
        int *A = new int[N];
        for (int j = 0; j < N; j++) {
            in >> _;
            A[j] = _;
        }
        Solution *S = new Solution(A, N, W);
        S->CoinChangeProblem(out);
    }
    return 0;
}
