#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"
using namespace std;
int main()
{   // open file
    string filename_input = "data.csv";
    ifstream ifs(filename_input);
    if (ifs.fail()){
        cerr << "Input file not found";
        return 1;
    }
    string filename_output = "result.txt";
    ofstream fout(filename_output);
    if (fout.fail()){
        cerr << "Error in opening the output file";
        return 1;
    }
    // read the header from the input file and write it to the output file
    string line;
    getline(ifs, line);
    stringstream stream_line1(line);
    string name_of_S;
    string value_of_S;
    getline(stream_line1, name_of_S, ';');
    getline(stream_line1, value_of_S, ';');
    getline(ifs, line);
    double value_of_S_in_double = stod(value_of_S);
    stringstream stream_line2(line);
    string name_of_n;
    string value_of_n;
    getline(stream_line2, name_of_n, ';');
    getline(stream_line2, value_of_n, ';');
    fout <<name_of_S<< " = "<<fixed << setprecision(2) << value_of_S_in_double <<", "<< name_of_n<<" = "<< value_of_n<<endl;
    getline(ifs, line);
    stringstream stream_line3(line);
    string name_of_w;
    string name_of_r;
    getline(stream_line3, name_of_w, ';');
    getline(stream_line3, name_of_r, ';');
    // Read and elaborate the following lines taken from the input file
    size_t num_row = count(filename_input);
    double* w = new double[num_row];     // allocating memory for two arrays of double dynamically
    double* r = new double[num_row];
    unsigned int i = 0;
    while (getline(ifs, line)) {
        stringstream stream_line(line);
        string wi;
        string ri;
        getline(stream_line, wi, ';');
        double wi_double = stod(wi);
        getline(stream_line, ri, ';');
        double ri_double = stod(ri); 
        if (i>num_row-1){
            cerr<<"index out of range";
            delete [] w;
            delete [] r;
            return 1;
        }
        w[i] =  wi_double;
        r[i] = ri_double;
        i++;
    }
    fout << name_of_w << " = ";
    write_in_outfile(fout, w, num_row);
    fout << name_of_r << " = ";;
    write_in_outfile(fout, r, num_row);
    double rate_of_return = find_rate(w,r,num_row);
    fout << "Rate of return of the portfolio: " <<fixed << setprecision(4) << rate_of_return << endl;
    double V = find_V(w,r,value_of_S_in_double,num_row);
    fout << "V: " << fixed << setprecision(2) << V << endl;
    delete [] w;
    delete [] r;
    ifs.close();
    fout.close();
    return 0;
}

