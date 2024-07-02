#include <string>

using namespace std;

class Student
{ 
private:
    string name {};
    double GPA {0};
    double GRE {0};
    double TOEFL {0};
    mutable int numOfapp {0};
public:
    
    Student(string,double,double,double);
    Student(const Student& x);
    ~Student();
    string getName() const;
    double getGPA() const;
    void set_name(string);
    double getGRE() const;
    double getTOEFL() const;
    int getNumOfapp() const;
    void numOfappincrement() const;
    
};
