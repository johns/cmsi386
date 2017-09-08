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
  return [Math.trunc(quarters), Math.trunc(dimes), Math.trunc(nickles), c];
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

function powers(base, limit, p) {
  let num = 0;
  let i = 0;
  while (num < limit) {
    num = base ** i;
    i++;
  }
}


module.exports = {
  change, stripQuotes, scramble, powers,
};
