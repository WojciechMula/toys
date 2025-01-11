const svgns = "http://www.w3.org/2000/svg";

class View {
    constructor(doc, svg) {
        this.doc = doc;
        this.svg = svg;
    }

    refresh(root) {
        this.svg.innerHTML = '';

        let stack = [root];
        while (stack.length > 0) {
            const node = stack.pop();
            const node_cx = node.cx();
            const node_cy = node.cy();
            for (const child of node.children) {
                let el = this.doc.createElementNS(svgns, "line");
                el.setAttributeNS(null, "stroke", "black");
                el.setAttributeNS(null, "stroke-width", "2.0px");
                el.setAttributeNS(null, "x1", node_cx);
                el.setAttributeNS(null, "y1", node_cy);
                el.setAttributeNS(null, "x2", child.cx());
                el.setAttributeNS(null, "y2", child.cy());
                this.svg.appendChild(el);

                stack.push(child);
            }
        }

        stack = [root];
        while (stack.length > 0) {
            const node = stack.pop();
            for (const child of node.children) {
                stack.push(child);
            }

            {
                let el = this.doc.createElementNS(svgns, "rect");
                el.setAttributeNS(null, "stroke", "black");
                el.setAttributeNS(null, "stroke-width", "0.5px");
                el.setAttributeNS(null, "fill", "#dee");
                el.setAttributeNS(null, "x", node.x);
                el.setAttributeNS(null, "y", node.y);
                el.setAttributeNS(null, "width", node.width);
                el.setAttributeNS(null, "height", node.height);
                this.svg.appendChild(el);
            }

            {
                let el = this.doc.createElementNS(svgns, "text");
                el.innerHTML = node.label;
                this.svg.appendChild(el);

                const bbox = el.getBBox();
                const cx = node.cx();
                const cy = node.cy();
                el.setAttributeNS(null, "x", cx - bbox.x - bbox.width / 2.0);
                el.setAttributeNS(null, "y", cy - bbox.y - bbox.height / 2.0);
            }
        }
    }
}

const letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                 'q', 'r', 's', 't', 'u', 'w', 'v', 'x',
                 'y', 'z'];

const widths = [20, 40];


function generate_random_tree(count, rand) {
    let arr = new Array();
    for (let i=0; i < count; i++) {
        const label = letters[i % letters.length];
        const width = widths[rand() % widths.length];

        let node = new Node(label);
        node.width = width;
        arr.push(node);
    }

    while (arr.length > 1) {
        const idx  = pick_random(arr, rand);
        const root = arr.splice(idx, 1)[0];

        const idx2 = pick_random(arr, rand);
        const node = arr.splice(idx2, 1)[0];

        root.add_child(node);

        arr.push(root);
    }

    return arr[0];
}

function pick_random(array, rand) {
    const n = array.length;
    if (n == 0) {
        return undefined;
    }

    idx = rand() % n;

    return idx;
}

if (typeof document !== 'undefined') {
    const a = 1013904223;
    const c = 1664525;
    const m = 1 << 31;

    let seed = 42;
    function rand_int() {
        seed = (a*seed + c) % m;
        return seed >> 16;
    }

    document.addEventListener('DOMContentLoaded', function() {
        let svg = document.getElementById("display");
        let node_count = document.getElementById("node_count");
        let view = new View(document, svg);

        function generate() {
            const tree = generate_random_tree(node_count.value, rand_int);

            const x_space = 5;
            const y_space = 30;
            tree_layout(tree, x_space, y_space);

            view.refresh(tree);
        }

        document.getElementById("generate").addEventListener("click", function() {
            generate();
        }, false);

        generate()
    }, false);
}
