class View {
    constructor(doc) {
        this.doc = doc; // this is not nice...

        function element(id) {
            let v = doc.getElementById(id);
            if (v == undefined) {
                throw Error("HTML element #" + id + " not found");
            }

            return v;
        }

        this.input = element("input");
        this.expression = element("expression");
        this.message = element("message");
        this.fun = element("function");
        this.expr_str = '';
        this.values = [
            element("func0"),
            element("func1"),
            element("func2"),
            element("func3"),
            element("func4"),
            element("func5"),
            element("func6"),
            element("func7"),
        ];
        this.rows = [
            element("row0"),
            element("row1"),
            element("row2"),
            element("row3"),
            element("row4"),
            element("row5"),
            element("row6"),
            element("row7"),
        ];

        function elements(cls) {
            let v = doc.getElementsByClassName(cls);
            if (v.length == 0) {
                throw Error("not HTML elements with class " + cls);
            }

            return v;
        }

        this.vars = [elements("var_a"), elements("var_b"), elements("var_c") ];
        this.hex = elements("hex");
    }

    update() {
        if (this.input.value == this.expr_str) {
            return;
        }

        this.expr_str = this.input.value;

        try {
            const tokens = tokenize(this.expr_str);
            const variables = this.resolve_variables(tokens);
            const lex    = new Lexer(tokens);
            const expr   = parse(lex);

            this.set_variables(expr, variables);
            this.evaluate(expr, variables);

            this.input.classList.remove("error");
        } catch (err) {
            input.classList.add("error");

            if (err.message == TOKENIZE_ERROR) {
                const msg = err.cause[0];
                const pos = err.cause[1];
                const len = 1;
                this.set_error(msg, pos, len);
            } else if (err.message == PARSE_ERROR) {
                const msg = err.cause[0];
                const pos = err.cause[1];
                const len = err.cause[2];
                this.set_error(msg, pos, len);
            } else {
                throw err;
            }
        }
    }

    resolve_variables(tokens) {
        let variables = new Set();
        for (let i in tokens) {
            const token = tokens[i];
            if (token.type == TOKEN_ATOM) {
                variables.add(token.atom);
            }
        }

        if (variables.length > 3) {
            throw Error("up to three variables allowed, found " + variables);
        }

        let arr = [];
        for (let variable of variables) {
            arr.push(variable);
        }

        arr.sort();

        return arr;
    }

    evaluate(expr, variables) {
        const combinations = [
            [0, 0, 0],
            [0, 0, 1],
            [0, 1, 0],
            [0, 1, 1],
            [1, 0, 0],
            [1, 0, 1],
            [1, 1, 0],
            [1, 1, 1],
        ];

        const op = function(op, arg1, arg2) {
            switch (op) {
                case OP_AND: return arg1 & arg2;
                case OP_OR:  return arg1 | arg2;
                case OP_XOR: return arg1 ^ arg2;
                case OP_NOT:
                    if (arg1 == 1) {
                        return 0;
                    } else {
                        return 1;
                    }
            }
        }

        let val = 0;
        let weight = 1;
        for (let i in combinations) {
            const atom = function(name) {
                const var_id = variables.indexOf(name);
                if (var_id >= 0) {
                    return combinations[i][var_id];
                }
            }

            const res = expr.preorder(atom, op);

            let out = this.values[i];
            let row = this.rows[i];

            row.classList.remove("one", "zero");
            if (res == undefined) {
                out.innerHTML = '&mdash;';
            } else {
                out.innerText = res;
                if (res) {
                    row.classList.add("one");
                    val += weight;
                } else {
                    row.classList.add("zero");
                }
            }

            weight = weight << 1;
        }

        for (const elem of this.hex) {
            elem.innerText = val2hex(val);
        }
    }

    set_variables(expr, variables) {
        let fun = "f(";
        for (let i=0; i < 3; i++) {
            let name = variables[i];
            if (name == undefined) {
                name = '?';
            }

            if (i > 0) {
                fun += ',';
            }

            fun += name;

            for (let elem of this.vars[i]) {
                elem.innerText = name;
            }
        }

        fun += ')';
        this.fun.innerText = fun;
        this.expression.innerText = fun + ' = ' + expr.to_string();
        this.message.innerText = '';
    }

    unset_error() {
        input.classList.remove("error");
        this.message.innerHTML = '';
    }

    set_error(msg, position, length) {
        this.input.classList.add("error");
        if (position == undefined || length == undefined) {
            this.message.innerHTML = msg;
        } else {
            const before    = this.expr_str.substr(0, position);
            const highlight = this.expr_str.substr(position, length);
            const after     = this.expr_str.substr(position + length);

            this.expression.innerHTML = '';
            let f1 = this.doc.createElement("tt");
            f1.innerText = before;
            let f2 = this.doc.createElement("tt");
            f2.classList.add("highlight");
            f2.classList.add("error");
            f2.innerText = highlight;
            let f3 = this.doc.createElement("tt");
            f3.innerText = after;

            this.expression.appendChild(f1);
            this.expression.appendChild(f2);
            this.expression.appendChild(f3);

            this.message.innerHTML = '';
            let p2 = this.doc.createElement("i");
            p2.innerText = msg;
            this.message.appendChild(p2)
        }
    }
}

function val2hex(val) {
    const nibble2digit = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'];
    return nibble2digit[val >> 4] + nibble2digit[val & 0xf];
}

if (typeof document !== 'undefined') {
    document.addEventListener('DOMContentLoaded', function() {
        let view = new View(document);

        document.addEventListener("keyup", function(event) {
            if (document.activeElement === view.input) {
                view.update()
            }
        });

        view.update();
    }, false);
}
