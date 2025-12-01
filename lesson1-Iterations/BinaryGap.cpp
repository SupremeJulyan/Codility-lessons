#include <climits>
#include <algorithm>
using namespace std;
inline bool bit(int N,unsigned int x) {//第x位是0还是1
    return N & (1 << x);
}
int solution(int N) {
    // Implement your solution here
    int last_i = INT_MAX;//保证只有一个1时答案正确
    int max_gap = 0;
    int max_bit = sizeof(N) * 8;
    bool found_one = false;
    for(int i = 0; i < max_bit; i++) {
        if (bit(N, i)) {
            if (found_one) {
                max_gap = std::max(i - last_i - 1, max_gap);
            }
            last_i = i;
            found_one = true;
        }
    }
    return max_gap;
}