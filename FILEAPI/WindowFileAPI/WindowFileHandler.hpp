
#ifndef __HANDLER__
        #include "Handler.hpp"
#endif

#ifndef __WINDOWFILEHANDLER__
    #define __WINDOWFILEHANDLER__ 0
#include<windows.h>    

class WindowFileHandler : public Handler
{
        public:
        HANDLE fileHandle;
        OPEN_STATUS Open(char* filename,int creation_type, int access_type)
        {
            DWORD creationType = OPEN_ALWAYS;
            if(creation_type == (int)OPEN_TYPE::OPEN)
            {
                creationType = OPEN_ALWAYS;
            }
            else  if(creation_type == (int)OPEN_TYPE::CREATE)
            {
                creationType = CREATE_ALWAYS;
            }
            else  if(creation_type == (int)OPEN_TYPE::BOTH)
            {
                creationType = OPEN_ALWAYS | CREATE_ALWAYS;
            }
            DWORD accessType = GENERIC_READ;
            if(access_type == (int)OPERATION_TYPE::READ)
            {
                accessType = GENERIC_READ;
            }
            else if(access_type == (int)OPERATION_TYPE::WRITE)
            {
                accessType = GENERIC_WRITE;
            }
            else if(access_type == (int)OPERATION_TYPE::BOTH)
            {
                accessType = GENERIC_READ | GENERIC_WRITE;
            }
            fileHandle = CreateFileA((LPCSTR)filename,accessType,0,0,creationType,0,NULL);
            if(fileHandle == INVALID_HANDLE_VALUE)
            {
                
                return OPEN_STATUS::FAILURE;
            }
            return OPEN_STATUS::SUCCESS;
        }
        READ_STATUS Read(char* buffer,int numberOfReadBytes)
        {
            DWORD readBytes = 0;
            BOOL status = ReadFile(fileHandle,buffer,numberOfReadBytes,&readBytes,NULL);
            
            if(!status)
            {
                
                return READ_STATUS::FAILURE;
            }
            if(readBytes == 0)
            {
                return READ_STATUS::ENDOFFILE;
            }
            return READ_STATUS::SUCCESS;
        }
        READ_STATUS Read(char* buffer)
        {
            int size = 0;
            int status = 1;
            char* tempBuffer = new char;
            while(status == 1)
            {
                MovePointer(size,POSITION_TYPE::START);
                READ_STATUS enumStatus = Read(tempBuffer,1);
                if(enumStatus == READ_STATUS::ENDOFFILE)
                {
                    break;
                }
                else if(enumStatus == READ_STATUS::FAILURE)
                {
                    return READ_STATUS::FAILURE;
                }
                buffer[size] = *tempBuffer;
                size++;

            }
            return READ_STATUS::SUCCESS;
        }
        WRITE_STATUS Write(char* buffer,int numberOfReadBytes)
        {
            BOOL status = WriteFile(fileHandle,buffer,numberOfReadBytes,0,0);
            if(!status)
            {
                return WRITE_STATUS::FAILURE;
            }
            return WRITE_STATUS::SUCCESS;
        }
        WRITE_STATUS Write(char* buffer)
        {
            int size = 0;
            while(buffer[size] != '\0')
            {
                size++;
            }
            return Write(buffer,size);
        }
        CLOSE_STATUS Close()
        {
            BOOL status = CloseHandle(fileHandle);
            if(!status)
            {
                return CLOSE_STATUS::FAILURE;
            }
            return CLOSE_STATUS::SUCCESS;
        }
        POINTER_OPERATION_STATUS MovePointer(long distance,POSITION_TYPE Position)
        {
            DWORD postion = FILE_BEGIN;
            if(Position ==  POSITION_TYPE::START)
            {
                postion = FILE_BEGIN;
            }
            else if(Position ==  POSITION_TYPE::CURRENT)
            {
                postion = FILE_CURRENT;
            }
            else if(Position ==  POSITION_TYPE::END)
            {
                postion = FILE_END;
            }
            DWORD status = SetFilePointer(fileHandle,distance,0,postion);
            if(status == INVALID_SET_FILE_POINTER)
            {
                return POINTER_OPERATION_STATUS::FAILURE;
            }
            return POINTER_OPERATION_STATUS::SUCCESS;
        }
};
#endif