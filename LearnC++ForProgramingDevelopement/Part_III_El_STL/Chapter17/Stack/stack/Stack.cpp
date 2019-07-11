using MyStack = std::stack<int>;

MyStack myStack;
myStack.emplace(0);
myStack.push(1);
myStack.push(2);

std::cout << "Top of the stack: " << myStack.top() << std::endl;

myStack.pop();
std::cout << "Top of the stack: " << myStack.top() << std::endl;