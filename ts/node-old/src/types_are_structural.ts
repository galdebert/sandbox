
interface Point2D {
    x: number; y: number;
}

interface Point3D {
    x: number; y: number; z: number;
}

var point2D: Point2D = { x: 0, y: 10 }
var point3D: Point3D = { x: 0, y: 10, z: 20 }

function takePoint2D(point: Point2D) { /* do something */ }

takePoint2D(point2D); // exact match
takePoint2D(point3D); // duck typing

//takePoint2D({ x: 0 }); // Error: missing information y