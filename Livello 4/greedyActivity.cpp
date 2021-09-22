#include <iostream>
#include <fstream>
using namespace std;
class Node {
    int i, f;
public:
    Node(int i, int f) {
        this->i = i;
        this->f = f;
    }
    int getStart() { return i; }
    int getFinish() { return f; }
    int getProfit() { return f - i; }
};
class Solution {
    Node** A;
    int items;
public:
    Solution(int* B, int* C, int items);
    int getMax();
    int getMin();
    Node** sortArray();
    void printArray();
    void activitySelection(ofstream &out);
};
Solution::Solution(int* B, int* C, int items) {
    this->items = items;
    A = new Node*[items];
    for (int i = 0; i < items; i++)
        A[i] = new Node(B[i], C[i]);
}
int Solution::getMax() {
    int max = A[0]->getFinish();
    for (int i = 1; i < items; i++)
        if (A[i]->getFinish() > max)
            max = A[i]->getFinish();
    return max;
}
int Solution::getMin() {
    int min = A[0]->getFinish();
    for (int i = 1; i < items; i++)
        if (A[i]->getFinish() < min)
            min = A[i]->getFinish();
    return min;
}
Node** Solution::sortArray() {
    int minValue = getMin();
    int k = getMax() - minValue + 1;
    int *K = new int[k];
    for (int i = 0; i < k; i++)
        K[i] = 0;
    for (int i = 0; i < items; i++)
        K[A[i]->getFinish() - minValue]++;
    Node **B = new Node*[items];
    for (int i = 1; i < k; i++)
        K[i] += K[i - 1];
    for (int i = items - 1; i >= 0; i--) {
        B[K[A[i]->getFinish() - minValue] - 1] = A[i];
        K[A[i]->getFinish() - minValue]--;
    }
    return B;
}
void Solution::printArray() {
    A = sortArray();
    for (int i = 0; i < items; i++)
        cout << "( " << A[i]->getStart() << " " << A[i]->getFinish() << " ) ";
    cout << endl;
}
void Solution::activitySelection(ofstream &out) {
    A = sortArray();
    int j = 0, startPoint = A[0]->getFinish(), activitiesSelected = 1;
    for (int i = 1; i < items; i++) {
        if (A[i]->getStart() >= startPoint) {
            activitiesSelected++;
            startPoint = A[i]->getFinish();
        }
    }
    out << activitiesSelected << endl;
}
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    for (int i = 0; i < 100; i++) {
        int items;
        in >> items;
        int *A = new int[items], *B = new int[items], item;
        char c;
        for (int j = 0; j < items; j++) { // With comma version
            in >> c;
            in >> item;
            A[j] = item;
            in >> item;
            in >> c;
            B[j] = item;
        }
        Solution *S = new Solution(A, B, items);
        S->activitySelection(out);
    }

}