#include <iostream>

#include "stubclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

void call(std::function<void()> func) {
  try {
    func();
  } catch (JsonRpcException &e) {
    cerr << e.what();
  }
}

int main() {
  HttpClient httpclient("http://u:p@localhost:18443");
  StubClient client1(httpclient, JSONRPC_CLIENT_V1); // json-rpc 1.0
  StubClient client2(httpclient, JSONRPC_CLIENT_V2); // json-rpc 2.0

  std::map<std::string, StubClient*> clients = {{"jsonrpc 1.0", &client1}, {"jsonrpc 2.0", &client2}};

  auto iter = clients.begin();
  while (iter != clients.end()) {
    cout << endl << iter->first << endl;
    call([&](){cout << iter->second->getblockcount() << endl;});
    call([&](){cout << iter->second->getblockhash(1) << endl;});

    iter++;
  }
}
