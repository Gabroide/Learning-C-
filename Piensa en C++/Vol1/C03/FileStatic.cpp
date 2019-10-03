//: C03:FileStatic.cpp
// File scope demostration. Compiling and
// linking this file with FileStatic.cpp
// will cause a linker error

// File scope means oly available in this file:
static int fs;

int main()
{
	fs = 1;
} ///:~
