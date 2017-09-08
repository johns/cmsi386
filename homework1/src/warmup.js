function change (c) {
	if (c < 0) {
		throw new RangeError("Amount Cannot be Negative");
	}
	var quarters = c/25;
	c %= 25;
	var dimes = c/10;
	c %= 10;
	var nickles = c/5;
	c %= 5;
	var pennies = c/1;
	return [Math.trunc(quarters), Math.trunc(dimes), Math.trunc(nickles), pennies];
}

function stripQuotes (s) {
	return s.replace(/"|'/gi, "");
}

function scramble (s) {
	var scrambledWord = "";
	while (s.length > 0) {
		var randomIndex = Math.trunc(Math.random() * s.length);
		scrambledWord += s.charAt(randomIndex);
		s = s.replace(s.charAt(randomIndex), "");
	}
	return scrambledWord
}

function powers (base, limit, p) {
	var num = 0;
	var i = 0;
	while (num < limit) {
		num = Math.pow(base, i)
		i++;
	}
}


module.exports = {
  change, stripQuotes, scramble, powers,
};
