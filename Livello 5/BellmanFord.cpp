#include <iostream>
#include <fstream>
using namespace std;
template <class T> class Solution {
    int** adjMatrix;
    T* A;
    int n;
public:
    Solution(T* A, int n);
    void addEdge(T i, T j, int weight);  
    void insertionSort();
    int searchVertex(T i);
    void BellmanFord(int s);
    void scanGraph(int s) {}
    void relaxNodes(int s) {}
};
template <class T> Solution<T>::Solution(T* A, int n) {
    this->A = A;
    this->n = n;
    adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) 
        adjMatrix[i] = new int[n];
    insertionSort();
}
template <class T> void Solution<T>::insertionSort() {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
template <class T> void Solution<T>::addEdge(T i, T j, int weight) {
    i = searchVertex(i);
    j = searchVertex(j);
    if (i > 0 && j > 0) adjMatrix[i][j] = weight;
}
template <class T> int Solution<T>::searchVertex(T k) {
    for (int i = 0; i < n; i++)
        if (A[i] == k)
            return i;
    return -1;
}
template <class T> void Solution<T>::BellmanFord(int s) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    } cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
template <class T> void Solution<T>::scanGraph(int s) {}
template <class T> void Solution<T>::relaxNodes(int s) {}

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
        in >> n; 
        in >> m;
        in >> type;
        if (type == "int") {
            int *A = new int[n], _;
            for (int j = 0; j < n; j++) {
                in >> _;
                A[j] = _;
            }
            Solution<int> *S = new Solution<int>(A, n);
            for(int i = 0; i < m; i++){
                string edge;
                in >> edge;
                int sourceVertex = stod(edge.substr(1, edge.find(',')-1));
                string _ = edge.substr(edge.find(",")+1, edge.length()-edge.find(",")-1);
                int destVertex = stod(_.substr(0, _.find(",")));
                int weight = stoi(_.substr(_.find(",")+1, _.length()-_.find(",")-1));
                S->addEdge(sourceVertex, destVertex, weight);
            }
            S->BellmanFord(0);
            // ( 11 , 22 , 33 )
            // _ __ _ __ _ __ _
            // 1 2  3 4  5  6 7 
            // stod(edge.substr(1, edge.find(","))) = stod(edge.substr(1, 3));
            // stod(edge.substr(edge.find(",")+1, edge.length()-1-edge.find(","))) = stod(edge.substr(3+1, 7-1-3));
        } else if (type == "double") {}
    }
}
