#include <bits/stdc++.h>

using namespace std;

int prioritas(char tanda) {
    if (tanda == '^') return 3;
    if (tanda == '*' || tanda == '/') return 2;
    if (tanda == '+' || tanda == '-') return 1;
    return 0;
}

string toPostfix(string formula) {
    stack<char> operators;
    string result = "";

    for (char token : formula) {
        if (isalnum(token)) {
            result += token;
        } 
        else if (token == '(') {
            operators.push(token);
        } 
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        } 
        else {
            while (!operators.empty() && prioritas(operators.top()) >= prioritas(token)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    return result;
}

int main() {
    string input = "a+(2*b^3)/(f-g)+d*h";
    
    string hasil = toPostfix(input);

    cout << "Infix  : " << input << endl;
    cout << "Postfix   : " << hasil << endl;

    return 0;
}