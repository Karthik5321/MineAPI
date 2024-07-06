#ifndef __ENUMHANDLER__
    #include"EnumHandler.hpp"
#endif

#ifndef __FILEENUMHANDLER__
    #define __FILEENUMHANDLER__ 1
#endif
class FileEnumHandler: public EnumHandler
{
    public:
    
    OPEN_STATUS getCreateEnum(int code){

        return OPEN_STATUS::FAILURE;
    }
    READ_STATUS getReadEnum(int code){
        return READ_STATUS::FAILURE;
    }
    WRITE_STATUS getWriteEnum(int code){
       return WRITE_STATUS::FAILURE;
    }
    DELETE_STATUS getDeleteEnum(int code){
        return DELETE_STATUS::FAILURE;
    }
    CLOSE_STATUS getCloseEnum(int code)
    {
        return CLOSE_STATUS::FAILURE;
    };
     virtual OPEN_TYPE getOpenOperationEnum(int code)
    {
        return OPEN_TYPE::BOTH;
    };
    virtual OPERATION_TYPE getOperationTypeEnum(int code)
    {
        return OPERATION_TYPE::BOTH;
    };
};