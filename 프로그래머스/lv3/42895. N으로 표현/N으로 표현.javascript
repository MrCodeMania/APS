function solution(N, number) {
  var S = [];
  for (var i = 1; i <= 8; i++) S[i] = new Set();

  S[1].add(N);

    if(N == number)
        return 1;
    
  for (var level = 2; level <= 8; level++) {
    var str = N;
    for (var i = 2; i <= level; i++) str += N + "";

    S[level].add(Number(str));

    for (var i = 1; i < level; i++) {
      for (var x of S[i]) {
        for (var y of S[level - i]) {
          S[level].add(x + y);
          S[level].add(x * y);
          if (x - y > 0) S[level].add(x - y);
          if (x > 0 && y > 0) S[level].add(Math.floor(x / y));
        }
      }
    }

    if (S[level].has(number)) return level;
  }

  return -1;
}

solution(5, 12);