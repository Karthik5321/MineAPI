#ifndef __ENUMHANDLER__
    #include"EnumHandler.hpp"
#endif
#ifndef __HANDLER__
    #include "Handler.hpp"
#endif
#ifndef __API__
    #define __API__ 1
#endif
class API
{
    public:
    virtual EnumHandler* getFileEnumHandler(){
        return NULL;
    }
    virtual Handler* getFileHandler(){
        return NULL;
    }
};