const path = require('path');
const Calc = require('node-gyp-build')(__dirname);

const LOOP_COUNT = 1000000;

let beginTime = new Date();
for(var i = 0; i < LOOP_COUNT; i++) {
    Calc.Add(12, 34);
}
let endTime = new Date();
console.log (`${LOOP_COUNT} Calc.Add using ${(endTime.getTime() - beginTime.getTime())}ms`);
