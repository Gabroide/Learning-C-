//: C03:Enum.cpp
// Keeping track of shapes

enum ShapeType
{
	circle,
	square,
	rectangle,
}; // Must end with a semicolon like a struct

int main()
{
	ShapeType shape = circle;
	// Activities here...
	// Now do something based on what the shape is:
	switch(shape)
	{
		case circle:	
			/* Circel stuff */
			break;
		case square:
			/* Square stuff */
			break;
		case rectangle:	
			/* Rectangle stuff */
			break;
	}///:~
}
