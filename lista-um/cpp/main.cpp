#include <bits/stdc++.h>
#include "structures/Stack.h"
#include "operators/BinaryOperator.h"
#include "operators/BinaryOperatorFactory.h"

#define endl '\n'
#define STACK_INT_SENTINEL -1
#define STACK_STRING_SENTINEL "SENTINEL"

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack<int> *stackHeadValues = Stack<int>::buildStackHead(STACK_INT_SENTINEL);
    Stack<string> *stackHeadInfix = Stack<string>::buildStackHead(STACK_STRING_SENTINEL);

    int totalExpressions;
    cin >> totalExpressions;

    for (int i = 0; i < totalExpressions; i++) {
        string action;
        string inputExpression;

        cin >> action >> inputExpression;

        if (action == "VAL") {
            for (char input : inputExpression) {
                if (input == '1' || input == '0') {
                    stackHeadValues->push(input - 48);
                } else if (input == '~') {
                    int z = stackHeadValues->pop();
                    stackHeadValues->push(!z);
                } else {
                    int z = stackHeadValues->pop();
                    int y = stackHeadValues->pop();

                    BinaryOperator *operation = BinaryOperatorFactory::buildBinaryOperator(input);
                    stackHeadValues->push(operation->operate(z, y));
                }
            }
            cout << stackHeadValues->pop() << endl;
        } else {
            for (char input : inputExpression) {
                if (input == '1' || input == '0') {
                    string inputAsString(1, input);
                    stackHeadInfix->push(inputAsString);
                } else if (input == '~') {
                    string z = stackHeadInfix->pop();
                    stackHeadInfix->push("(~" + z + ")");
                } else {
                    string z = stackHeadInfix->pop();
                    string y = stackHeadInfix->pop();
                    stackHeadInfix->push("(" + y + input + z + ")");
                }
            }

            cout << stackHeadInfix->pop() << endl;
        }
    }

    return 0;
}
