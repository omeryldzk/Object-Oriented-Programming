#include <string>
#include <iostream>

class ALU
{
public:
    ALU(int);  // constructor w/ numPercores parameter 
    // add, subtract and multiply methods.
    int add(int,int) const;
    int substract(int,int) const;
    int multiply(int,int) const;
    
private:
    int numPerCores;

};


class CPU
{
public:
    CPU(int); // constructor w/ numPercores parameter CPU will set this variable on ALU object
    ~CPU(); //destructor to delete alu object
    // executes the operation on alu and returns the result.
    int execute(const std::string) const;
    const ALU* get_ALU() const {return alu; }
private:
    const ALU *alu;

};



class CUDA
{
public: 
    CUDA(int); // constructor w/ numcores parameter 
    std::string trainModel() const;
    std::string render() const;
private:
    int numCores;

};






class GPU
{
public:
    GPU(int);// constructor w/ numcores parameter GPU will set this variable on CUDA object
    ~GPU();//destructor to delete cuda object
    // executes the operation on cuda and returns the result.
    std::string execute(const std::string)const; 
    const CUDA* get_CUDA() const {return cuda; }
private:
    const CUDA *cuda;

};




class Computer   
{
    friend void operator+(Computer&,CPU&);//opretaor overload function for cpu
    friend void operator+(Computer&,GPU&);//opretaor overload function for gpu
public:
    Computer();
    /* execute operation on the relevant part on the computer */
    void execute(const std::string) const;
    /* Getters will return attached value and setters will set attachedcpu and attachedgpu */
    CPU* getCpu() {return attachedCPU;}
    GPU* getGpu() {return attachedGPU;}
    void setCpu(CPU& cpu) {attachedCPU = &cpu;}
    void setGpu(GPU& gpu) {attachedGPU = &gpu;} 
private:
    /* The computer never modifies the internal states of the attached CPU and GPU
    .Because attached CPU and GPU first set to null and when any CPU and GPU attached 
    adding new entities to a computer is not possible
    */
    CPU *attachedCPU;
    GPU *attachedGPU;
};



