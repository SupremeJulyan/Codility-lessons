#include <vector>
#include <string>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    //PQ分别给定起止范围，求S在这个范围的影响因子最小值
    int SN = S.size();
    int PN = P.size();
    vector<vector<int>> prefix_sums(4,vector<int>(SN+1,0));//为ACGT各创建一个前缀和，保存出现次数
    for(int i = 0 ; i < SN ; i++){
        for(int j = 0 ; j < 4 ; j++){
            prefix_sums[j][i+1] = prefix_sums[j][i];
        }
        switch (S[i]) {
            case 'A' : prefix_sums[0][i+1]++;break;
            case 'C' : prefix_sums[1][i+1]++;break;
            case 'G' : prefix_sums[2][i+1]++;break;
            case 'T' : prefix_sums[3][i+1]++;break;
        }
    }
    vector<int> res;
    for(int i = 0; i < PN ; i++){
        int x = P[i];
        int y = Q[i];
        for (int j = 0 ; j < 4 ;j++){//按ACGT顺序的话，只要出现就是最小值
            if(prefix_sums[j][y+1] > prefix_sums[j][x]){//P[y] - P[x-1] > 0排除x,start,end是下标，还要都+1
                res.push_back(j+1);
                break;
            }
        }
    }
    return res;
}