class Node {
    constructor(label) {
        this.label  = label;
        this.width  = 30;
        this.height = 30;
        this.children = new Array();

        // left-upper corner of object
        this.x = undefined;
        this.y = undefined;
    }

    cx() {
        return this.x + this.width / 2.0;
    }

    cy() {
        return this.y + this.height / 2.0;
    }

    add_child(node) {
        this.children.push(node);
    }

    is_leaf() {
        return this.children.length == 0;
    }

    first_child() {
        return this.children[0];
    }

    last_child() {
        return this.children[this.children.length - 1];
    }
}
