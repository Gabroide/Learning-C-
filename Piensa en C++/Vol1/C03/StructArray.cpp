//: C03;StructArray.cpp
// an array of struct

typedef struct
{
	int i, j, k;
} ThreeDPoints;

int main()
{
	ThreeDPoints p[10];
	for(int i = 0; i < 10; i++)
	{
		p[i].i = i +1;
		p[i].j = i + 2;
		p[i].k = i + 3;
	}
}///:~
