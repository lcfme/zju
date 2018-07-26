// #! /usr/bin/env node

var expr = '- / 3 2 * 1 / 8 9';
/**
 *  3 - 2 / 2 - 1 * 8 / 9
 *
 */

const evalMath = (function() {
  var expr,
    ch,
    i,
    signTable = {
      '+': '+',
      '-': '-',
      '*': '*',
      '/': '/'
    },
    opStack = [],
    numStack = [];
  function skipSpace() {
    if (/\s/.test(ch)) next();
  }
  function parseExpr() {
    while (ch) {
      skipSpace();
      var op;
      if ((op = isOp())) {
        opStack.push(op);
        var left = numStack.pop();
        var right = numStack.pop();
        var _op = opStack.pop();
        switch (_op) {
          case '+':
            numStack.push(left + right);
            break;
          case '-':
            numStack.push(left - right);
            break;
          case '*':
            numStack.push(left * right);
            break;
          case '/':
            numStack.push(left / right);
            break;
          default:
            throw new Error('Invald op');
        }
        continue;
      }
      var value;
      if ((value = parseNum())) {
        numStack.push(value);
        continue;
      }
      throw new Error('Invalid Expr');
    }
    var result = numStack.pop();
    if (numStack.length) throw new Error('Invalid Expr');
    return result;
  }
  function isOp() {
    var op = signTable[ch];
    if (op) {
      next();
    }
    return op;
  }
  function parseNum() {
    var val = '';
    while (ch && /[\d.]/.test(ch)) {
      val = ch + val;
      next();
    }
    val = Number(val);
    if (isNaN(val)) throw new Error('Invald Number');
    return val;
  }
  function next() {
    ch = expr[--i];
  }
  return function(_expr) {
    expr = _expr;
    i = expr.length - 1;
    ch = expr[i];
    opStack = [];
    numStack = [];
    return parseExpr();
  };
})();

evalMath(expr);
