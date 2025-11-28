#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int n = S.size();
    int m = P.size();
    vector<int> result(m);
    
    // 使用数组而不是map存储前缀和，提高访问速度
    vector<vector<int>> prefix(4, vector<int>(n + 1, 0));
    
    // 一次性构建所有字符的前缀和数组
    for (int i = 0; i < n; i++) {
        // 复制前一位置的值
        for (int j = 0; j < 4; j++) {
            prefix[j][i + 1] = prefix[j][i];
        }
        
        // 根据当前字符更新对应的前缀和
        switch (S[i]) {
            case 'A': prefix[0][i + 1]++; break;
            case 'C': prefix[1][i + 1]++; break;
            case 'G': prefix[2][i + 1]++; break;
            case 'T': prefix[3][i + 1]++; break;
        }
    }
    
    // 处理查询
    for (int i = 0; i < m; i++) {
        int start = P[i];
        int end = Q[i];
        
        // 按影响因子顺序检查（A=1, C=2, G=3, T=4）
        for (int j = 0; j < 4; j++) {
            if (prefix[j][end + 1] - prefix[j][start] > 0) {
                result[i] = j + 1;  // 影响因子是索引+1
                break;
            }
        }
    }
    
    return result;
}