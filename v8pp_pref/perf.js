var v8pp_pref = require('./build/Release/v8pp_pref');

const Calc = v8pp_pref.Calc;


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
