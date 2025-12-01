#include <stack>
#include <vector>
using namespace std;
int solution(vector<int> &H) {
    // Implement your solution here
    // 石头是一个矩形，厚度固定为1 H[i] 和 H[i+1] 组成一个1×h[i]的块，返回块数
    // 只要找到两个相同高度的点H[x] = H[y] 且 x~y中间没有比xy矮的点，就可以组成一个块
    stack<int> s;
    int res = 0;
    for(const auto & h : H){
        // 弹出所有比当前高度高的栈顶元素
        while(!s.empty() && h < s.top()){
            s.pop();
            res++;
        }
        // 只有当栈为空或当前高度大于栈顶时，才需要压入新高度
        if (s.empty() || h > s.top()) {
            s.push(h);
        }
        
    }
    return res+s.size();
}
