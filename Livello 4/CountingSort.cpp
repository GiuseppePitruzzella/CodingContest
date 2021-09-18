#include <iostream>
#include <fstream>
using namespace std;
class Solution {
    int n, k;
    int* A, *B, *C;
public:
    Solution(int* A, int n);
    void CountingSort();
    void printSolution(ofstream& out);
    int getMax();
    int getMin();
};
Solution::Solution(int* A, int n) {
    this->A = A;
    this-> n = n;
}
int Solution::getMax() {
    int maxElement = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > maxElement) 
            maxElement = A[i];
    return maxElement;
}
int Solution::getMin() {
    int minElement = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] < minElement) 
            minElement = A[i];
    return minElement;
}

void Solution::CountingSort() {
    int minValue = getMin();
    k = getMax() - minValue + 1;
    C = new int[k];
    for (int i = 0; i < k; i++)
        C[i] = 0;
    for (int i = 0; i < n; i++)
        C[A[i] - minValue]++;
    B = new int[n];
    for (int i = 1; i < k; i++)
        C[i] += C[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i] - minValue] - 1] = A[i];
        C[A[i] - minValue]--;
    }
}
void Solution::printSolution(ofstream &out) {
    for (int i = 0; i < k; i++)
        out << C[i] << " ";
    for (int i = 0; i < n; i++)
        out << B[i] << " ";
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
        int n, _;
        in >> n;
        int *A = new int[n];
        for (int j = 0; j < n; j++) {
            in >> _;
            A[j] = _;
        }
        Solution *S = new Solution(A, n);
        S->CountingSort();
        S->printSolution(out);
    }
    return 0;
}
