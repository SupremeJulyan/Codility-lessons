#include <vector>
using namespace std;
//放到另一个n+1大小的数组中，空的那个就是少的元素
int solution(vector<int> &A) {
    // Implement your solution here
    int Bsize  = A.size()+1;
    int *B = new int[Bsize]{};//第i-1个元素就是i
    for(const auto & a : A){
        B[a-1] = a;
    }
    for(int i = 0 ; i < Bsize;i++){
        if(B[i] == 0){
            return i+1;
        }
    }
    return 0;
}

