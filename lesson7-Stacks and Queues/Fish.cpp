#include <stack>
#include <vector>
using namespace std;
int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    //A保存鱼的大小，B保存鱼来自上游0还是下游1
    //如果两条鱼相向游，中间没其他鱼，那么大鱼吃小鱼
    //返回剩下鱼数量
    stack<int> ds;//往下游的鱼
    int N = A.size();
    int us_alive = 0;//往上游的存活鱼
    for(int i = 0 ;i < N;i++){
        if(B[i] == 1){
            ds.push(A[i]);
        }else{//往上游的鱼往前回溯找有没有往下游的鱼
            while(!ds.empty() && A[i] > ds.top()){  //遇到比自己小的鱼就吃掉
                ds.pop();
            }
            if(ds.empty()) us_alive++; //没有遇到比自己大的鱼，说明存活下来
        }
    }
    return ds.size() + us_alive; //存活的下游鱼+存活的上游鱼

}