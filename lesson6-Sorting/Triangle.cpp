#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    int N = A.size();
    std::sort(A.begin(),A.end());
    for(int i = 2;i < N;i++){
        if(A[i-2] > A[i] - A[i-1])//两边之和大于第三边,避免加法溢出
            return 1;
    }
    return 0;
}
