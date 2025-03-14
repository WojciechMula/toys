"use strict";

class Edge {
    constructor(a, b) {
        if (a < b) {
            this.idx0 = a;
            this.idx1 = b;
        } else {
            this.idx0 = b;
            this.idx1 = a;
        }
    }

    hash() {
        return this.idx0 + " " + this.idx1;
    }
}

const VERTEX0 = 0;
const VERTEX1 = 1;
const VERTEX2 = 2;
const NORMAL  = 3;

function giftwrapping3d(vertices) {
    // 1. the first step of 2D convex hull (we project the 3D cloud on the XY plane)
    const ch2d = giftwrapping2d(vertices);

    // 2. send the first edge to 
    let queue = new Array();
    let analysed = new Set();

    function add_edge(idx0, idx1) {
        const e = new Edge(idx0, idx1);
        const h = e.hash();
        if (analysed.has(h)) {
            return;
        }

        queue.push(e);
        analysed.add(h);
    }

    add_edge(ch2d[0], ch2d[1]);

    let triangles = new Array();
    while (queue.length > 0) {
        const e = queue.pop();
        const idx0 = e.idx0;
        const idx1 = e.idx1;
        const p0 = vertices[idx0];
        const p1 = vertices[idx1];

        const old = triangles.length;
        for (let idx=0; idx < vertices.length; idx++) {
            if (idx == idx0 || idx == idx1) {
                continue;
            }

            const p2 = vertices[idx];
            const N  = normal3d(p0, p1, p2);

            if (triangle_side(p0, N, idx0, idx1, idx, vertices)) {
                add_edge(idx0, idx);
                add_edge(idx1, idx);

                triangles.push([idx0, idx1, idx, normalize(N)]);
                break;
            }
        }

        if (triangles.length == old) {
            // no progress
            break;
        }
    }

    return triangles;
}

const err = 1e-6;

function triangle_side(p0, N, idx0, idx1, idx2, vertices) {
    let side = null;
    for (let idx=0; idx < vertices.length; idx++) {
        const p = vertices[idx];

        const dx = p.x - p0.x;
        const dy = p.y - p0.y;
        const dz = p.z - p0.z;

        let v = dx*N.x + dy*N.y + dz*N.z;
        if (Math.abs(v) < err) {
            v = 0;
        }

        if (v > 0) {
            return false;
        }
    }

    return true;
}

function normal3d(A, B, C) {
    const dx1 = B.x - A.x;
    const dy1 = B.y - A.y;
    const dz1 = B.z - A.z;

    const dx2 = C.x - A.x;
    const dy2 = C.y - A.y;
    const dz2 = C.z - A.z;

    const x = dy1*dz2 - dz1*dy2;
    const y = dz1*dx2 - dx1*dz2;
    const z = dx1*dy2 - dy1*dx2;

    return new Point(x, y, z);
}

function normalize(p) {
    const dx2 = p.x * p.x;
    const dy2 = p.y * p.y;
    const dz2 = p.z * p.z;
    const len = Math.sqrt(dx2 + dy2 + dz2);

    return new Point(p.x / len, p.y / len, p.z / len);
}

function dot(p1, p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}
