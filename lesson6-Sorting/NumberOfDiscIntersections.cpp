#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int binSearch(vector<long long> &A, long long x) {
    int low = 0, high = A.size() - 1;
    int result = A.size();  // 默认返回末尾位置
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // 防止溢出
        if (A[mid] > x) {
            result = mid;  // 记录可能的位置
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;  // 返回第一个大于x的位置
}
int solution(vector<int> &A) {
    // Implement your solution here
    //A[1] = 5 表示 圆心是1，半径是5
    //返回任意一对圆盘有交点的个数
    //思路：从圆心在 最左边的圆盘i开始，查看右边的圆盘j的左边界是否小于等x的右边界
    int N = A.size();
    // 使用long long防止溢出
    vector<long long> lefts;
    vector<long long> rights;
    
    for(int i = 0; i < N; i++) {
        // 安全转换：先将int转换为long long再计算
        long long center = static_cast<long long>(i);
        long long radius = static_cast<long long>(A[i]);
        
        lefts.push_back(center - radius);
        rights.push_back(center + radius);
    }
    int res = 0;
    //不排序，O（n^2） 超时
    // for(int i = 0 ; i < N ;i++){
    //     for(int j = i+1 ; j < N ; j++){
    //         if(rights[i] > lefts[j])
    //             res++;
    //     }
    // }

    // 按左边界排序
    sort(lefts.begin(),lefts.end());
    for(int i = 0 ; i < N ;i++){
        long long r = rights[i];
        int j = binSearch(lefts,r);//二分查找r在lefts里的位置j，<j的坐标的左边界都可以和r相交
        res += j-(i+1);//i+1表示每次遍历rights数组都会多一次来自本身的左边界被重复计算，所以要减掉
        if (res > 10000000) {
            return -1;
        }
    }
    return res;
}
