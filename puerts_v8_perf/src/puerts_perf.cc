#include <node.h>
#include "Binding.hpp"

struct Calc
{
    static int Add(int a, int b) {
        return a + b;
    }
    
    int M_Add(int a, int b) {
        return a + b;
    }
};

UsingCppType(Calc);

void Init() {
  puerts::DefineClass<Calc>()
    .Constructor()
    .Method("M_Add", MakeFunction(&Calc::M_Add))
    .Function("Add", MakeFunction(&Calc::Add))
    .Register();
} 

PESAPI_MODULE(puertsv8, Init)
