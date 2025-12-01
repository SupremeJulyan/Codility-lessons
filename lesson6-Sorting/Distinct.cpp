#include <unordered_set>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    std::unordered_set<int> s;
    for(const auto & a : A)
        s.insert(a);
    return s.size();
}