//: C03:Global2.cpp
// Accssing external global variables
extern int globe; 
// (The global linker resolve the references)
void func()
{
	globe = 47;
}///:~
