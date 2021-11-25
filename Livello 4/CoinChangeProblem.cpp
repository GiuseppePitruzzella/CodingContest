#include <iostream>
#include <fstream>
using namespace std;

class Solution {
    int** S;
public:
    Solution(int* A, int change, int n) {
        S = new int*[n];
        for (int i = 0; i < n; i++)
            S = new int*[change];
        
    }
};
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
        // Inizializzazione del resto da restituire, del numero di tagli disponibili e dell'iteratore
        int change, n, _;
        in >> change;
        in >> n;
        // Creo un array di lunghezza pari al numero di tagli
        int *A = new int[n];
        for (int j = 0; j < n; j++) {
            in >> _;
            A[j] = _;
        }
        // Creo l'oggetto Solution
        Solution *S = new Solution(A, r, n);
        // Trovo l'insieme minimo di monete necessarie per restituire il resto r.
        S->CoinChangeProblem(out);
    }
    return 0;
}
