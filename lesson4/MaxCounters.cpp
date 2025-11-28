#include <algorithm>
vector<int> solution(int N, vector<int> &A) {
    // Implement your solution here
    //N=5,counter = {0,0,0,0,0}
    //A[0] = 3  1<=3<=5 increase 对第3个数+1
    //A[3] = 6 6 = 5+1 max  把所有数设置为最大值。
    vector<int> counter(N,0);
    int max_c = 0;//一次操作的最大值
    int last_max_c = 0;//上次操作的最大值
    for(const auto &a : A){
        if(a >=1 && a <= N){
            counter[a-1] = std::max(counter[a-1],last_max_c);//设置最大值
            counter[a-1]++;
            max_c = std::max(counter[a-1],max_c);//更新本次操作的最大值
        }else if(a == N+1){
            last_max_c = max_c;//不在这里循环设置最大值，在元素需要+1的时候才设置最大值
        }
    }
    //剩下没被设置最大值设置最大值
    for(auto &c : counter){
        c = std::max(c,last_max_c);
    }
    return counter;
}