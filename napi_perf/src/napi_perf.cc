#include <node_api.h>

namespace demo {
    
int Add(int a, int b) {
    return a + b;
}

napi_value Add_Wrap(napi_env env, napi_callback_info args) {
  napi_status status;
  napi_value sum;
  
  size_t argc = 2;
  napi_value argv[2];

  status = napi_get_cb_info(env, args, &argc, argv, NULL, NULL);

  int value1, value2;

  napi_get_value_int32(env, argv[0], &value1);
  napi_get_value_int32(env, argv[1], &value2);
  
  napi_create_int32(env, Add(value1, value2), &sum);

  return sum;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Add_Wrap, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "Add", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo 
