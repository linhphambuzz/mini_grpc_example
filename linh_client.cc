#include <grpcpp/grpcpp.h>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include "proto-src/linh.grpc.pb.h"

using linh::DataComm; 
using grpc::Channel;

class DataCommClient{
protected: 
    std::unique_ptr<DataComm::Stub> stub; 
public:
    DataCommClient(std::shared_ptr<Channel> channel): stub(DataComm::NewStub(channel)){};
    ~DataCommClient();
};


int main() {
    // Your code here
    return 0;
}