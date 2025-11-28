int solution(int A, int B, int K) {
    // Implement your solution here
    //求在A~B之间能被K整除的数，这些数有多少个
    //假设P(x,k)为 从0开始到x能被k整除的数个数
    //那么从 A到B 能被k整除的数个数 为P(B,K) - P(A-1,K) 包括A本身
    // 如A = 6 B = 11 K = 2
    // P(11,2) = 2,4,6,8,10 = 5
    // P(6,2) = 2,4,6 = 3
    // P(B,K) - P(A,K) = 2 少算 6本身,所以用P(B,K) - P(A-1,K)
    auto P = [](int X,int K)->int{
        return X/K + 1; //公式 从[0,X]范围有多少个被K整除的数，包括0
    };
    if(A == 0) return P(B,K);//注意A为0的情形
    return P(B,K) - P(A-1,K);

}