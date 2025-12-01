#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    int N = A.size();
    std::sort(A.begin(),A.end());
    //最大三数乘积
    return std::max(A[N-1]*A[N-2]*A[N-3],//三个最大数
                    A[0]*A[1]*A[N-1]//两个最小数(负数)与一个最大数(正数)
    )

}
