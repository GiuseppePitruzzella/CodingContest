#include <iostream>
#include <fstream>
using namespace std;
class Solution {
    string x, y;
    int n, m;
    int **M;
public:
    Solution(string x, string y);
    int EditDistance();
    void printMatrix();
    int minValue(int a, int b, int c);
};
Solution::Solution(string x, string y) {
    this->x = x; // Memorizzo la stringa x
    this->n = x.length();
    this->y = y;
    this->m = y.length();
    M = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
        M[i] = new int[m + 1];
}
int Solution::minValue(int a, int b, int c) {
    return min(min(a, b), c);
}
int Solution::EditDistance() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) M[i][j] = j;
            else if (j == 0) M[i][j] = i;
            else if (x[i - 1] == y[j - 1]) 
                M[i][j] = M[i - 1][j - 1];
            else M[i][j] = minValue(M[i - 1][j], M[i - 1][j - 1], M[i][j - 1]) + 1;
        }
    }
    return M[n][m];
}
void Solution::printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
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
        int _;
        string x, y;
        in >> _;
        in >> _;
        in >> x;
        in >> y;
        Solution *S = new Solution(x, y);
        out << S->EditDistance() << endl;
    }
    return 0;
}
