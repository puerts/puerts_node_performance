#include <node.h>
#ifdef WITH_V8_FAST_CALL
#include <v8-fast-api-calls.h>
#endif

int Add(int a, int b) {
    return a + b;
}

static void Add_Wrap(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  int a = info[0]->Int32Value(context).ToChecked();
  int b = info[1]->Int32Value(context).ToChecked();

  info.GetReturnValue().Set(Add(a, b));
}

NODE_MODULE_INIT(/* exports, module, context */) {
  v8::Isolate* isolate = context->GetIsolate();

  exports->Set(context,
               v8::String::NewFromUtf8(isolate, "Add").ToLocalChecked(),
               v8::FunctionTemplate::New(isolate, Add_Wrap)
                  ->GetFunction(context).ToLocalChecked()).FromJust();

#ifdef WITH_V8_FAST_CALL
  static v8::CFunction FastAdd(v8::CFunction::Make(Add));
  exports->Set(
    context, v8::String::NewFromUtf8Literal(isolate, "FAdd"),
    v8::FunctionTemplate::New(
            isolate, Add_Wrap, v8::Local<v8::Value>(),
        v8::Local<v8::Signature>(), 0, v8::ConstructorBehavior::kThrow,
                              v8::SideEffectType::kHasSideEffect, &FastAdd)
        ->GetFunction(context).ToLocalChecked()).FromJust();
#endif
} 
