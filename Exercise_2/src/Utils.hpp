#ifndef Utils_HPP
#define Utils_HPP
#include <fstream>
#include <string>
using namespace std;

// "count" is a function which counts how many rows there are after the header in the file given, meaning it counts how many pairs (w,r) there are.
// filename : path name of the input file
// return the number of row
size_t count(const string& filename);

// "write_in_outfile" is a function which writes the arrays to a file
// filename : path name of the output file
// arr : array
// size_arr : size of the array
void write_in_outfile(ofstream& filename, const double* const &arr, const size_t size_arr);

// "print" is a function that prints an array to the screen
// arr : pointer that points to the beginning of array
// size_arr : size of the array
void print(const double* const &arr, const size_t size_arr);

// "find_V" is a function which calculates the final value of the portfolio
// w: pointer that points to the beginning of allocated memory in which the fractions of S over time are stored
// r: pointer that points to the beginning of allocated memory in which the rates of return over time are stored
// s: single double value representing the initial investment
// size_arr: size of both w and r
// return the final value
double find_V(const double* const w,const double* const r, double s, const size_t size_arr);

// "find_rate" is a function which obtains the rate of return  of a financial asset
// w: pointer that points to the beginning of allocated memory in which the fractions of S over time are stored
// r: pointer that points to the beginning of allocated memory in which the rates of return over time are stored
// size_arr: size of both w and r
// return the rate of return
double find_rate(const double* const w,const double* const r, const size_t size_arr);
#endif
