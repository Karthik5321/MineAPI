#ifndef __HANDLER__
    #define __HANDLER__ 1
#endif
#ifndef __ENUMHANDLER__
    #include "EnumHandler.hpp"
#endif
class Handler
{
    public:
        virtual OPEN_STATUS Open(char* filename,int creation_type, int access_type)
        {
            return OPEN_STATUS::SUCCESS;
        }
        virtual READ_STATUS Read(char* buffer,int numberOfReadBytes)
        {
            return READ_STATUS::SUCCESS;
        }
        virtual READ_STATUS Read(char* buffer)
        {
            return READ_STATUS::SUCCESS;
        }
        virtual WRITE_STATUS Write(char* buffer,int numberOfReadBytes)
        {
            return WRITE_STATUS::SUCCESS;
        }
        virtual WRITE_STATUS Write(char* buffer)
        {
            return WRITE_STATUS::SUCCESS;
        }
        virtual CLOSE_STATUS Close()
        {
            return CLOSE_STATUS::SUCCESS;
        }
        virtual POINTER_OPERATION_STATUS MovePointer(int byteNumber,POSITION_TYPE Position)
        {
            return POINTER_OPERATION_STATUS::FAILURE;
        }
};