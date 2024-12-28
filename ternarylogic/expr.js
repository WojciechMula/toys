const TOKENIZE_ERROR = "tokenize";
const PARSE_ERROR = "parse";

const TOKEN_AND = 1;
const TOKEN_OR  = 2;
const TOKEN_XOR = 3;
const TOKEN_NOT = 4;
const TOKEN_LPAREN = 10;
const TOKEN_RPAREN = 11;
const TOKEN_ATOM = 42;
const TOKEN_EOF  = 100;

class Token {
    constructor(type, atom, position, length) {
        this.type = type;
        this.atom = atom;
        this.position = position;
        this.length = length;
    }

    to_string() {
        switch (this.type) {
            case TOKEN_NOT: return "not";
            case TOKEN_AND: return "and";
            case TOKEN_OR: return "or";
            case TOKEN_XOR: return "xor";
            case TOKEN_LPAREN: return "(";
            case TOKEN_RPAREN: return ")";
            case TOKEN_EOF: return "end of string";
            case TOKEN_ATOM: return "var(" + this.atom + ")";
        }
    }
}

function tokenize(s) {
    let res = [];

    let position = 0;
    let literal = '';
    let literal_start = 0;

    function push_token(token, length) {
        flush_literal()
        res.push(new Token(token, undefined, position, length));
    }

    function extend_literal(c) {
        if (literal) {
            literal += c;
        } else {
            literal = c;
            literal_start = position;
        }
    }

    function flush_literal() {
        if (literal) {
            res.push(new Token(TOKEN_ATOM, literal, literal_start, literal.length));
            literal = '';
        }
    }

    while (s) {
        const c0 = s.at(0);
        let n = 1;
        switch (c0) {
            case 'a':
            case 'A':
                c1 = s.at(1);
                c2 = s.at(2);
                c3 = s.at(3);
                if ((c1 == 'n' || c1 == 'N') && (c2 = 'd' || c2 == 'D') && !is_letter(c3)) {
                    push_token(TOKEN_AND, 3);
                    n = 3;
                } else {
                    extend_literal(c0);
                }
                break;

            case 'o':
            case 'O':
                c1 = s.at(1);
                c2 = s.at(2);
                if ((c1 == 'r' || c1 == 'R') && !is_letter(c2)) {
                    push_token(TOKEN_OR, 2);
                    n = 2;
                } else {
                    extend_literal(c0);
                }
                break;

            case 'x':
            case 'X':
                c1 = s.at(1);
                c2 = s.at(2);
                c3 = s.at(3);
                if ((c1 == 'o' || c1 == 'O') && (c2 == 'r' || c2 == 'R') && !is_letter(c3)) {
                    push_token(TOKEN_XOR, 3);
                    n = 3;
                } else {
                    extend_literal(c0);
                }
                break;

            case 'n':
            case 'N':
                c1 = s.at(1);
                c2 = s.at(2);
                c3 = s.at(3);
                if ((c1 == 'o' || c1 == 'O') && (c2 == 't' || c2 == 'T') && !is_letter(c3)) {
                    push_token(TOKEN_NOT, 3);
                    n = 3;
                } else {
                    literal += c0;
                }
                break;

            case '~':
            case '!':
                push_token(TOKEN_NOT, 1);
                break;

            case '&':
                push_token(TOKEN_AND, 1);
                break;

            case '|':
                push_token(TOKEN_OR, 1);
                break;

            case '^':
                push_token(TOKEN_XOR, 1);
                break;

            case '(':
                push_token(TOKEN_LPAREN, 1);
                break;

            case ')':
                push_token(TOKEN_RPAREN, 1);
                break;

            case ' ':
                flush_literal();
                break;

            default:
                if (is_letter(c0)) {
                    extend_literal(c0);
                } else {
                    throw Error(TOKENIZE_ERROR, {cause: ["unexpected character '" + c0 +"'", position]});
                }
                break;
        }

        s = s.substr(n);
        position += n;
    }

    flush_literal();

    return res;
}

function is_letter(c) {
    if (c != undefined) {
        return c.match(/[a-zA-Z]/);
    }

    return false;
}

class Lexer {
    constructor(tokens) {
        this.tokens = tokens;
        this.eof = new Token(TOKEN_EOF)
    }

    is_empty() {
        return this.tokens.length == 0;
    }

    position() {
        return this.max - this.tokens.length;
    }

    peek() {
        let v = this.tokens[0];
        if (v == undefined) {
            return this.eof;
        }

        return v;
    }

    consume() {
        let v = this.tokens.shift();
        if (v == undefined) {
            return this.eof;
        }

        return v;
    }
}

const OP_AND = 100;
const OP_OR  = 101;
const OP_XOR = 102;
const OP_NOT = 103;

class Node {
    constructor(op, arg1, arg2) {
        this.op   = op;
        this.arg1 = arg1;
        this.arg2 = arg2;
    }

    to_string() {
        if (this.arg2 != undefined) {
            return '(' + this.arg1.to_string() + ' ' + op2str(this.op) + ' ' + this.arg2.to_string() + ')';
        } else {
            return '(' + op2str(this.op) + ' ' + this.arg1.to_string() + ')';
        }
    }

    preorder(atom, op) {
        const arg1 = this.arg1.preorder(atom, op);
        if (this.arg2 == undefined) {
            return op(this.op, arg1);
        }

        const arg2 = this.arg2.preorder(atom, op);
        return op(this.op, arg1, arg2);
    }
}

function op2str(op) {
    switch (op) {
        case OP_AND: return "and";
        case OP_OR:  return "or";
        case OP_XOR: return "xor";
        case OP_NOT: return "not";
    }
}

class Atom {
    constructor(arg) {
        this.arg = arg
    }

    preorder(atom, op) {
        return atom(this.arg.atom);
    }

    to_string() {
        return this.arg.atom;
    }
}

function parse(lex, terminator) {
    let arg1 = parse_expression(lex);

    while (!lex.is_empty()) {
        token = lex.peek();
        let op = undefined;
        switch (token.type) {
            case TOKEN_AND:
                op = OP_AND;
                break;

            case TOKEN_OR:
                op = OP_OR;
                break;

            case TOKEN_XOR:
                op = OP_XOR;
                break;

            default:
                if (token.type == terminator) {
                    return arg1;
                }

                throw Error(PARSE_ERROR, {cause: ["unexpected " + token.to_string(), token.position, token.length]});
        }

        lex.consume();

        let arg2 = parse_expression(lex);

        arg1 = new Node(op, arg1, arg2)
    }

    return arg1;
}

function parse_expression(lex) {
    let token = lex.peek();
    switch (token.type) {
        case TOKEN_NOT:
            lex.consume();
            return new Node(OP_NOT, parse_expression(lex));

        case TOKEN_LPAREN:
            let pos = lex.position();
            lex.consume();
            let expr = parse(lex, TOKEN_RPAREN);
            if (lex.peek().type != TOKEN_RPAREN) {
                throw Error(PARSE_ERROR, {cause: ["missing the closing parenthesis", token.position, token.length]});
            }

            lex.consume();
            return expr;

        case TOKEN_ATOM:
            lex.consume();
            return new Atom(token);

        default:
            throw Error(PARSE_ERROR, {cause: ["unexpected " + token.to_string(), token.position, token.length]});
    }
}

if (typeof document === 'undefined') {
    function assert_eq(input, got, want) {
        if (want != got) {
            console.log("input: " + input);
            console.log("want:  " + want);
            console.log("got:   " + got);
            throw Error("test failed");
        }
    }

    function test_tokenize_valid() {
        const cases = [
            ["a", "var(a)"],
            ["a b c", "var(a) var(b) var(c)"],
            ["  bc    ", "var(bc)"],
            ["not a  and not  bcd or ef xor   gh", "not var(a) and not var(bcd) or var(ef) xor var(gh)"],
            ["! a  & !!  bcd | ef ^   gh", "not var(a) and not not var(bcd) or var(ef) xor var(gh)"],
        ];

        for (const i in cases) {
            const tc = cases[i];
            const input = tc[0];
            const want  = tc[1];
            const list  = tokenize(input);

            let tmp = [];
            for (const item of list) {
                tmp.push(item.to_string());
            }

            const got = tmp.join(' ');

            assert_eq(input, got, want);
        }
    }

    function test_tokenize_invalid() {
        const cases = [
            ["what is this?", "unexpected character '?'", 12],
        ];

        for (const i in cases) {
            const tc = cases[i];
            const input = tc[0];
            const msg   = tc[1];
            const pos   = tc[2];

            try {
                tokenize(input);
                throw Error("expected an error to be thrown");
            } catch (err) {
                if (err.message != TOKENIZE_ERROR) {
                    throw Error("unexepected error: " + err.message);
                }

                assert_eq(input, err.cause[0], msg);
                assert_eq(input, err.cause[1], pos);
            }
        }
    }

    function test_parse_valid() {
        const cases = [
            ["a AND b", "(a and b)"],
            ["a and b and c and d", "(((a and b) and c) and d)"],
            ["a and not b", "(a and (not b))"],
            ["!!!x", "(not (not (not x)))"],
        ];

        for (const i in cases) {
            const tc = cases[i];
            const input = tc[0];
            const want  = tc[1];

            const tokens = tokenize(input);
            const lex = new Lexer(tokens);
            const expr = parse(lex);
            const got = expr.to_string();

            assert_eq(input, got, want);
        }
    }

    function test_parse_invalid() {
        const cases = [
            ["a bcde", "unexpected var(bcde)", 2, 4],
            ["a (b or c)", "unexpected (", 2, 1],
            ["   (", "unexpected end of string", undefined, undefined],
            ["x or (a xor b ", "missing the closing parenthesis", 5, 1],
        ];

        for (const i in cases) {
            const tc = cases[i];
            const input = tc[0];
            const msg   = tc[1];
            const pos   = tc[2];
            const len   = tc[3];

            const tokens = tokenize(input);
            const lex = new Lexer(tokens);

            try {
                const expr = parse(lex);
                console.log(expr)
                throw Error("expected an error to be thrown");
            } catch (err) {
                if (err.message != PARSE_ERROR) {
                    throw Error("unexepected error: " + err.message);
                }

                assert_eq(input, err.cause[0], msg);
                assert_eq(input, err.cause[1], pos);
                assert_eq(input, err.cause[2], len);
            }
        }
    }

    test_tokenize_valid();
    test_tokenize_invalid();
    test_parse_valid();
    test_parse_invalid();

    console.log("All OK");
}
