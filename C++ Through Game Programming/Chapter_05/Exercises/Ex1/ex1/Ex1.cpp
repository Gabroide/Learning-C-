// Exercise 1

// Wrong code
// int askNumber(int low = 1, int high)
//
// Solution
// The code is worng because it is assigning a default value to the first parameter but not the the following one.
// Once ou have assigned a default parameter value ypu MUST to assign a default value to the following ones.
// There are two ways of solve and create a right code
//
// Solution I
// Reversing the parameters
// int askNumber(int high, int low = 1)
//
// Solution II
// Giving a default parameter value to the following parameters
// int askNumber(int low = 1, int high = 10)