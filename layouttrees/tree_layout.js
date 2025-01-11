function tree_layout(root, x_space, y_space) {
    let levels = new Map();
    let stack = [[root, 0]];

    // 1. group nodes by their depths
    let max_depth = 0;
    while (stack.length > 0) {
        let [node, depth] = stack.shift();
        max_depth = Math.max(max_depth, depth);

        let nodes = levels.get(depth);
        if (nodes === undefined) {
            nodes = new Array();
            levels.set(depth, nodes);
        }

        nodes.push(node);

        for (let i=0; i < node.children.length; i++) {
            const child = node.children[i];
            stack.push([child, depth + 1]);
        }
    }

    // 2. assign y coordinates to levels
    let y = 0;
    for (let depth=0; depth <= max_depth; depth++) {
        let nodes = levels.get(depth);
        for (let node of nodes) {
            node.x = 0;
            node.y = y;
        }

        y += max_height(nodes);
        y += y_space;
    }

    // 3. do layout
    for (let depth=max_depth; depth >= 0; depth--) {
        let nodes = levels.get(depth);
        for (let i=0; i < nodes.length; i++) {
            let node = nodes[i];
            if (i > 0) {
                // make this node adjacent to the previous one
                const prev =  nodes[i-1]
                node.x = prev.x + prev.width + x_space;
            }

            if (node.is_leaf()) {
                continue;
            }

            // 1. desired x position
            const x  = average_x(node.children);
            const dx = x - node.cx();

            if (dx > 0) {
                // 2. move this node to the right
                node.x += dx;
            } else if (dx < 0) {
                // 3. move children of this node and neighbours to the right
                for (let j=i; j < nodes.length; j++) {
                    const node = nodes[j];
                    for (let child of node.children) {
                        translate_tree(child, -dx);
                    }
                }
            }
        }
    }
}

function average_x(nodes) {
    let sum = 0;
    for (const node of nodes) {
        sum += node.cx();
    }

    return sum / nodes.length;
}

function max_height(nodes) {
    let max = 0.0;
    for (const node of nodes) {
        max = Math.max(max, node.height);
    }

    return max;
}

function translate_tree(root, dx) {
    root.x += dx
    for (node of root.children) {
        translate_tree(node, dx);
    }
}
