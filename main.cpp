#include <iostream>

using namespace std;

// /********** Stack Implementation **********\

const int MAX_SIZE = 100;
template<class t>

class stack {
	int top;
	t item[MAX_SIZE];
public:
	stack() :top(-1) {}
	bool isEmpty()
	{
		return top < 0;
	}

	void push(t Element)
	{
		if (top >= MAX_SIZE - 1)
		{
			cout << "Stack full on push";
		}
		else
		{
			top++;
			item[top] = Element;
		}
	}
	void pop()
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else
			top--;
	}
	void pop(t& Element)
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else {
			Element = item[top];
			top--;
		}
	}
	void getTop(t& stackTop)
	{
		if (isEmpty())
			cout << "stack empty on getTop";
		else {
			stackTop = item[top];
			cout << stackTop << endl;
		}
	}
	void print() {
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;

	}
};

void run_stack() {
	stack<string>s;
	s.push("sameh");
	s.push("ahmed");
	s.push("mohamed");
	s.pop();
	s.push("younis");
	s.print();
}

// /********** Stack Using Linked List Implementation **********\

template<class t>

class Stack {
private:
	struct StackNode
	{
		t item;
		StackNode* next;
	};
	StackNode* topPtr, * curPtr;
public:
	Stack() {
		topPtr = NULL;
	}
	bool isEmpty()
	{
		return topPtr == NULL;
	}
	void push(t newItem)
	{
		StackNode* newPtr = new StackNode;
		if (newPtr == NULL)
			cout << "Stack push cannot allocate memory";
		else
		{
			newPtr->item = newItem;
			newPtr->next = topPtr;
			topPtr = newPtr;
		}
	}
	void pop() {
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			StackNode* temp = topPtr;
			topPtr = topPtr->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void pop(t stackTop)
	{
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			stackTop = topPtr->item;
			StackNode* temp = topPtr;
			topPtr = topPtr->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void getTop(t stackTop)
	{
		if (isEmpty())
			cout << "stack empty on getTop";
		else
			stackTop = topPtr->item;
		cout << "\nTop Element of the stack is " << stackTop;
		cout << endl;
	}
	void display()
	{
		curPtr = topPtr;
		cout << "\nItems in the stack : ";
		cout << "[ ";
		while (curPtr != NULL)
		{
			cout << curPtr->item << " ";
			curPtr = curPtr->next;
		}
		cout << " ]\n";
	}
};

void run_stack_2() {
	Stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	s.push(50);
	int x = 0;


	s.display();

	s.getTop(x);

}

// /********** Balanced Parentheses Using Stack {([ ])} **********\

bool ArePair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;
	return false;
}

bool AreBalanced(string exp)
{
	stack<char>  S;
	int length = exp.length();
	for (int i = 0; i < length; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

void run_AreBalanced_ArePair(){

	string expression;
	cout << "Enter an expression:";
	cin >> expression;
	if (AreBalanced(expression))
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
}

// /********** Expression Evaluation Using Stack **********\

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

int performOperation(int op1, int op2, char op)
{
	int ans;
	switch (op) {
	case '+':
		ans = op2 + op1;
		break;
	case '-':
		ans = op2 - op1;
		break;
	case '*':
		ans = op2 * op1;
		break;
	case '/':
		ans = op2 / op1;
		break;
	}
	return ans;
}


int run_performOperation_isOperator()
{
	char exp[1000], buffer[15];
	int i, op1, op2, len, j, x;
	stack<int> s;
	cout << "Enter a Postfix Expression: ( e.g. 4 5 * )\n";
	cin.getline(exp, 1000);
	len = strlen(exp);
	j = 0;
	for (i = 0; i < len; i++) {

		if (exp[i] >= '0' && exp[i] <= '9') {
			buffer[j++] = exp[i];
		}
		else if (exp[i] == ' ') {
			if (j > 0) {
				buffer[j] = '\0';
				x = atoi(buffer);
				s.push(x);
				j = 0;
			}
		}

		else if (isOperator(exp[i])) {
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(performOperation(op1, op2, exp[i]));
		}
	}
	cout << "Answer = " << s.top();
}

// /********** Infix To Postfix Using Stack **********\

    // Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

    // Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

    // Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

    // Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

void runInfixToPostfix ()
{
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";
}

    // Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++.
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for (unsigned int i = 0; i < expression.length(); i++) {

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

    // Function to verify whether a character is english letter or numeric digit.
    // We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

    // Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

    // Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

    // Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

    // Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}

// /********** Queue Implementation Using Circular Array **********\

class arrayQueueType
{
	int rear;
	int front;
	int length;
	int *arr;
	int maxSize;

public:
	arrayQueueType(int size) {
		if (size <= 0)
			maxSize = 100;
		else
			maxSize = size;

		front = 0;

		arr = new int[maxSize];
		rear = maxSize - 1;
		length = 0;
	}
	int isEmpty()
	{
		return length == 0;
	}
	bool isFull()
	{
		return length == maxSize;
	}
	void addQueue(int Element)
	{
		if (isFull())
		{
			cout << "Queue Full Can't Enqueue ...!";
		}
		else
		{
			rear = (rear + 1) % maxSize;
			arr[rear] = Element;
			length++;
		}


	}
	void deleteQueue()
	{
		if (isEmpty())
		{
			cout << "Empty Queue Can't Dequeue ...!";
		}
		else
		{
			front = (front + 1) % maxSize;
			--length;

		}


	}
	int frontQueue()
	{
		assert(!isEmpty());
		return arr[front];
	}

	int rearQueue()
	{
		assert(!isEmpty());
		return arr[rear];
	}


	void printQueue()
	{
		if (!isEmpty()) {
			for (size_t i = front; i != rear; i = (i + 1) % maxSize)
			{
				cout << arr[i] << " ";
			}
			cout << arr[rear];
		}
		else
			cout << "Empty Queue";
	}


	int queueSearch(int element) {
		int pos = -1;
		if (!isEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % maxSize)
				if (arr[i] == element)
				{
					pos = i;
					break;
				}
			if (pos == -1)
			{
				if (arr[rear] == element)
					pos = rear;
			}
		}
		else
			cout << "Q is empty ! " << endl;
		return pos;
	}


	~arrayQueueType() {
		delete[]arr;
	}
};

void runQueue()
{
	arrayQueueType q1(5);
	q1.addQueue(10);
	q1.addQueue(20);
	q1.addQueue(30);
	q1.addQueue(40);
	q1.addQueue(50);

	q1.deleteQueue();
	q1.deleteQueue();

	q1.addQueue(60);
	q1.addQueue(70);

	cout << q1.queueSearch(60) << endl;
	cout << q1.queueSearch(70) << endl;

	q1.printQueue();
}

int main()
{

}
