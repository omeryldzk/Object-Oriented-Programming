#include <iostream> 
#include <stdio.h>
#include "university.h"


using namespace std;


University::University(string uniName,double wGPA,double wGRE,double wTOEFL,double bias){
    this->uniName = uniName;
    this->wGPA = wGPA;
    this->wGRE = wGRE;
    this->wTOEFL = wTOEFL;
    this->bias = bias;
    

}
University::University(string uniName,double wGPA,double wGRE,double wTOEFL,double bias,string cName){
    this->uniName = uniName;
    this->wGPA = wGPA;
    this->wGRE = wGRE;
    this->wTOEFL = wTOEFL;
    this->cName = cName;
    this->bias = bias;
    

}
University::~University(){
    
}

void University::evaluate_student(const Student &s1) {
        double z = (s1.getGPA() * this->getwGPA()) + (s1.getGRE() * this->getwGRE())
         + (s1.getTOEFL() * this->getwTOEFL()) + this->getbias();
         if(z >= 0){
            cout<<s1.getName()<<" is admitted to "<<this->getuniName()<<"."<<endl;
         }
         else
            cout<<s1.getName()<<" is rejected from "<<this->getuniName()<<"."<<endl;
        s1.numOfappincrement();
}

double University::getwGPA() const
    {
        return this->wGPA;
    }
double University::getbias() const
    {
        return this->bias;
    }

double University::getwGRE() const
    {
        return this->wGRE;
    }


double University::getwTOEFL() const
    {
        return this->wTOEFL;
    }
string University::getuniName() const
    {
        return this->uniName;
    }

