# MINI GRPC EXAMPLE 

A small example of writting client/server code implementing the C++ gRPC API to help me understand the concept of gRPC, and to make it easier for me to debug code in the larger project of the OS class I'm taking.

## Concept 
### Services Definition 
Services are defined in [proto file](./linh.proto). gRPC uses what's called the "protobuf language" for their Interface Definition Language. This file includes: 
- package name : This will then be the `namespace` in all the generated code for implementation.
- name of the service (i.e:`DataComm`). This will be the based-class from which the service implementation class will be derived from. 
- methods to be implemented for the service
- messages definitions and their fields. 



## Compile 

1. Generate grpc-compiled code only 
```
    make protos
```
2. Generate client, server, protos:
```
    make all
```
