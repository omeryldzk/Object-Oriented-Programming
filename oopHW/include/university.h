#include "student.h"
#include <string>

using namespace std;

class University
{
private:
    string uniName {};
    string cName {};
    double wGPA;
    double wGRE;
    double wTOEFL;
    double bias;

public:
    University(string,double,double,double,double);
    University(string,double,double,double,double,string);
    ~University();
    void evaluate_student(const Student &x) ;
    double getbias() const;
    double getwGPA() const;
    double getwGRE() const;
    double getwTOEFL() const;
    string getuniName() const;
};
