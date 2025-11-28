#include <algorithm>
int solution(vector<int> &A) {
    // Implement your solution here
    int ls = 0,rs = 0;//从P分割，左边之和与右边之和
    int N = A.size();
    auto sum = [](vector<int> &A, int start, int end)->int {
        int s = 0;
        for(int i = start ; i < end ;i++){
            s += A[i];
        }
        return s;
    };
    //P=1时
    ls = A[0];
    rs = sum(A,1,N);
    int res = abs(ls-rs);
    //P>1
    for(int p = 2; p < N; p++){
        ls += A[p-1];//多一个A[p-1]
        rs -= A[p-1];//少一个A[p-1]
        res = std::min(res,abs(ls-rs));
    }
    return res;
}
