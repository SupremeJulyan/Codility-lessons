#include <stack>
#include <string>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    //括号匹配
    stack<char> s;
    for(const auto & ch: S){
        if(ch == '('){
            s.push(ch);
            continue;
        }
        if(ch == ')' && s.top() != '(') return 0;
        s.pop();
    }
    return s.empty();
}