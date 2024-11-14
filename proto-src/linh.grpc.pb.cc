// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: linh.proto

#include "linh.pb.h"
#include "linh.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace linh {

static const char* DataComm_method_names[] = {
  "/linh.DataComm/SendFile",
};

std::unique_ptr< DataComm::Stub> DataComm::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< DataComm::Stub> stub(new DataComm::Stub(channel));
  return stub;
}

DataComm::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SendFile_(DataComm_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DataComm::Stub::SendFile(::grpc::ClientContext* context, const ::linh::FileReq& request, ::linh::FileRes* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SendFile_, context, request, response);
}

void DataComm::Stub::experimental_async::SendFile(::grpc::ClientContext* context, const ::linh::FileReq* request, ::linh::FileRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendFile_, context, request, response, std::move(f));
}

void DataComm::Stub::experimental_async::SendFile(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::linh::FileRes* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SendFile_, context, request, response, std::move(f));
}

void DataComm::Stub::experimental_async::SendFile(::grpc::ClientContext* context, const ::linh::FileReq* request, ::linh::FileRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendFile_, context, request, response, reactor);
}

void DataComm::Stub::experimental_async::SendFile(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::linh::FileRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SendFile_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::linh::FileRes>* DataComm::Stub::AsyncSendFileRaw(::grpc::ClientContext* context, const ::linh::FileReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::linh::FileRes>::Create(channel_.get(), cq, rpcmethod_SendFile_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::linh::FileRes>* DataComm::Stub::PrepareAsyncSendFileRaw(::grpc::ClientContext* context, const ::linh::FileReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::linh::FileRes>::Create(channel_.get(), cq, rpcmethod_SendFile_, context, request, false);
}

DataComm::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      DataComm_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< DataComm::Service, ::linh::FileReq, ::linh::FileRes>(
          std::mem_fn(&DataComm::Service::SendFile), this)));
}

DataComm::Service::~Service() {
}

::grpc::Status DataComm::Service::SendFile(::grpc::ServerContext* context, const ::linh::FileReq* request, ::linh::FileRes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace linh
