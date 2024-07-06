#ifndef __ENUMHANDLER__
    #define __ENUMHANDLER__ 1

#include <cstddef>


enum class OPEN_STATUS
    {
        SUCCESS,
        FAILURE
    };
enum class  READ_STATUS
    {
        SUCCESS,
        ENDOFFILE,
        FAILURE
    };
enum class  WRITE_STATUS
    {
        SUCCESS,
        FAILURE
    };
enum class CLOSE_STATUS
    {
        SUCCESS,
        FAILURE
    };

enum class DELETE_STATUS
    {
        SUCCESS,
        FAILURE
    };
enum class OPEN_TYPE
    {
        OPEN,
        CREATE,
        BOTH
    };
enum class OPERATION_TYPE
{
    READ,
    WRITE,
    BOTH
};
enum class POSITION_TYPE
{
    START,
    CURRENT,
    END
};
enum class POINTER_OPERATION_STATUS
{
    SUCCESS,
    FAILURE
};
class EnumHandler
{
    public:
   
    virtual  OPEN_STATUS getCreateEnum(int code){
        return OPEN_STATUS::SUCCESS;
    }
    virtual READ_STATUS getReadEnum(int code){
        return READ_STATUS::SUCCESS;
    }
    virtual WRITE_STATUS getWriteEnum(int code){
        return WRITE_STATUS::SUCCESS;
    }
    virtual DELETE_STATUS getDeleteEnum(int code){
        return DELETE_STATUS::SUCCESS;
    }
    virtual CLOSE_STATUS getCloseEnum(int code)
    {
        return CLOSE_STATUS::SUCCESS;
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
#endif