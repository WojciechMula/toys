// Jarvis algorithm for convex hulls
function giftwrapping2d(vertices) {
    let ch = new Array();

    const first_idx = find_miny_minx(vertices);
    ch.push(first_idx);

    const xn = vertices[first_idx].x;
    const yn = vertices[first_idx].y;
    const P = new Point(xn - 100.0, yn);

    function side(A, B, C) {
        let dx1 = B.x - A.x
        let dy1 = B.y - A.y

        let dx2 = C.x - A.x
        let dy2 = C.y - A.y

        return (dx1*dy2 - dx2*dy1);
    }

    while (true) {
        const n = ch.length;
        const A_idx = ch[n - 1];
        const A = vertices[A_idx];
        let B_idx = null;
        let B = null;
        if (n - 2 < 0) {
            B = P;
        } else {
            B_idx = ch[n - 2];
            B = vertices[B_idx];
        }

        for (let index=0; index < vertices.length; index++) {
            if (index == A_idx || index == B_idx) {
                continue;
            }

            const P = vertices[index];
            if (side(A, B, P) > 0) {
                B_idx = index;
                B = P;
            }
        }

        if (B_idx == ch[0]) {
            break;
        }

        ch.push(B_idx);
    }

    return ch;
}

function find_miny_minx(vertices) {
    let x = null;
    let y = null;
    let index = null
    for (let i=0; i < vertices.length; i++) {
        const p = vertices[i];
        if (index === null) {
            index = i;
            x = p.x;
            y = p.y;
        } else {
            if ((p.y > y) || (p.y == y && p.x > x)) {
                index = i;
                x = p.x;
                y = p.y;
            }
        }
    }

    return index;
}
