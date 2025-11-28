int solution(vector<int> &A) {
    // Implement your solution here
    //从1开始到N，在A中没出现的数
    int N = A.size();
    bool *P = new bool[N+1]{};
    for(const auto &a : A){
        if(a >= 1 && a <= N) P[a] = true;
    }
    for(int i = 1;i <= N; i++){
        if(P[i] == false) return i;
    }
    return N+1;//如果1~N全有，那最小正整数是N+1
}