function solution(genres, plays) {
  var answer = [];
  var arr = [];
  var m = new Map();
  var idx = 0;

  for (var value of genres) {
    if (m.get(value) == null) m.set(value, idx++);
    else continue;
  }

  for (var i = 0; i < idx; i++) {
    arr[i] = [];
  }

  for (var i = 0; i < plays.length; i++) {
    arr[m.get(genres[i])].push([plays[i], i]);
  }

  for (var i = 0; i < arr.length; i++) {
    arr[i].sort((a, b) => (a[0] - b[0] == 0 ? a[1] - b[1] : b[0] - a[0]));
  }

  for (var i = 0; i < arr.length; i++) {
    var sum = 0;
    for (var j = 0; j < arr[i].length; j++) {
      sum += arr[i][j][0];
    }
    arr[i].push(sum);
  }

  while (true) {
    if (arr.length == 0) break;
    var maxIdx = 0;
    for (var i = 0; i < arr.length; i++) {
      if (arr[i][arr[i].length - 1] > arr[maxIdx][arr[maxIdx].length - 1]) {
        maxIdx = i;
      }
    }

    answer.push(arr[maxIdx][0][1]);
    if (arr[maxIdx].length > 2) answer.push(arr[maxIdx][1][1]);

    arr.splice(maxIdx, 1);
  }

  return answer;
}

console.log(
  solution(["A", "B", "A", "B", "A", "C"], [500, 600, 150, 800, 2500, 5000])
);
