#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    //异或特性 0^N=N N^N=0 ,出现偶数此的最终为0，剩下的就是出现奇数次的
    int res = 0;
    for(auto &a : A){
        res = a ^ res;
    }
    return res;
}