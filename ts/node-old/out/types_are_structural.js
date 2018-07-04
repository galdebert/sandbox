"use strict";
var point2D = { x: 0, y: 10 };
var point3D = { x: 0, y: 10, z: 20 };
function iTakePoint2D(point) { }
iTakePoint2D(point2D); // exact match okay iTakePoint2D(point3D); // extra information okay
iTakePoint2D({ x: 0 }); // Error: missing information `y
//# sourceMappingURL=types_are_structural.js.map