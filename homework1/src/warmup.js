function change(c) {
  if (c < 0) {
    throw new RangeError('Amount Cannot be Negative');
  }
  let coins = c;
  const quarters = coins / 25;
  coins %= 25;
  const dimes = coins / 10;
  coins %= 10;
  const nickles = coins / 5;
  coins %= 5;
  return [Math.trunc(quarters), Math.trunc(dimes), Math.trunc(nickles), coins];
}

function stripQuotes(s) {
  return s.replace(/"|'/gi, '');
}

function scramble(w) {
  let words = w;
  let scrambledWord = '';
  while (words.length > 0) {
    const randomIndex = Math.trunc(Math.random() * words.length);
    scrambledWord += words.charAt(randomIndex);
    words = words.replace(words.charAt(randomIndex), '');
  }
  return scrambledWord;
}

function powers(base, limit, p) { // BUG
  if (p === undefined) {
    powers(base, limit, 1);
  }
  if (p <= limit) {
    powers(base, limit, base * p);
  }
}

function* powersGenerator(base, limit) {
  let answer = 1;
  while (answer < limit) {
    if (answer === 1) {
      answer = base;
      yield answer;
    }
    yield answer;
    answer **= base;
  }
}

function say() {
}

function interleave(a, ...v) {
  let counter = 0;
  const result = [];
  for (let i = 0; i < a.length; i += 1) {
    result.push(a[i]);
    if (i < v.length) {
      result.push(v[i]);
    }
    counter = i + 1;
  }
  for (let j = counter; j < v.length; j += 1) {
    result.push(v[j]);
  }
  return result;
}

module.exports = {
  change, stripQuotes, scramble, powers, powersGenerator, say, interleave,
};
