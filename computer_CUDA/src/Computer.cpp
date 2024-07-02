#include <string>
#include <iostream>
#include "Computer.h"
/* Constructor */
Computer::Computer(){
        std::cout << "Computer is ready"<< std::endl;
        attachedCPU = nullptr;
        attachedGPU = nullptr;
}

void Computer::execute(const std::string operation) const{
    if(operation == "subtract" || operation == "add"  || operation == "multiply" ){
        std::cout << this->attachedCPU->execute(operation) << std::endl;
    }
    else if(operation == "render" || operation == "trainModel" ){
        std::cout << this->attachedGPU->execute(operation) <<std::endl;
}
}
/* Constructor craete an ALU object*/
CPU::CPU(int numPerCores)
{
    this->alu = new const ALU(numPerCores);
    std::cout << "CPU is ready"<< std::endl;
}
CPU::~CPU(){
    delete alu;
}


int CPU::execute(const std::string operation) const{
    int number1,number2;
    std::cout << "Enter two integers"<< std::endl;
    std::cin >> number1 >> number2 ;
    if(operation == "subtract"){
       return this->get_ALU()->substract(number1,number2);
    }
    else if(operation == "add"){
        return this->get_ALU()->add(number1,number2);
    }
    else if(operation == "multiply"){
        return this->get_ALU()->multiply(number1,number2);
    }
    return 0;
}
ALU::ALU(int numPerCores){ //constructor
    this->numPerCores=numPerCores;
    std::cout << "ALU is ready"<< std::endl;
}
int ALU::add(int x1,int x2) const{
    return x1 + x2;
}
int ALU::substract(int x1,int x2) const{
    return x1 - x2;
}
int ALU::multiply(int x1,int x2) const{
    return x1 * x2;
}

/* Constructor craete an CUDA object*/
GPU::GPU(int numCores)
{
    this->cuda = new const CUDA(numCores);
    std::cout << "GPU is ready"<< std::endl;
}

GPU::~GPU(){
    delete cuda;
}

std::string GPU::execute(const std::string operation) const{
    if(operation == "render"){
        return this->get_CUDA()->render();
    }
    else if(operation == "trainModel"){
        return this->get_CUDA()->trainModel();
    }
    return 0;
}
CUDA::CUDA(int numCores){//constructor
    this->numCores = numCores;
    std::cout << "CUDA is ready"<< std::endl;
}
std::string CUDA::render() const{
    return "Video is rendered";
}
std::string CUDA::trainModel() const{
    return "AI Model is trained";
}
/* +oprator check if the cpu entities are already attached and attachs 
computer class object and reference to CPU class object.*/
void operator+(Computer& comp,CPU& cpu) {
    if(!comp.getCpu()){
        comp.setCpu(cpu);
        std::cout << "CPU is attached"<< std::endl;
    }
    else
        std::cout << "There is already a CPU"<< std::endl;
}
/* +oprator check if the cpu entities are already attached and attachs 
computer class object and reference to GPU class object.*/
void operator+(Computer& comp,GPU& gpu)  {
    if(!comp.getGpu()){
        comp.setGpu(gpu);
        std::cout << "GPU is attached"<< std::endl;
    }
    else
        std::cout << "There is already a GPU"<< std::endl;
}
