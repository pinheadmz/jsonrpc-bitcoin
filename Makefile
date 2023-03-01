all:
	g++ stubclient.cpp -std=c++11 -ljsoncpp -lcurl -ljsonrpccpp-common -ljsonrpccpp-client -o sampleclient

.PHONY: client
client:
	jsonrpcstub spec.json --cpp-client=StubClient

