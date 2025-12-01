#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    int AN = A.size();
    bool *P = new bool[AN+1]{};//记录1~AN是否存在
    int cnt = AN;
    for(const auto &a :A){
        if(a >= 1 && a <= AN && !P[a]){
            P[a] = true;
            cnt--;
        }
    }
    return cnt == 0;
}