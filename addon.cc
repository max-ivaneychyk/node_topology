#include <napi.h>
#include <windows.h>

Napi::Value Toggle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong argument - mode - not a number").ThrowAsJavaScriptException();
    return env.Null();
  }

  double mode = info[0].As<Napi::Number>().DoubleValue();
 
  if (mode == 2) {
    SetDisplayConfig(0, NULL,0, NULL,(SDC_APPLY | SDC_TOPOLOGY_CLONE));
  } else {
    SetDisplayConfig(0, NULL,0, NULL,(SDC_APPLY | SDC_TOPOLOGY_EXTEND));
  }

  return Napi::Number::New(env, 0);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "toggle"), Napi::Function::New(env, Toggle));
  return exports;
}

NODE_API_MODULE(addon, Init)
