#include <cmath>
#include <numbers>
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;

// Calculates the value of the function for the given x.
// Does not check x, so x: x >= -10 and x != 14.
// Takes the argument, returns the value of the function.
double f(double argument){
    return cos(19.0/62)
    - (26*numbers::e/(61* numbers::pi))*(6.0/((argument+13)*(argument-14)))
    + 15*sin(argument-7) + sqrt(argument+10);
}

// Checks if the function can be calculated for the given x.
// Takes x. Throws runtime_error if x out of domain
void checkDomain(double x){
    if(x<-10 || x==14)
        throw runtime_error("undefined");
}

/* Shows the author and the task, reads input value ones,
// then shows the result, "undefined", or "wrong input". */
int main(){
    double input_number;
    cout<<"Author: Taras Malash ITK-11"<<endl;
    cout<<"This program calculates the value of the function by given x.";
    cout<<" Variant 172"<<endl;
    cout<<"Enter an argument x ( x != 14 and x >= -10):"<<endl;
    cin>>input_number;

    if(cin.fail()){
        cout<<"wrong input"<<endl;
        return 0;
    }

    cout<<"***** do calculations ... ";
    bool is_defined = true;
    double result = 0;

    try{
        checkDomain(input_number);
        result = f(input_number);
    }
    catch (const runtime_error&){
        is_defined = false;
    }

    cout<<"done"<<endl;
    cout<<fixed<<setprecision(5)<<"for x = "<<input_number<<endl;

    if(is_defined)
        cout<<setprecision(9)<<"result = "<<result<<endl;
    else
        cout<<"result = undefined"<<endl;

    return 0;
}