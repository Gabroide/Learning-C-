//: C03:static_cast.cpp
void func(int)
{	
}

int main()
{
	int i = 0x7fff;	// Max pos value = 32767
	long l;
	float f;
	
	// (1) Typical castless conversion:
	l = i;
	f = i;
	
	// Also works:
	l = static_cast<int>(i);
	static_cast<float>(i);
	
	// (2) Narrowing converstions:
	i = l; // May lost results
	i = f; // May lost results
	
	// Says "I know," eliminates warnings:
	i = static_cast<int>(i);
	i = static_cast<char>(i);
	
	// (3) Forcing conversion from void* :
	void* vp = &i;
	
	// Old way produces a dangerous conversion:
	float* fp = (float*) vp;
	
	// The new wau i equally dangerous:
	fp = static_cast<float*> (vp);
	
	// (4) Implicit type conversions, normally
	// performed by the compiler:
	double d = 0.0;
	int x = d; // Automatic type conversion
	x = static_cast<int>(d); // More explicit
	func(d); // Automatic conversio
	func(static_cast<int>(d)); // // More explicit
}///:~
