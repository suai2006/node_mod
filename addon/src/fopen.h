
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

    void fopen(const FunctionCallbackInfo<Value>& args) {
        
        Isolate* isolate = args.GetIsolate();
        std::string value = *String::Utf8Value(isolate, args[0]);  
        std::ifstream file(value);
        std::string content( (std::istreambuf_iterator<char>(file) ),(std::istreambuf_iterator<char>()) );
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, content.c_str()));
    }
}