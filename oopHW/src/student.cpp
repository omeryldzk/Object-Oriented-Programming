#include <iostream> 
#include <stdio.h>
#include <string>
#include "student.h"


using namespace std;


Student::Student(string name, double GPA, double GRE, double TOEFL)
{   
    this->name = name;
    this->GPA = GPA;
    this->GRE = GRE;
    this->TOEFL = TOEFL;
    this->numOfapp = 0;
    cout<<this->name<<" logged in to the system."<<endl;
}
Student::Student(const Student& x){
        name = x.name;
        GPA = x.GPA;
        GRE = x.GRE;
        TOEFL = x.TOEFL;
        numOfapp = x.numOfapp;
        cout<<this->name<<" logged in to the system."<<endl;

}
Student::~Student()
{   
    cout<<this->getName()<<" logged out of the system with "<<this->getNumOfapp()
    <<" application(s)."<<endl;
}

string Student::getName() const
    {
        return this->name;
    }

void Student::set_name(string name)
    {
        this->name = name;
    }
double Student::getGPA() const
    {
        return this->GPA;
    }

double Student::getGRE() const
    {
        return this->GRE;
    }


double Student::getTOEFL() const
    {
        return this->TOEFL;
    }

int Student::getNumOfapp() const
    {
        return this->numOfapp;
    }


void Student::numOfappincrement() const
    {
        this->numOfapp++;
    }


