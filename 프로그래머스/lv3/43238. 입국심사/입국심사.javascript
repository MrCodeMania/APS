function solution(n, times) {
  var answer = 0;

  times.sort();

  var high = times[0] * n;
  var low = 0;

  while (high > low) {
    var mid = Math.floor((low + high) / 2);
    var cnt = 0;
    for (var t of times) cnt += Math.floor(mid / t);

    if (cnt >= n) high = mid;
    else low = mid + 1;
  }

  return high;
}

solution(2, [7, 10]);
