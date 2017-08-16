function log(s: string) {
    document.body.innerHTML += s;
    document.body.innerHTML += "<br>";
}

interface ClockInterface {
    tick();
}

class DigitalClock implements ClockInterface {
    constructor(h: number, m: number) { log("DigitalClock constructor"); }
    tick() {}
}

class AnalogClock implements ClockInterface {
    constructor(h: number, m: number) { log("AnalogClock constructor"); }
    tick() {}
}

class SomethingElse {
}

// --------------------------------------------------------
function clockFactory_UsingAny(klass: any, hour: number, minute: number): ClockInterface {
    return new klass(hour, minute);
}

log("---------------------------------");
log("clockFactory_UsingAny(klass: any, hour: number, minute: number)");
let digital1 = clockFactory_UsingAny(DigitalClock, 12, 17);
let analog1 = clockFactory_UsingAny(AnalogClock, 7, 32);
try {
    let err1 = clockFactory_UsingAny(new SomethingElse, 7, 32);  // no compile error, runtime error, booh !
}
catch (e) {
    log("exception catched: " + (<Error>e).message);
}
// --------------------------------------------------------
interface ClockConstructor {
    new (hour: number, minute: number): ClockInterface;
}
function clockFactory_UsingClockConstructor(ctor: ClockConstructor, hour: number, minute: number): ClockInterface {
    return new ctor(hour, minute);
}
log("---------------------------------");
log("call createClock(ctor: ClockConstructor, hour: number, minute: number)");
let digital2 = clockFactory_UsingClockConstructor(DigitalClock, 12, 17);
let analog2 = clockFactory_UsingClockConstructor(AnalogClock, 7, 32);
//let err2 = clockFactory_UsingClockConstructor(new SomethingElse, 7, 32); // compile error, yeah !


