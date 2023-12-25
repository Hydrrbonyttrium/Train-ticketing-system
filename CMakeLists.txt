cmake_minimum_required(VERSION 3.26)
project(TrainTicketing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TrainTicketing
        DataEntry.cpp
        DataEntry.h
        Graph.cpp
        Graph.h
        LinkList.h
        LinkList.tpp
        LinkQueue.cpp
        LinkQueue.h
        Login.cpp
        Login.h
        main.cpp
        Public1.h
        Reality.h
        Search.cpp
        Search.h
        Sqlist.h
        SqList.tpp
        Ticket.cpp
        Ticket.h
        Tree.h
        Tree.tpp)
