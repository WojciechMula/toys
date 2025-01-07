class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

function transform(vertices, anglex, angley) {
    let transformed = new Array(vertices.length);

    const cax = Math.cos(anglex);
    const sax = Math.sin(anglex);
    const cay = Math.cos(angley);
    const say = Math.sin(angley);

    for (let i in vertices) {
        const p = vertices[i];

        const x1 = p.x * cax - p.z * sax;
        const z1 = p.x * sax + p.z * cax;
        const y1 = p.y;

        const x = x1;
        const y = y1 * cay - z1 * say;
        const z = y1 * say + z1 * cay;
        transformed[i] = [x, y, z];
    }
    return transformed;
}
 
const svgns = "http://www.w3.org/2000/svg";

class View {
    constructor(doc, svg) {
        this.doc = doc;
        this.svg = svg;
        this.anglex = 0.0;
        this.angley = 0.0;
        this.selected_triangle = 0;
        this.vertices = [];
        this.triangles = [];

        const width  = svg.width.baseVal.value;
        const height = svg.height.baseVal.value;

        this.dx = width / 2;
        this.dy = height / 2;
        this.scale = Math.max(width, height) / 3;
        this.width = width;
        this.height = height;
    }
    
    world2view_x(x) {
        return x * this.scale + this.dx;
    }
    
    world2view_y(y) {
        return y * this.scale + this.dy;
    }

    update() {
        let t = transform(this.vertices, this.anglex, this.angley);
        for (let i in t) {
            const id = "p" + i;

            let el = this.svg.getElementById(id);
            if (el === null) {
                el = this.doc.createElementNS(svgns, "circle");
		        el.setAttributeNS(null, "id", id);
        		el.setAttributeNS(null, "fill", "black");
        		el.setAttributeNS(null, "r", 2);
                this.svg.appendChild(el);
            }

            let [x, y, _] = t[i];
            let xs = this.world2view_x(x);
            let ys = this.world2view_y(y);
            el.setAttributeNS(null, "cx", xs);
            el.setAttributeNS(null, "cy", ys);
        }

        for (let i=0; i < this.triangles.length; i++) {
            const id = "tri" + i;
            let el = this.svg.getElementById(id);
            if (el === null) {
                el = this.doc.createElementNS(svgns, "polygon");
                el.setAttributeNS(null, "id", id);
                el.setAttributeNS(null, "stroke", "blue");
                el.setAttributeNS(null, "fill", "none");
                this.svg.appendChild(el);
            }

            let d = "";
            for (const index of this.triangles[i]) {
                let [x, y, _] = t[index];
                let xs = this.world2view_x(x);
                let ys = this.world2view_y(y);

                d += " " + xs + "," + ys;
            }
            el.setAttributeNS(null, "points", d);
            if (i == this.selected_triangle) {
                el.setAttributeNS(null, "fill", "green");
                el.setAttributeNS(null, "opacity", 0.7);
            } else {
                el.setAttributeNS(null, "fill", "none");
            }
        }
    }

    set_data(vertices, triangles) {
        this.vertices = vertices;
        this.triangles = triangles;
        this.svg.innerHTML = '';
    }
}


function random_points(n, seed) {
    const a = 1103515245;
    const c = 12345;
    const m = 1 << 31;
    const rand_max = 1 << 30;

    let v = seed;
    function rand_int() {
        v = (a*v + c) % m;
        return v;
    }

    function rand() {
        return rand_int();
    }

    let res = new Array(n);
    for (let i=0; i < n; i++) {
        const x = rand();
        const y = rand();
        const z = rand();

        res[i] = new Point(x, y, z);
    }

    return res;
}

function center_and_scale(vertices) {
    let p = vertices[0];
    let min = new Point(p.x, p.y, p.z);
    let max = new Point(p.x, p.y, p.z);

    for (let i=1; i < vertices.length; i++) {
        const p = vertices[i];
        min.x = Math.min(p.x, min.x);
        min.y = Math.min(p.y, min.y);
        min.z = Math.min(p.z, min.z);

        max.x = Math.max(p.x, max.x);
        max.y = Math.max(p.y, max.y);
        max.z = Math.max(p.z, max.z);
    }

    const dx = max.x - min.x;
    const dy = max.y - min.y;
    const dz = max.z - min.z;

    const dim2 = Math.max(dx, Math.max(dy, dz)) / 2.0;
    const scale = 1.0 / dim2;
    const dx2 = dx / 2.0;
    const dy2 = dy / 2.0;
    const dz2 = dz / 2.0;

    for (let i=0; i < vertices.length; i++) {
        let p = vertices[i];
        p.x = (p.x - dx2) * scale;
        p.y = (p.y - dy2) * scale;
        p.z = (p.z - dz2) * scale;
    }

    return vertices;
}


if (typeof document !== 'undefined') {
    let l = console.log;

    document.addEventListener('DOMContentLoaded', function() {
        let svg = document.getElementById("display");
        let n_points_elem = document.getElementById("n_points");
        let view = new View(document, svg);

        function generate() {
            const n_points = n_points_elem.value;
            if (n_points <= 0) {
                return;
            }

            const seed = 42;
            let vertices  = random_points(n_points, seed);
            let vertices2 = center_and_scale(vertices);
            let triangles = giftwrapping3d(vertices);
            view.set_data(vertices, triangles);
            view.update();
        }

        document.getElementById("calculate").addEventListener("click", function() {
            generate();
        }, false);

        let rotate = false;
        svg.addEventListener("click", function() {
            rotate = !rotate;
        });

        svg.addEventListener("mousemove", function(ev) {
            if (rotate) {
                view.anglex = (ev.x / view.width) * 2 * Math.PI;
                view.angley = (ev.y / view.height) * 2 * Math.PI;
            }
            view.update();
        }, false);

        document.addEventListener("keypress", function(ev) {
            if (ev.key == "n") {
                view.selected_triangle += 1;
                view.update();
                ev.preventDefault();
            }
            if (ev.key == "p") {
                view.selected_triangle -= 1;
                view.update();
                ev.preventDefault();
            }
        }, false);

        generate();
    }, false);
}
