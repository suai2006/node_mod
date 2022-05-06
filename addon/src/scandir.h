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

    void ScanDir(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        WIN32_FIND_DATA f;  
        std::string value = *String::Utf8Value(isolate, args[0]);
        value += "/*";
        LPSTR fullPath = const_cast<char *>(value.c_str());
        
        HANDLE h = FindFirstFile(fullPath , &f);
        Local<Object> dir = Object::New(isolate);
        
        if(h != INVALID_HANDLE_VALUE) {
          do {
            if (f.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
              dir->Set(String::NewFromUtf8(isolate, f.cFileName), String::NewFromUtf8(isolate, "isDir"));
            }else{
              Local<Value> res = args[0];
              dir->Set(String::NewFromUtf8(isolate, f.cFileName), String::NewFromUtf8(isolate, "isFile"));
            }
          } 
          while(FindNextFile(h, &f) != 0);
        }
        else {
          dir->Set(String::NewFromUtf8(isolate, "error"), String::NewFromUtf8(isolate, "Error opening directory"));
        }
        args.GetReturnValue().Set(dir);
    }
}