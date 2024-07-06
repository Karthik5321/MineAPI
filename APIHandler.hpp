#ifndef __API__
  #include"API.hpp"
#endif
#ifndef __FILEAPI__
    #include "FileAPI.hpp"
#endif
#include<stdlib.h>
#ifndef __APIHANDLER__
    #define __APIHANDLER__ 1
#endif
class APIHandler
{
    public:
    static API* getFileAPI()
    {
        return new FileAPI;
    }
};