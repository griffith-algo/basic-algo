/**
 * @file prob4.cpp
 * @brief C++ version of the call-centre, order-queue, and postfix-calculator example.
 */

#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct Call {
    int priority;
    string caller;

    /**
     * @brief Reverse the comparison so smaller priority numbers are served first.
     * @param other const Call& Another call record used by the priority queue.
     * @return bool True when this call should come after other inside the heap structure.
     */
    bool operator<(const Call& other) const {
        return priority > other.priority;
    }
};

class CallCenter {
public:
    /**
     * @brief Add a new call to the priority queue.
     * @param priority int Priority number of the caller. Smaller values mean more urgent calls.
     * @param caller const string& Name of the caller.
     * @return void This method updates the queue and does not return a value.
     */
    void add_call(int priority, const string& caller) {
        calls.push(Call{priority, caller});
    }

    /**
     * @brief Answer the next call.
     * @return string Name of the caller who should be served next, or an empty string when no calls remain.
     */
    string answer_call() {
        if (calls.empty()) {
            return "";
        }
        string caller = calls.top().caller;
        calls.pop();
        return caller;
    }

private:
    priority_queue<Call> calls;
};

struct CustomerOrder {
    int order_number;
    string customer;
};

class OrderQueue {
public:
    /**
     * @brief Add a new customer order to the back of the queue.
     * @param order_number int Identifier of the order.
     * @param customer const string& Name of the customer who placed the order.
     * @return void This method updates the queue and does not return a value.
     */
    void add_order(int order_number, const string& customer) {
        orders.push(CustomerOrder{order_number, customer});
    }

    /**
     * @brief Send the next order using first-in, first-out order.
     * @return string Name of the customer whose order is sent next, or an empty string when no orders remain.
     */
    string send_order() {
        if (orders.empty()) {
            return "";
        }
        string customer = orders.front().customer;
        orders.pop();
        return customer;
    }

private:
    queue<CustomerOrder> orders;
};

class Calculator {
public:
    /**
     * @brief Evaluate a postfix expression with integer arithmetic.
     * @param expression const string& Space-separated postfix expression.
     * @return int Computed integer result of the expression.
     */
    int calculate(const string& expression) {
        vector<int> stack;
        string token;

        for (char character : expression) {
            if (character == ' ') {
                if (!token.empty()) {
                    process_token(token, stack);
                    token.clear();
                }
            } else {
                token.push_back(character);
            }
        }
        if (!token.empty()) {
            process_token(token, stack);
        }
        if (stack.size() != 1) {
            throw runtime_error("Invalid expression");
        }
        return stack.back();
    }

private:
    /**
     * @brief Process one token from the postfix expression.
     * @param token const string& Current token, either a number or an operator.
     * @param stack vector<int>& Evaluation stack used by the postfix algorithm.
     * @return void This helper updates the stack and does not return a value.
     */
    void process_token(const string& token, vector<int>& stack) {
        if (isdigit(static_cast<unsigned char>(token[0]))) {
            stack.push_back(stoi(token));
            return;
        }

        int operand2 = stack.back();
        stack.pop_back();
        int operand1 = stack.back();
        stack.pop_back();

        if (token == "+") {
            stack.push_back(operand1 + operand2);
        } else if (token == "-") {
            stack.push_back(operand1 - operand2);
        } else if (token == "*") {
            stack.push_back(operand1 * operand2);
        } else if (token == "/") {
            stack.push_back(operand1 / operand2);
        } else {
            throw runtime_error("Invalid operator");
        }
    }
};

/**
 * @brief Run the queue and calculator demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    CallCenter cc;
    cc.add_call(3, "John");
    cc.add_call(1, "Jane");
    cc.add_call(2, "Jim");
    cout << cc.answer_call() << '\n';
    cout << cc.answer_call() << '\n';
    cout << cc.answer_call() << '\n';
    cout << cc.answer_call() << '\n';

    OrderQueue oq;
    oq.add_order(1, "John");
    oq.add_order(2, "Jane");
    oq.add_order(3, "Jim");
    cout << oq.send_order() << '\n';
    cout << oq.send_order() << '\n';
    cout << oq.send_order() << '\n';
    cout << oq.send_order() << '\n';

    Calculator calc;
    cout << calc.calculate("5 1 2 + 4 * + 3 -") << '\n';
    return 0;
}
