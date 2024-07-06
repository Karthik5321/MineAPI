
#ifndef __HANDLER__
        #include "Handler.hpp"
#endif

#ifndef __POSIXFILEHANDLER__
    #define __POSIXFILEHANDLER__ 0
   
#include<unistd.h>
class PosixFileHandler : public Handler
{
        public:
        int fileHandle;
        OPEN_STATUS Open(char* filename,int creation_type, int access_type)
        {
            int creationType = 0;
         
            if(creation_type == (int)OPEN_TYPE::CREATE)
            {
                creationType = O_CREAT;
            }
         
            int accessType = O_RDONLY;
            if(access_type == (int)OPERATION_TYPE::READ)
            {
                accessType = O_RDONLY;
            }
            else if(access_type == (int)OPERATION_TYPE::WRITE)
            {
                accessType = O_WRONLY;
            }
            else if(access_type == (int)OPERATION_TYPE::BOTH)
            {
                accessType = O_RDWR;
            }
            fileHandle = CreateFileA((LPCSTR)filename,access_type|creation_type);
            if(fileHandle == -1)
            {
                
                return OPEN_STATUS::FAILURE;
            }
            return OPEN_STATUS::SUCCESS;
        }
        READ_STATUS Read(char* buffer,int numberOfReadBytes)
        {
            
            int status = read(fileHandle,buffer,numberOfReadBytes);
            
            if(status == -1)
            {
                
                return READ_STATUS::FAILURE;
            }
            if(status == 0)
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
            int status = write(fileHandle,buffer,numberOfReadBytes);
            if(status == -1)
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
            int postion = SEEK_SET;
            if(Position ==  POSITION_TYPE::START)
            {
                postion = SEEK_SET;
            }
            else if(Position ==  POSITION_TYPE::CURRENT)
            {
                postion = SEEK_CUR;
            }
            else if(Position ==  POSITION_TYPE::END)
            {
                postion = SEEK_END;
            }
            int status = lseek(fileHandle,distance,0,postion);
            if(status == -1)
            {
                return POINTER_OPERATION_STATUS::FAILURE;
            }
            return POINTER_OPERATION_STATUS::SUCCESS;
        }
};
#endif