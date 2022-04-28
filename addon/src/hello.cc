#include <windows.h>
#include <iostream>
#include <tchar.h> 
#include <stdio.h>
#include <cstring>
#include <strsafe.h>
#include <node.h>
#include <vector>
namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Number;
    using v8::Integer;

    
    void Method(const FunctionCallbackInfo<Value>& args) {
      Isolate* isolate = args.GetIsolate();
      // args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
      Local<Object> obj = Object::New(isolate);
       
      obj->Set(String::NewFromUtf8(isolate, "mean"), Number::New(isolate, 45));
      obj->Set(String::NewFromUtf8(isolate, "median"), Number::New(isolate, 11));
      obj->Set(String::NewFromUtf8(isolate, "standard_deviation"), Number::New(isolate, 20));
      obj->Set(String::NewFromUtf8(isolate, "n"),  Number::New(isolate, 15));

      // Return the object
      args.GetReturnValue().Set(obj);
      
    }

    void Create(const FunctionCallbackInfo<Value>& args) {
        WIN32_FIND_DATA f;
        HANDLE h = FindFirstFile("./*", &f);
        if(h != INVALID_HANDLE_VALUE) {
          do {
            if (f.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
              _tprintf(TEXT("  %s   <DIR>\n"), f.cFileName);
            }else{
              _tprintf(TEXT(" %s \n"), f.cFileName);
            }
          } 
          while(FindNextFile(h, &f) != 0);
          
        }
        else {
          fprintf(stderr, "Error opening directory\n");
        }
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello", Method);
        NODE_SET_METHOD(exports, "create", Create);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo