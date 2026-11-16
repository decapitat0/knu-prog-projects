#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;

const double a = -0.9;
const double b = 0.9;

// Computes S(x) as the sum up to the first term with |term| <= eps.
// Precondition: x in [a; b], eps > 0.
// Returns the value of the sum.
double s(double argument, double eps){
    double term = argument*argument/2;
    double sum = term;
    int n = 1;
    while(term > eps || term < -eps){
        term *= argument*n/(n+2);
        ++n;
        sum += term;
    }
    return sum;
}

// Reads x and checks if the function can be calculated for the given value.
// Throws invalid_argument if x is not a real number.
// Throws out_of_range if x is out of the range [a; b].
double readArgument(){
    double argument;
    string line;
    char extra;
    cout<<"Enter a real x in range [-0.9; 0.9]: ";
    getline(cin, line);
    istringstream in(line);
    if(!(in >> argument) || (in >> extra))
        throw invalid_argument("x is not a real number");
    if(argument< a || argument > b)
        throw out_of_range(" is out of the range");
    return argument;
}

// Reads eps and checks if the function can be calculated for the given value.
// Throws invalid_argument if eps is not a real number.
// Throws out_of_range if eps <= 0.
double readEps(){
    double eps;
    string line;
    char extra;
    cout<<"Enter a positive value of eps [eps > 0]: ";
    getline(cin, line);
    istringstream in(line);
    if(!(in >> eps) || (in >> extra))
        throw invalid_argument("eps is not a real number");
    if(eps <= 0)
        throw out_of_range("eps value must be positive");
    return eps;
}

// Shows the author and the task, reads input values x and eps,
// then prints the result or an error message.
int main(){
    cout<<"Author: Taras Malash ITK-11"<<endl;
    cout<<"This program calculates the sum of a power series at a given point ";
    cout<<"x in [-0.9; 0.9] with accuracy eps"<<endl;
    cout<<"Variant 172"<<endl;

    try{
        double argument = readArgument();
        double eps = readEps();
        cout<<"***** do calculations ... ";
        double result = s(argument, eps);
        cout<<"done"<<endl;
        cout<<uppercase<<scientific;
        cout<<setprecision(7)<<"for x = "<<argument<<endl;
        cout<<setprecision(9)<<"for eps = "<<eps<<endl;
        cout<<fixed<<setprecision(8)<<"result = "<<result<<endl;
    }
    catch (const exception& e){
        cout<<"***** error\n"<<e.what()<<endl;
    }
    return 0;
}