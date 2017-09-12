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

function powers(base, limit, p) {
  let answer = 1;
  let exp = 1;
  while (answer <= limit) {
    p(answer);
    answer = base ** exp;
    exp += 1;
  }
}

function* powersGenerator(base, limit) {
  let exp = 0;
  while (base ** exp <= limit) {
    yield base ** exp;
    exp += 1;
  }
}

// const say = ((word) => {
//   let result = word;
//   return () => {
//     result += word;
//     return result;
//   };
// })();

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

function makeCryptoFunctions(key, algorithm) { // Add specific throw error
  const crypto = require('crypto');
  function encrypt(text) {
    const cipher = crypto.createCipher(algorithm, key);
    let crypted = cipher.update(text, 'utf8', 'hex');
    crypted += cipher.final('hex');
    return crypted;
  }
  function decrypt(text) {
    const decipher = crypto.createDecipher(algorithm, key);
    let dec = decipher.update(text, 'hex', 'utf8');
    dec += decipher.final('utf8');
    return dec;
  }
  return [encrypt, decrypt];
}

function cylinder(c) {
  let { radius, height } = c;
  if (radius === undefined) {
    radius = 1;
  }
  if (height === undefined) {
    height = 1;
  }
  const surfaceArea = () => (2 * Math.PI * radius * height) + (2 * Math.PI * radius * radius);
  const volume = () => Math.PI * radius * radius * height;
  const widen = (factor) => { radius *= factor; };
  const stretch = (factor) => { height *= factor; };
  const toString = () => `Cylinder with radius ${radius} and height ${height}`;
  return Object.freeze({
    radius, height, surfaceArea, volume, widen, stretch, toString,
  });
}

module.exports = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  // say,
  interleave,
  cylinder,
  makeCryptoFunctions,
  // randomName
};
