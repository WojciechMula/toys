class Word {
    constructor(val) {
        this.bits = []
        for (let i=0; i < 16; i++) {
            let bit = val % 2;
            val = Math.trunc(val / 2);

            this.bits.push(bit);
        }

        this.lsb_index = 0;
        this.bit_count = 16;
    }

    clone() {
        let c = Object.assign(Object.create(Object.getPrototypeOf(this)), this);
        c.bits = [...this.bits]
        return c
    }

    is_bit_active(pos) {
        if (pos < this.lsb_index) {
            return false;
        }

        if (pos >= this.lsb_index + this.bit_count) {
            return false;
        }

        return true;
    }

    number() {
        let res = 0;
        for (let i=0; i < this.bit_count; i++) {
            res += this.bits[i + this.lsb_index] << i;
        }

        return res;
    }

    shift_left_inplace() {
        this.bits.pop();
        this.bits.unshift(0);
    }

    ge(B) {
        let borrow_in = 0;
        let borrow_out = 0;

        for (let i=0; i < 16; i++) {
            let a = this.bits[i];
            let b = B.bits[i];

            borrow_out = 0;
            if (borrow_in + b > a) {
                borrow_out = 1;
            }

            borrow_in = borrow_out;
        }

        return borrow_out == 0
    }

    sub(B) {
        let res = this.clone()
        let borrow_in = 0;
        let borrow_out = 0;

        for (let i=0; i < 16; i++) {
            let a = this.bits[i];
            let b = B.bits[i];

            borrow_out = 0;
            if (borrow_in + b > a) {
                a += 2
                borrow_out = 1;
            }

            res.bits[i] = a - (b + borrow_in);
            borrow_in = borrow_out;
        }

        return res;
    }

    set_bit(pos) {
        this.bits[pos] = 1;
    }
}

class State {
    constructor(comment, relation, a, b, c) {
        this.comment  = comment
        this.relation = relation
        this.a = a.clone();
        this.b = b.clone();
        this.c = c.clone();
    }
}

function long_divide(a, b) {
    let states = [];

    for (let i=0; i < 8; i++) {
        b.shift_left_inplace();
    }
    b.lsb_index = 8;
    b.bit_count = 8;
    for (let i=15; i >= 0; i--) {
        if (b.bits[i] == 1) {
            break;
        }

        b.bit_count -= 1;
    }

    a.lsb_index = b.lsb_index;
    a.bit_count = 8;

    let quotient = new Word(0);
    quotient.lsb_index = 16;
    quotient.bit_count = 0;

    states.push(new State("initial state", "", a, b, quotient));

    for (let i=7; i >= 0; i--) {
        a.shift_left_inplace();

        let av = a.number();
        let bv = b.number();
        let relation = "";
        if (av >= bv) {
            relation = av + " ≥ " + bv + " ⇒ " + "1"
        } else {
            relation = av + " < " + bv + " ⇒ " + "0"
        }

        states.push(new State("include bit #" + i + " of dividend", relation, a, b, quotient));

        if (a.ge(b)) {
            a = a.sub(b);
            states.push(new State("subtracting divisor", relation, a, b, quotient));

            quotient.set_bit(i + 8);
            quotient.lsb_index -= 1;
            quotient.bit_count += 1;
            states.push(new State("set bit #" + i + " of quotient", relation, a, b, quotient));
        } else {
            quotient.lsb_index -= 1;
            quotient.bit_count += 1;
            states.push(new State("reset bit #" + i + " of quotient", relation, a, b, quotient));
        }
    }

    states.push(new State("dividend contains the remainder", "", a, b, quotient))

    return states;
}

class WordView {
    constructor(doc, name) {
        this.bits = []
        for (let i=0; i < 16; i++) {
            let id = name + "_" + i;
            this.bits.push(doc.getElementById(id));
        }

        this.number = doc.getElementById(name);
    }

    unset() {
        for (let i=0; i < 16; i++) {
            let cell = this.bits[i];
            if (cell) {
                cell.innerText = "";
                cell.classList.remove("active");
                cell.classList.add("inactive");
            }
        }

        this.number.innerText = "";
    }

    set(word) {
        for (let i=0; i < 16; i++) {
            let cell = this.bits[i];
            if (cell) {
                cell.innerText = word.bits[i];
                if (word.is_bit_active(i)) {
                    cell.classList.add("active");
                    cell.classList.remove("inactive");
                } else {
                    cell.classList.remove("active");
                    cell.classList.add("inactive");
                }
            }
        }

        this.number.innerText = word.number();
    }
}

class View {
    constructor(doc) {
        this.states   = [];
        this.state_id = 0;
        this.error    = "";
        this.dividend = new WordView(doc, "dividend");
        this.divisor  = new WordView(doc, "divisor");
        this.quotient = new WordView(doc, "quotient");

        this.start_button  = doc.getElementById("start");
        this.prev_button   = doc.getElementById("prev");
        this.next_button   = doc.getElementById("next");
        this.status_line   = doc.getElementById("status");
        this.relation_line = doc.getElementById("relation");
    }

    update() {
        let len = this.states.length;
        if (len > 0) {
            let state = this.states[this.state_id];

            this.dividend.set(state.a);
            this.divisor.set(state.b);
            this.quotient.set(state.c);

            this.prev_button.disabled = this.state_id == 0;
            this.next_button.disabled = this.state_id >= len - 1;
            this.status_line.innerText = state.comment;
            this.relation_line.innerText = state.relation;
        } else {
            this.dividend.unset();
            this.divisor.unset();
            this.quotient.unset();

            this.prev_button.disabled = true;
            this.next_button.disabled = true;
            this.status_line.innerText = this.error;
            this.relation_line.innerText = "";
        }
    }

    start() {
        this.state_id = 0;
        this.update();
    }

    prev() {
        if (this.state_id > 0) {
            this.state_id -= 1;
            this.update();
        }
    }

    next() {
        let len = this.states.length - 1;
        if (this.state_id < len) {
            this.state_id += 1;
            this.update();
        }
    }

    set_states(states) {
        this.states = states;
        this.state_id = 0;
        this.error = "";
        this.update();
    }

    set_error(msg) {
        this.states = [];
        this.error = msg;
        this.update();
    }
}

document.addEventListener('DOMContentLoaded', function() {
    let view = new View(document);
    let input_dividend = document.getElementById("input_dividend");
    let input_divisor = document.getElementById("input_divisor");

    function start() {
        input_dividend.classList.remove("error");
        input_divisor.classList.remove("error");

        let dividend = parseInt(input_dividend.value);
        if (isNaN(dividend)) {
            view.set_error("wrong dividend");
            input_dividend.classList.add("error");
            return;
        }

        if (dividend < 0 || dividend > 255) {
            view.set_error("dividend must be in range [0, 255]");
            input_dividend.classList.add("error");
            return;
        }

        let divisor = parseInt(input_divisor.value);
        if (isNaN(divisor)) {
            view.set_error("wrong divisor");
            input_divisor.classList.add("error");
            return;
        }

        if (divisor < 1 || divisor > 255) {
            view.set_error("divisor must be in range [1, 255]");
            input_divisor.classList.add("error");
            return;
        }

        let states = long_divide(new Word(dividend), new Word(divisor));
        view.set_states(states);

        view.start();
    }

    document.getElementById("start").addEventListener("click", function() {
        start();
    });

    document.getElementById("prev").addEventListener("click", function() {
        view.prev();
    });

    document.getElementById("next").addEventListener("click", function() {
        view.next();
    });

    start();
}, false);
