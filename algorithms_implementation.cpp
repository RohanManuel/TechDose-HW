
/*
1. Implement:
(i) Previous Greater Element
(ii) Previous Smaller Element
(iii) Next Greater Element
(iv) Next Smaller Element
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Previous Greater Element
vector<int> previousGreaterElement(vector<int>& arr) {
    vector<int> result(arr.size());
    stack<int> s;
    
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        result[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return result;
}

// Previous Smaller Element
vector<int> previousSmallerElement(vector<int>& arr) {
    vector<int> result(arr.size());
    stack<int> s;
    
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        result[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return result;
}

// Next Greater Element
vector<int> nextGreaterElement(vector<int>& arr) {
    vector<int> result(arr.size());
    stack<int> s;
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        result[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return result;
}

// Next Smaller Element
vector<int> nextSmallerElement(vector<int>& arr) {
    vector<int> result(arr.size());
    stack<int> s;
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        result[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return result;
}

/*
2. Solve Leetcode Problems:
(i) Stock Span Problem
(ii) Online Stock Span Problem
(iii) Car Fleet Problem
(iv) Car Fleet Problem II
*/

// (i) Stock Span Problem
vector<int> stockSpan(vector<int>& prices) {
    vector<int> span(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        span[i] = (s.empty()) ? i + 1 : i - s.top();
        s.push(i);
    }
    
    return span;
}

// (ii) Online Stock Span Problem
class StockSpanner {
public:
    stack<pair<int, int>> s;
    int index;
    
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        while (!s.empty() && s.top().second <= price) {
            s.pop();
        }
        int span = s.empty() ? index + 1 : index - s.top().first;
        s.push({index, price});
        return span;
    }
};

// (iii) Car Fleet Problem
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    for (int i = 0; i < position.size(); i++) {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end());

    int fleets = 0;
    double timeToTarget = -1;
    for (int i = cars.size() - 1; i >= 0; i--) {
        double time = (double)(target - cars[i].first) / cars[i].second;
        if (time > timeToTarget) {
            fleets++;
            timeToTarget = time;
        }
    }
    
    return fleets;
}

// (iv) Car Fleet Problem II
vector<double> carFleetII(vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<double> answer(n, -1.0);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && speed[i] <= speed[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            answer[i] = (double)(position[s.top()] - position[i]) / (speed[i] - speed[s.top()]);
        }
        s.push(i);
    }
    
    return answer;
}

/*
3. Expression Evaluation:
(i) Basic Calculator I/II/III
(ii) Infix, Prefix, Postfix
*/

// Infix to Postfix conversion
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;
    
    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

// (iv) Queue using Stack
class QueueUsingStack {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }
};

// (iv) Stack using Queue
class StackUsingQueue {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topVal = q1.front();
        q1.pop();
        swap(q1, q2);
        return topVal;
    }
};
