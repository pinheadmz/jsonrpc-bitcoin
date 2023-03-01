# jsonrpc-bitcoin

Simple package for testing JSON-RPC 2.0 using
[libjson-rpc-cpp](https://github.com/cinemast/libjson-rpc-cpp)

Start bitcoind:
```
bitcoind -regtest -rpcuser=u -rpcpassword=p -debug=rpc
```

Run:
```
make && ./sampleclient
```
## Examples

Expected output:
```
jsonrpc 1.0
206
51d201ed667bc9814b17310f940806c3e40118b58b4d3bd331a8aadca6ba0edb

jsonrpc 2.0
206
51d201ed667bc9814b17310f940806c3e40118b58b4d3bd331a8aadca6ba0edb
```

Unhappy output :-(
```
jsonrpc 1.0
206
51d201ed667bc9814b17310f940806c3e40118b58b4d3bd331a8aadca6ba0edb

jsonrpc 2.0
Exception -32001 : The response is invalid:  {
        "error" : null,
        "id" : 1,
        "result" : 206
}
Exception -32001 : The response is invalid:  {
        "error" : null,
        "id" : 1,
        "result" : "51d201ed667bc9814b17310f940806c3e40118b58b4d3bd331a8aadca6ba0edb"
}
```