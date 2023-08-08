#include <node.h>
#include <v8pp/class.hpp>
#include <v8pp/module.hpp>

using namespace v8;

struct Calc
{
    static int Add(int a, int b) {
        return a + b;
    }
    
    int M_Add(int a, int b) {
        return a + b;
    }
};

void init(Local<Object> exports) {
    Isolate* isolate = Isolate::GetCurrent();
    v8pp::module addon(isolate);
    
    v8pp::class_<Calc> Calc_class(isolate);
    Calc_class.ctor();
    Calc_class.function("Add", &Calc::Add);
    Calc_class.function("M_Add", &Calc::M_Add);

    // set class into the module template
    addon.class_("Calc", Calc_class);
    
    exports->SetPrototype(Isolate::GetCurrent()->GetCurrentContext(), addon.new_instance());
}

NODE_MODULE(addon, init)
