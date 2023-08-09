cd napi_perf
npm install .
cd ..

## Download v8-fast-api-calls.h that matches your local nodejs version before you uncomment
#cd puerts_fastcall_perf
#npm install .
#cd ..

cd puerts_perf
npm install .
cd ..

cd puerts_v8_perf
npm install .
cd ..

cd v8api_perf
npm install .
cd ..

cd v8pp_pref
npm install .
cd ..



cd napi_perf
echo "--------------napi_perf-----------------"
node perf.js
echo "----------------------------------------"
cd ..

## Download v8-fast-api-calls.h that matches your local nodejs version before you uncomment
#cd puerts_fastcall_perf
#echo "--------------puerts_fastcall_perf-----------------"
#node --turbo-fast-api-calls perf.js
#echo "----------------------------------------"
#cd ..

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
