class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

function transform_points(vertices, anglex, angley) {
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

function transform_triangle_normals(triangles, anglex, angley) {
    let normals = new Array(triangles.length);

    const cax = Math.cos(anglex);
    const sax = Math.sin(anglex);
    const cay = Math.cos(angley);
    const say = Math.sin(angley);

    for (let i in triangles) {
        const p = triangles[i][NORMAL];

        const x1 = p.x * cax - p.z * sax;
        const z1 = p.x * sax + p.z * cax;
        const y1 = p.y;

        const x = x1;
        const y = y1 * cay - z1 * say;
        const z = y1 * say + z1 * cay;
        normals[i] = new Point(x, y, z);
    }

    return normals;
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

        this.show_edges     = true;
        this.show_points    = true;
        this.show_triangles = true;

        this.light = normalize(new Point(-0.75, 0.5, -1));
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
        this.force_refresh();
    }

    set_show_points(flag) {
        this.show_points = flag;
        this.force_refresh();
    }

    set_show_triangles(flag) {
        this.show_triangles = flag;
        this.force_refresh();
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
        let t = transform_points(this.vertices, this.anglex, this.angley);
        for (let i=0; i < t.length; i++) {
            const [x, y, z] = t[i];
            const xs = this.world2view_x(x);
            const ys = this.world2view_y(y);
            t[i] = [xs, ys, z];
        }

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

            const [xs, ys, _] = t[i];
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
            const triangle = this.triangles[i];
            for (let j=0; j < 3; j++) {
                const index = triangle[j];
                const [xs, ys, _] = t[index];

                d += " " + xs + "," + ys;
            }

            el.setAttributeNS(null, "points", d);
            if (i == this.selected_triangle) {
                el.setAttributeNS(null, "fill", "red");
                el.setAttributeNS(null, "opacity", 1.0);
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

        if (this.show_triangles) {
            this.do_show_triangles(t);
        }
    }

    do_show_triangles(t) {
        let normals = transform_triangle_normals(this.triangles, this.anglex, this.angley);
        let n = this.triangles.length;
        let triangles = new Array(n);
        for (let i=0; i < n; i++) {
            const triangle = this.triangles[i];
            const p0 = t[triangle[VERTEX0]];
            const p1 = t[triangle[VERTEX1]];
            const p2 = t[triangle[VERTEX2]];
            const z  = Math.min(p0[2], Math.min(p1[2], p2[2]));
            triangles[i] = [z, p0, p1, p2, normals[i]];
        }

        // depth sort
        function cmp(t0, t1) {
            const z0 = t0[0];
            const z1 = t1[0];

            if (z0 > z1) {
                return +1;
            }
            if (z0 < z1) {
                return -1;
            }
            return 0;
        }

        triangles.sort(cmp);

        const face_r = 0;
        const face_g = 128;
        const face_b = 0;

        const light_r = 255;
        const light_g = 255;
        const light_b = 255;

        function color_component(face, light, t) {
            let c = face + light * t;
            if (c > 255) {
                return 255;
            }
            if (c < 0) {
                return 0;
            }
            return c;
        }

        function color(t) {
            const r = color_component(face_r, light_r, t);
            const g = color_component(face_g, light_g, t);
            const b = color_component(face_b, light_b, t);

            return 'rgb(' + r + ',' + g + ',' + b + ')';
        }
        for (let i=0; i < n; i++) {
            const id = "ft" + i;
            let el = this.svg.getElementById(id);
            if (el === null) {
                el = this.doc.createElementNS(svgns, "polygon");
                el.setAttributeNS(null, "id", id);
                el.setAttributeNS(null, "stroke", "none");
                this.svg.appendChild(el);
            }

            const [_, p0, p1, p2, N] = triangles[i];
            const d = p0[0] + "," + p0[1] + "," + p1[0] + "," + p1[1] + "," + p2[0] + "," + p2[1];

            el.setAttributeNS(null, "points", d);

            const t = Math.pow(Math.abs(dot(this.light, N)), 5);
            const col = color(t);

            el.setAttributeNS(null, "fill", col);
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

function count_vertices(triangles) {
    let s = new Set();
    for (const triangle of triangles) {
        s.add(triangle[VERTEX0]);
        s.add(triangle[VERTEX1]);
        s.add(triangle[VERTEX2]);
    }

    return s.size;
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
        let triangle_count_elem = document.getElementById("triangle_count");
        let vertices_count_elem = document.getElementById("vertices_count");
        let view = new View(document, svg);

        function generate() {
            const n_points = n_points_elem.value;
            if (n_points <= 0) {
                return;
            }

            let vertices  = random_points(n_points, rand);
            let vertices2 = center_and_scale(vertices);
            let triangles = giftwrapping3d(vertices2);

            triangle_count_elem.innerText = triangles.length;
            vertices_count_elem.innerText = count_vertices(triangles);

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
                view.anglex +=  dx * angle_x_step;
                view.angley += -dy * angle_y_step;
                view.update();
            }
            last_x = ev.clientX;
            last_y = ev.clientY;
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

        document.getElementById("show_triangles").addEventListener("click", function(ev) {
            view.set_show_triangles(ev.target.checked);
            view.update();
        });

        generate();
    }, false);
}
