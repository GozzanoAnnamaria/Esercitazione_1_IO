// Exercise 2

#include <iostream>
#include <fstream>
#include <cmath>
#include <numbers>
#include <iomanip>

//  Function that maps points in the interval
double change(double N)
{
    // Old interval
    double old_max = 5.0;
    double old_min = 1.0;

    // New interval
    double new_max = 2;
    double new_min = -1;

    double new_data;

    new_data = ((N-old_min)/(old_max-old_min))*(new_max-new_min) + new_min;
    return new_data;
}

int main()
{
    double data = 0;
    double new_data = 0;
    double SumData = 0;
    double mean = 0;
    int i = 0;

    // Open input file 
    std::ifstream file_input;
    file_input.open("data.txt");
    
    if (file_input.fail())
    {
        std::cerr<<"File not found"<<std::endl;
        return 1;
    }

    // Open output file 
    std::ofstream outputfile("result.txt");
    outputfile<<"# N Mean"<<std::endl;

    // Change the interval, compute the mean and print the results
    while(file_input>>data){
        i++;

        double new_data = change(data);
        SumData += new_data;
        mean = SumData/i;
        
        outputfile<<i<<" "<<std::setprecision(16)<<std::scientific<<mean<<std::endl;
    }
    
    // Close all files
    outputfile.close(); 
    file_input.close();

    return 0;
}