#include <limits>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    //求所有切片中的最小平均值，切片size大于1,返回这个切片的开始下标
    int N = A.size();
    double min_avg = std::numeric_limits<double>::max();
    int res = 0;
    vector<int> P(N+1,0);
    for(int i = 0 ; i < N; i++){
        P[i+1] = P[i] + A[i];
    }
    //数学性质：最小平均片段的长度只能是2或3。因此，我们只需要检查所有长度为2和3的子数组即可。
    for(int i = 0; i < N; i++){
        if(i < N-1){
            double avg = (P[i+2] - P[i])/2.0;//切片大小就是2或者3，其实必要用前缀和
            if(avg < min_avg){
                min_avg = avg;
                res = i;
            }
        }
        if(i < N-2){
            double avg = (P[i+3] - P[i])/3.0;
            if(avg < min_avg){
                min_avg = avg;
                res = i;
            }
        }
    }
    return res;
}