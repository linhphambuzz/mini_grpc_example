#include <grpcpp/grpcpp.h>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include "proto-src/linh.grpc.pb.h"

using linh::DataComm; 
using grpc::Channel;
using std::string; 
using grpc::Status;
using grpc::ClientContext; 
using linh::FileReq;
using linh::FileRes;  


class DataCommClient{
protected: 
    std::unique_ptr<DataComm::Stub> stub; 
public:
    DataCommClient(std::shared_ptr<Channel> channel): stub(DataComm::NewStub(channel)){};
    ~DataCommClient(){};
    void SendFile(){
        ClientContext ctx; 
        FileReq req;
        FileRes res; 

        Status s= this->stub->SendFile(&ctx,req,&res);
        if (s.ok()){
            std::cout << "respond from the server: " << res.respond() <<  std::endl;
        }

    };

};


int main() {
    string server="0.0.0.0:50051"; 
    std::shared_ptr<Channel> channel=grpc::CreateChannel(server,grpc::InsecureChannelCredentials());
    /*client obj., constructor with channel linked to server*/
    DataCommClient linh_client(channel);
    linh_client.SendFile();

    return 0;
}