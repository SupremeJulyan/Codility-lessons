#include <vector>
using namespace std;
int solution(int X, vector<int> &A) {
    // Implement your solution here
    vector<bool> river(X+1,0);//第i个位置有无叶子
    int AN = A.size();
    int cnt = X;//记录河流还有多少位置没填上叶子
    for(int t = 0; t < AN ;t++){ 
        int pos = A[t];   
        if(pos >= 1 && pos <= X){ //这个位置在1~X以内
            if(river[pos]){//这个位置已有叶子，去重
                continue;
            }else{
                river[pos] = true;
                if(--cnt == 0) return t;
            }
        }
    }
    return -1;
}
