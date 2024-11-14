#include <string>

#include <grpcpp/grpcpp.h>
#include "proto-src/linh.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using linh::DataComm;

/* DataCommImpl is the derived class of Service
This is where all the service methods are implemented */

class DataCommImpl final : public DataComm::Service {

public: 
    Status SendFile(ServerContext* context, const ::linh::FileReq* request, ::linh::FileRes* response) override{
        std::string file_resp="this is the file respond"; 
        response->set_respond(file_resp);
        return Status::OK; 
    }

};

int main() {
    // Your code here
    return 0;
}