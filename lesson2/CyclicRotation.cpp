vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    int AN = A.size();
    if(AN < 2){
        return A;
    }
    for(int i = 0; i < K ; i++){
        int last = A[AN-1];
        for(int j = AN-1;j > 0 ;j--){
            A[j] = A[j-1];
        }
        A[0] = last;
    }
    return A;
}
