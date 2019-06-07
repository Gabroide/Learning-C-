// Exercise 2

// Wrong code
vector<int>::iterator iter;

// increment each score
for (iter = scores.begin(); iter != scores.end(); ++iter)
{
	iter++;
}

// The code is wrong because the increment must be done to a pointer *iter.
// The right code should be like this:
vector<int>::iterator iter;

// increment each score
for (iter = scores.begin(); iter != scores.end(); ++iter)
{
	*iter++;
}