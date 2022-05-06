#include "header.h"
#include "fopen.h"
#include "scandir.h"
#include "writetofile.h"

namespace fs {
    using namespace node;
    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Number;

    void Initialize(Local<Object> exports, Local<Object> module) {
        NODE_SET_METHOD(exports, "scanDir", ScanDir);
        NODE_SET_METHOD(exports, "writeToFile", WriteToFile);
        NODE_SET_METHOD(exports, "fopen", fopen);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}