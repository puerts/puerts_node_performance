# puerts_node_performance

## Tests

* [napi_perf](./napi_perf): Implemented using napi

* [puerts_fastcall_perf](./puerts_fastcall_perf): Implemented using puerts binding, and enabling PES_EXTENSION_WITH_V8_API and WITH_V8_FAST_CALL macros. Please note, to run this example, you need to manually download the v8-fast-api-calls.h for the corresponding local nodejs version and place it in the node-gyp header file directory.

* [puerts_perf](./puerts_perf): Implemented using puerts binding

* [puerts_v8_perf](./puerts_v8_perf): Implemented using puerts binding, and enabling PES_EXTENSION_WITH_V8_API macro.

* [v8api_perf](./v8api_perf): Implemented directly using v8 api

* [v8pp_pref](./v8pp_pref): Implemented using v8pp binding

## How to manually download v8-fast-api-calls.h

First, check the node.js version, download the corresponding source code package, unzip it and copy v8-fast-api-calls.h to the node-gyp header file directory. Generally speaking, the node-gyp header file directory on Linux, macOS, and Windows are as follows:

* Linux: ~/.cache/node-gyp/<node_version>/include/node, please replace <node_version> with the locally installed nodejs version, the same below.

* macOS: ~/Library/Caches/node-gyp/<node_version>/include/node/

* Windows: %userprofile%\AppData\Local\node-gyp\Cache<node_version>\include\node

## Test Results

### Environments

#### Windows

os: Windows 10 22H2
node version: v16.16.0
cpu: 12th Gen Intel(R) Core(TM) i7-1260P   2.10 GHz
memory: 32.0 GB

#### Ubuntu

os: Ubuntu 22.04.2 LTS (run on wsl)
node version: v18.14.1
cpu: 12th Gen Intel(R) Core(TM) i7-1260P   2.10 GHz
memory: 32.0 GB

#### macOS@intel

os: macOS Monterey 12.6.8
node version: v20.5.0
cpu:  10 core 10th-generation Intel Core i9 3.6G
memory: 32.0 GB

#### macOS@m1

os: macOS Ventura 13.5
node version: v18.9.0
cpu:  Apple M1 Pro
memory: 32.0 GB

### Test Results

#### 1000000 static function calls

|     | [napi_perf](./napi_perf)  | [puerts_fastcall_perf](./puerts_fastcall_perf) | [puerts_perf](./puerts_perf) | [puerts_v8_perf](./puerts_v8_perf) | [v8api_perf](./v8api_perf) | [v8pp_pref](./v8pp_pref)|
|  ----  | ----  | ----  | ----  | ----  | ----  | ----  |
| Windows  | 25ms | 4ms | 24ms | 16ms | 13ms | 30ms |
| Ubuntu  | 20ms | 4ms | 28ms | 12ms | 11ms | 21ms |
| macOS@intel | 27ms | 5ms | 25ms | 21ms | 15ms | 30ms |
| macOS@m1  | 39ms | 5ms | 29ms | 19ms | 15ms | 64ms |

### 1000000 member method calls

|     | [puerts_fastcall_perf](./puerts_fastcall_perf) | [puerts_perf](./puerts_perf) | [puerts_v8_perf](./puerts_v8_perf) | [v8pp_pref](./v8pp_pref)|
|  ----  | ----  | ----  | ----  | ----  | 
| Windows  | 11ms | 29ms | 19ms | 138ms |
| Ubuntu  | 10ms | 39ms | 20ms | 98ms |
| macOS@intel  | 10ms | 37ms | 25ms | 88ms |
| macOS@m1  | 12ms | 31ms | 21ms | 78ms |

