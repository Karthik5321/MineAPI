Hi, This is a personal Project. In this i write personal library for posix and windwos system calls.
  * Each Operation like File Operation, Socket , Window.
  * Each Operation has Five method Crate(it also contains open), Read, write, close, movepointer.
  * All operation treated as API
  * Each opearation Contains Folder LIKE FILEAPI
  * Each folder contains {API_Name}API.hpp, {API_Name}EnumHandler.hpp, {API_NAME}Handler.hpp
  * {API_Name}API.hpp inherit API.hpp and implement method for EnumHandler and Handler  initate.
  * {API_Name}EnumHandler.hpp inherit EnumHandler.hpp, this file contains all enum for all operation and global EnumHandler must be has entry for all enum. only very few enum must declare in {API_Name}EnumHandler.hpp. {API_Name}EnumHandler.hpp main use to implement method for get correct Enum for state
  * {API_NAME}Handler.hpp inherit Handler.hpp it implement all method in operation. in constructor initate {PlateformName}{API_NAME}Handler.hpp class and use this in its method.
  * {PlateformName}{API_NAME} folder contains all Plateform oriented {PlateformName}{API_Name}EnumHandler.hpp, {PlateformName}{API_NAME}Handler.hpp for same use case.
  * Top of the Heirachy contains APIHandler.hpp it return correct operation api. get{API_Name}API()
Project Structure:
  MineAPI:
    |
    |- APIHandler.hpp
    |- API.hpp
    |- EnumHandler.hpp
    |- Handler.hpp
    |- {API_Name(uppercase)}API(Floder)
      |
      |-{API_Name}API.hpp
      |-{API_Name}EnumHandler.hpp
      |-{API_Name}Handler.hpp
      |-{PlateformName}{API_NAME}
        |
        | -{PlateformName}{API_NAME}Handler.hpp
        | -{PlateformName}{API_NAME}EnumHandler.hpp
this project contains Cmake project.
build generated in the build folder.
bin/plateform{bitness}/executable file.

File Structure
APIHandler.hpp

class APIHandler
  get{API_NAME}API() return correct file API like FileAPI()

API.hpp

class API
  get{API_Name}EnumHandler() it does not implement here it will implement in API. {API_Name}it return EnumHandler class
  get{API_Name}Handler() it not implement here it will implement in {API_Name}API. it returns EnumHandler class
class EnumHandler
  it contains method
  {OperationName}Enum it also implement in {API_Name}EnumHandler.hpp
class Handler
  it contains all operation like create. it also implement in {API_name}handler.

{API_NAME}API

{API_NAME}HANDLE
  it constructor initate initate Plateform specfic Handler.
  it inherit Handler class I not fully implemented it use PlateformHandle method
        
