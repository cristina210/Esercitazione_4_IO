#include "Utils.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
//
size_t count(const string& filename){
    ifstream ifs(filename);
    size_t n = 0; // it'll be the size of an array
    string line;
    getline(ifs, line);
    getline(ifs, line);
    getline(ifs, line);
    while (std::getline(ifs, line)) {
        ++n;
    }
    ifs.close();
    return n;
}
//
void write_in_outfile(ofstream& fout, const double* const &arr, const size_t size_arr){
    fout << "[";
    unsigned int i = 0;
    while (i<size_arr){
        fout <<" "<<arr[i]<<" ";
        i=i+1;
    }
    fout << "]"<<endl;
}
//
void print(const double* const &arr, const size_t size_arr){
    cout << "[";
    unsigned int i = 0;
    while (i<size_arr){
        cout <<" "<<arr[i]<<" ";
        i=i+1;
    }
    cout << "]"<<endl;

}
//
double find_V(const double* const w,const double* const r, double s, const size_t size_arr){
    double V = 0 ;
    unsigned int i = 0;
    while (i<size_arr){
        V = V+((w[i]*s)*(1+r[i]));
        i=i+1;
    }
    return V;
}
//
double find_rate(const double* const w,const double* const r, const size_t size_arr){
    double rate = 0 ;
    unsigned int i = 0;
    while (i<size_arr){
        rate = rate + (w[i]*r[i]);
        i=i+1;
    }
    return rate;
}
