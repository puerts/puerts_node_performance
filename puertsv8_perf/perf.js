//cp v8-fast-api-calls.h ~/.cache/node-gyp/18.14.1/include/node
//node --turbo-fast-api-calls perf.js
//"defines": [ "BUILDING_PES_EXTENSION", "PES_EXTENSION_WITH_V8_API", "WITH_V8_FAST_CALL"],
const puerts = require('puerts');

let puerts_perf = puerts.load('build/Release/puerts_perf.node');
const Calc = puerts_perf.Calc;


const LOOP_COUNT = 1000000;

let beginTime = new Date();
for(var i = 0; i < LOOP_COUNT; i++) {
    Calc.Add(12, 34);
}
let endTime = new Date();
console.log (`${LOOP_COUNT} Calc.Add using ${(endTime.getTime() - beginTime.getTime())}ms`);

let calc = new Calc();

beginTime = new Date();
for(var i = 0; i < LOOP_COUNT; i++) {
    calc.M_Add(12, 34);
}
endTime = new Date();
console.log (`${LOOP_COUNT} calc.M_Add using ${(endTime.getTime() - beginTime.getTime())}ms`);

