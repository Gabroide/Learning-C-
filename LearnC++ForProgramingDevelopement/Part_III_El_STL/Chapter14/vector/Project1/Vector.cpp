// Adding items
using MyVector = std::vector<int>

MyVector myVector = {0, 1, 2};
myVector.push_back(3);
myVector.push_back(4);

// Erasin itesm
MyVector::const iterarot iter = myVector.begin() + 1;
myVectos.insert(iter, 5);
myVector.erase(iter);
