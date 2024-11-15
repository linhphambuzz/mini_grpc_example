#include <string>
#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "proto-src/linh.grpc.pb.h"

using std::string; 
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using linh::DataComm;



/* DataCommImpl is the derived class of Service
This is where all the service methods are implemented */

class DataCommImpl final : public DataComm::Service {

public: 
    DataCommImpl();
    Status SendFile(ServerContext* context, const ::linh::FileReq* request, ::linh::FileRes* response) override{
        std::string file_resp="this is the file respond"; 
        response->set_respond(file_resp);
        return Status::OK; 
    }

};

void RunServer(string server_address) {
  
  DataCommImpl service;
  ServerBuilder builder;
  
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main() {
    string server="0.0.0.0:50051"; 
    RunServer(server);
    return 0;
}