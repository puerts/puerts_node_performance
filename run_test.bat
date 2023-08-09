cd napi_perf
call npm install .
cd ..

@REM Download v8-fast-api-calls.h that matches your local nodejs version before you uncomment
@REM cd puerts_fastcall_perf
@REM call npm install .
@REM cd ..

cd puerts_perf
call npm install .
cd ..

cd puerts_v8_perf
call npm install .
cd ..

cd v8api_perf
call npm install .
cd ..

cd v8pp_pref
call npm install .
cd ..



cd napi_perf
echo "--------------napi_perf-----------------"
node perf.js
echo "----------------------------------------"
cd ..

@REM  Download v8-fast-api-calls.h that matches your local nodejs version before you uncomment
@REM cd puerts_fastcall_perf
@REM echo "--------------puerts_fastcall_perf-----------------"
@REM node --turbo-fast-api-calls perf.js
@REM echo "----------------------------------------"
@REM cd ..

cd puerts_perf
echo "--------------puerts_perf-----------------"
node perf.js
echo "----------------------------------------"
cd ..

cd puerts_v8_perf
echo "--------------puerts_v8_perf-----------------"
node perf.js
echo "----------------------------------------"
cd ..

cd v8api_perf
echo "--------------v8api_perf-----------------"
node perf.js
echo "----------------------------------------"
cd ..

cd v8pp_pref
echo "--------------v8pp_pref-----------------"
node perf.js
echo "----------------------------------------"
cd ..
