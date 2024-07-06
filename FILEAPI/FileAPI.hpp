#ifndef __API__
  #include "API.hpp"
#endif
#ifndef __FILEENUMHANDLER__
    #include "FileEnumHandler.hpp"
#endif
#ifndef __FILEHANDLER__
    #include "FileHandler.hpp"
#endif
#include <stdlib.h>

#ifndef __FILEAPI__
    #define __FILEAPI__ 0

class FileAPI : public API
{
 public:
 Handler* fileHandler = nullptr;
 EnumHandler* fileEnumHandler = nullptr;
 EnumHandler* getFileEnumHandler()
 {
    if(fileEnumHandler == nullptr)
    {
       
        fileEnumHandler = new FileEnumHandler;
        
    }
    return fileEnumHandler;
 
 }
 Handler* getFileHandler()
 {
    if(fileHandler == nullptr)
    {
        fileHandler = new FileHandler;
    }
    return fileHandler;
 }

};

#endif