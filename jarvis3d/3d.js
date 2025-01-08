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

        this.show_edges  = true;
        this.show_points = true;
    }

    select_next_triangle() {
        const n = this.triangles.length;
        if (n == 0) {
            return;
        }

        this.selected_triangle = (this.selected_triangle + 1) % n;
    }

    select_prev_triangle() {
        const n = this.triangles.length;
        if (n == 0) {
            return;
        }

        if (this.selected_triangle > 0) {
            this.selected_triangle -= 1;
        } else {
            this.selected_triangle = n - 1;
        }
    }

    set_show_edges(flag) {
        this.show_edges = flag;
    }

    set_show_points(flag) {
        this.show_points = flag;
    }

    force_refresh() {
        this.svg.innerHTML = '';
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
            if (this.show_points) {
                el.style.display = "";
            } else {
                el.style.display = "none";
            }
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
                el.style.display = "";
            } else {
                el.setAttributeNS(null, "fill", "none");
                if (this.show_edges) {
                    el.style.display = "";
                } else {
                    el.style.display = "none";
                }
            }
        }
    }

    set_data(vertices, triangles) {
        this.vertices = vertices;
        this.triangles = triangles;
        this.selected_triangle = 0;
        this.force_refresh();
    }
}

function random_points(n, rand) {
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
    const dx2 = 0.5 * dx;
    const dy2 = 0.5 * dy;
    const dz2 = 0.5 * dz;

    for (let i=0; i < vertices.length; i++) {
        let p = vertices[i];
        p.x = (p.x - min.x - dx2) * scale;
        p.y = (p.y - min.y - dy2) * scale;
        p.z = (p.z - min.z - dz2) * scale;
    }

    return vertices;
}


if (typeof document !== 'undefined') {
    const a = 1103515245;
    const c = 12345;
    const m = 1 << 31;
    const rand_max = 1 << 30;

    let seed = 42;
    function rand_int() {
        seed = (a*seed + c) % m;
        return seed;
    }

    function rand() {
        return rand_int() / rand_max - 0.5;
    }

    document.addEventListener('DOMContentLoaded', function() {
        let svg = document.getElementById("display");
        let n_points_elem = document.getElementById("n_points");
        let view = new View(document, svg);

        function generate() {
            const n_points = n_points_elem.value;
            if (n_points <= 0) {
                return;
            }

            let vertices  = random_points(n_points, rand);
            let vertices2 = center_and_scale(vertices);
            let triangles = giftwrapping3d(vertices2);
            view.set_data(vertices, triangles);
            view.update();
        }

        document.getElementById("calculate").addEventListener("click", function() {
            generate();
        }, false);

        const angle_x_step = Math.PI / 180;
        const angle_y_step = Math.PI / 180;
        svg.addEventListener("mousemove", function(ev) {
            if (ev.buttons != 0) {
                const dx = ev.clientX - last_x;
                const dy = ev.clientY - last_y;
                console.log(dx, dy)
                view.anglex +=  dx * angle_x_step;
                view.angley += -dy * angle_y_step;
            }
            last_x = ev.clientX;
            last_y = ev.clientY;
            view.update();
        }, false);

        document.addEventListener("keypress", function(ev) {
            if (ev.key == "n") {
                view.select_next_triangle();
                view.update();
                ev.preventDefault();
            }
            if (ev.key == "p") {
                view.select_prev_triangle();
                view.update();
                ev.preventDefault();
            }
        }, false);

        document.getElementById("show_edges").addEventListener("click", function(ev) {
            view.set_show_edges(ev.target.checked);
            view.update();
        });

        document.getElementById("show_points").addEventListener("click", function(ev) {
            view.set_show_points(ev.target.checked);
            view.update();
        });

        generate();
    }, false);
}
