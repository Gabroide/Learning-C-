using MyQueue = std::queue<int>;

MyQueue myQueue;
myQueue.emplace(0);
myQueue.emplace(1);
myQueue.emplace(2);

std::cout << "Front of the queue: " << myQueue.front() << std::endl;

myQueue.pop();