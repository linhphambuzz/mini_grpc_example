## C++ compiler flag setup 
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++14

## gRPC compiler setup
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`


PROTOS_PATH = ./   # .proto file path
PROTOS_SRC = ./proto-src # all generated file by grpc compiler goes here
vpath %.proto $(PROTOS_PATH) #tell make where to find .proto

all: linh_client linh_server 
# client : all grpc dependent and client src file 
# pb.h goes first because grpc.pb.h will look for it
linh_client: $(PROTOS_SRC)/linh.pb.o $(PROTOS_SRC)/linh.grpc.pb.o  linh_client.o 
	$(CXX) $^ $(LDFLAGS) -o $@
#server: all grpc dependent and server src file 
linh_server: $(PROTOS_SRC)/linh.pb.o $(PROTOS_SRC)/linh.grpc.pb.o  linh_server.o 
	$(CXX) $^ $(LDFLAGS) -o $@
# protos generated files 
protos: $(PROTOS_SRC)/linh.grpc.pb.cc $(PROTOS_SRC)/linh.pb.cc


# compile protos
.PRECIOUS: %.pb.cc
$(PROTOS_SRC)/%.pb.cc: linh.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=$(PROTOS_SRC) $<


.PRECIOUS: %.grpc.pb.cc
$(PROTOS_SRC)/%.grpc.pb.cc: linh.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=$(PROTOS_SRC) --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<


clean:
	rm -f *.o *.pb.cc *.pb.h linh_client linh_server