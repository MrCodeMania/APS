function solution(n, t, m, timetable) {
  var answer = "";

  for (var i = 0; i < timetable.length; i++) {
    timetable[i] = Number(timetable[i].split(":").join(""));
  }

  timetable.sort((a, b) => a - b);

  var shuttle = 900;
  var lastTime = 0;

  for (var i = 0; i < n; i++) {
    var cnt = 0;

    while (timetable[0] <= shuttle) {
      lastTime = timetable[0];
      timetable.shift();
      cnt++;

      if (cnt == m) {
        answer = lastTime - 1;
        if (answer % 100 >= 60) answer -= 40;
        break;
      }
    }

    if (i == n - 1 && cnt < m) answer = shuttle;

    shuttle += t;
    if (shuttle % 100 >= 60) shuttle += 40;
  }

  var hour =
    Math.floor(answer / 100) < 10
      ? "0" + Math.floor(answer / 100)
      : "" + Math.floor(answer / 100);
  var min = answer % 100 < 10 ? "0" + (answer % 100) : "" + (answer % 100);

  return hour + ":" + min;
}

solution(2, 10, 2, ["09:10", "09:09", "08:00"]);
