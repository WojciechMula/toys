class Word {
    constructor(val) {
        this.bits = []
        for (let i=0; i < 8; i++) {
            let bit = val % 2;
            val = Math.trunc(val / 2);

            this.bits.push(bit);
        }

        this.lsb_index = 0;
        this.bit_count = 8;
        this.highlighted = new Map();
    }

    clone() {
        let c = Object.assign(Object.create(Object.getPrototypeOf(this)), this);
        c.bits = [...this.bits];
        c.highlighted = new Map(this.highlighted);
        return c
    }

    highlight_active(val) {
        this.clear_highlight()
        for (let i=0; i < 8; i++) {
            if (this.is_bit_active(i)) {
                this.highlighted.set(i, val);
            }
        }
    }

    highlight_single(pos, val) {
        this.clear_highlight()
        this.highlighted.set(pos, val);
    }

    clear_highlight() {
        this.highlighted.clear();
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
        for (let i=0; i < 8; i++) {
            res += this.bits[i] << i;
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

        for (let i=0; i < 8; i++) {
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

        for (let i=0; i < 8; i++) {
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

    get_bit(pos) {
        return this.bits[pos];
    }

    set_bit(pos) {
        this.bits[pos] = 1;
    }
}

class State {
    constructor(comment, relation, dividend, divisor, reminder, quotient) {
        this.comment  = comment
        this.relation = relation
        this.dividend = dividend.clone();
        this.divisor  = divisor.clone();
        this.reminder = reminder.clone();
        this.quotient = quotient.clone();
    }
}

function long_divide(dividend, divisor) {
    let states = [];

    divisor.lsb_index = 0;
    divisor.bit_count = 8;
    for (let i=7; i >= 0; i--) {
        if (divisor.bits[i] == 1) {
            break;
        }

        divisor.bit_count -= 1;
    }

    let dv = divisor.number();

    let reminder = new Word(0);
    reminder.lsb_index = 0;
    reminder.bit_count = 0;

    let quotient = new Word(0);
    quotient.lsb_index = 8;
    quotient.bit_count = 0;

    function capture_state(caption, relation) {
        if (relation == undefined) {
            relation = "";
        }

        states.push(new State(caption, relation, dividend, divisor, reminder, quotient));

        dividend.clear_highlight();
        divisor.clear_highlight();
        reminder.clear_highlight();
        quotient.clear_highlight();
    }

    capture_state("initial state");

    for (let i=7; i >= 0; i--) {
        reminder.shift_left_inplace();
        reminder.lsb_index = 1;

        if (i < 7) {
            capture_state("make room for the next bit #" + i + " of dividend");
        }

        bit = dividend.get_bit(i)
        if (bit) {
            dividend.highlight_single(i, "copy1");
            reminder.highlight_single(0, "copy1");
            reminder.set_bit(0);
        } else {
            dividend.highlight_single(i, "copy0");
            reminder.highlight_single(0, "copy0");
        }

        reminder.lsb_index = 0;
        reminder.bit_count += 1;
        capture_state("copy bit #" + i + " of dividend", "")

        let rv = reminder.number();
        let relation = "";
        if (rv >= dv) {
            relation = rv + " ≥ " + dv + " ⇒ " + "1"
        } else {
            relation = rv + " < " + dv + " ⇒ " + "0"
        }

        divisor.highlight_active("compare");
        reminder.highlight_active("compare");
        capture_state("compare divisor and reminder", relation);

        if (reminder.ge(divisor)) {
            reminder = reminder.sub(divisor);
            capture_state("subtracting divisor", relation);

            quotient.set_bit(i);
            quotient.lsb_index -= 1;
            quotient.bit_count += 1;

            quotient.highlight_single(i, "copy1");
            capture_state("set bit #" + i + " of quotient", relation);
        } else {
            quotient.lsb_index -= 1;
            quotient.bit_count += 1;
            quotient.highlight_single(i, "copy0");
            capture_state("reset bit #" + i + " of quotient", relation);
        }
    }

    capture_state("finished");

    return states;
}

class WordView {
    constructor(doc, name) {
        this.bits = []
        for (let i=0; i < 8; i++) {
            let id = name + "_" + i;
            this.bits.push(doc.getElementById(id));
        }

        this.number = doc.getElementById(name);
    }

    unset() {
        for (let i=0; i < 8; i++) {
            let cell = this.bits[i];
            if (cell) {
                cell.innerText = "";
                cell.classList.remove("active");
                cell.classList.remove("highlighted");
                cell.classList.add("inactive");
            }
        }

        this.number.innerText = "";
    }

    set(word) {
        for (let i=0; i < 8; i++) {
            let cell = this.bits[i];
            if (cell) {
                cell.innerText = word.bits[i];
                cell.classList.remove("active", "inactive", "copy0", "copy1", "compare");
                if (word.is_bit_active(i)) {
                    cell.classList.add("active");
                    let cls = word.highlighted.get(i);
                    if (cls != undefined) {
                        cell.classList.add(cls);
                    }
                } else {
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
        this.reminder = new WordView(doc, "reminder");
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

            this.dividend.set(state.dividend);
            this.divisor.set(state.divisor);
            this.reminder.set(state.reminder);
            this.quotient.set(state.quotient);

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
