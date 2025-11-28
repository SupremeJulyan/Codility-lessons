int solution(int X, int Y, int D) {
    // Implement your solution here
    bool remainder = (Y-X) % D;
    return (Y-X) / D + remainder;
}