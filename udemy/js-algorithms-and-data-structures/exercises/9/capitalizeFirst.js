function capitalizeFirst(arr) {
  return arr.map(str => str[0].toUpperCase().concat(str.slice(1)));
}

console.log(
  capitalizeFirst(['1234', 'fdsaga', 'afdfaGGAa', 'GGAdfadf']),
);
