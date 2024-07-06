#ifndef __HANDLER__
    #include"Handler.hpp"
#endif
#ifndef __WINDOWFILEHANDLER__
    #include "WindowFileHandler.hpp"
#endif
#ifndef __FILEHANDLER__
    #define __FILEHANDLER__ 0

class FileHandler : public Handler
{
        public:
        Handler* fileHandler = nullptr;
        FileHandler()
        {
            #if defined(_WIN32)
                fileHandler = new WindowFileHandler;
            #endif
            #else
                fileHandler = new PosixFileHandler;
            #endif
        }
        OPEN_STATUS Open(char* filename,int creation_type, int access_type)
        {
            return fileHandler->Open(filename,creation_type,access_type);
        }
        READ_STATUS Read(char* buffer,int numberOfReadBytes)
        {
            return fileHandler->Read(buffer,numberOfReadBytes);
        }
        READ_STATUS Read(char* buffer)
        {
            return fileHandler->Read(buffer);
        }
        WRITE_STATUS Write(char* buffer,int numberOfReadBytes)
        {
            return fileHandler->Write(buffer,numberOfReadBytes);
        }
        WRITE_STATUS Write(char* buffer)
        {
            return fileHandler->Write(buffer);
        }
        CLOSE_STATUS Close()
        {
            return fileHandler->Close();
        }
        POINTER_OPERATION_STATUS MovePointer(int byteNumber,POSITION_TYPE Position)
        {
            return fileHandler->MovePointer(byteNumber,Position);
        }
};
#endif