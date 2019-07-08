using MyList = std::list<int>;

MyList myList = { 0, 1, 2 };
myList.push_back(3);
myList.push_back(4);
MyList::const_iterator iter = myList.cbegin();
++iter;
Iter = myList.insert(iter, 5);
myList.erase(iter);