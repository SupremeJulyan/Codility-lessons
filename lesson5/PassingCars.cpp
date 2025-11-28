int solution(vector<int> &A) {
    // Implement your solution here
    //0往东为P车，1往西为Q车，且P的位置在Q前，为一对相向而行的车，返回多少对车
    int N = A.size();
    unsigned int res = 0;
    int *P = new int[N]{};
    P[0] = A[0];
    for(int i = 0; i < N ; i++){
        P[i+1] = P[i] + A[i];
    }
    //此时P[i]表示，i时刻有P[i]辆Q车驶过。
    //假设i=x时，有P车驶过，从x~y=N 这个时间段的Q车都可以和他配对
    //pair = P[N-1] - P[x]
    for(int j = 0; j < N;j++){
        if(A[j] == 0)//P车
            res += (P[N-1] - P[j]);
    }
    return res > 1000000000 ? -1 : res;
}