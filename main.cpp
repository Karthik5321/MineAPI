#ifndef __API__
    #include"API.hpp"
#endif
#ifndef __APIHANDLER__
    #include"APIHandler.hpp"
#endif
#include<iostream>
int main()
{
    API* f = APIHandler::getFileAPI();
    EnumHandler* e = f->getFileEnumHandler();
    Handler* h = f->getFileHandler();
    OPEN_STATUS s = e->getCreateEnum(0);
    OPEN_STATUS t = h->Open("file.txt",(int)OPEN_TYPE::OPEN,(int)OPERATION_TYPE::READ);
    if(((int)s & (int)OPEN_STATUS::FAILURE) != 0)
    {
        std::cout<<"Success"<<std::endl;
    }
    if(((int)t & (int)OPEN_STATUS::FAILURE) != 0)
    {
        std::cout<<"Success"<<std::endl;
    }
    char* buffer = new char[11];
    READ_STATUS w = h->Read(buffer);
    std::cout<<buffer<<std::endl;
    h->Close();
    std::cout<<"Completed"<<std::endl;
}