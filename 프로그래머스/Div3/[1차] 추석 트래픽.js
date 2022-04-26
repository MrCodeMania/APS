function solution(lines) {
  var answer = 0;

  var timeline = [];
  var delay = [];

  var flag = false;

  if (lines[0].length == 1) flag = true;

  if (flag) {
    timeline.push(lines.split(/[\ss]/)[1]);
    delay.push(lines.split(/[\ss]/)[2]);
  } else {
    for (s of lines) {
      var temp = s.split(/[\ss]/);

      timeline.push(temp[1]);
      delay.push(temp[2]);

      console.log(temp);
    }
  }

  var time = [];

  for (var i = 0; i < timeline.length; i++) {
    time.push(timeline[i].split(":"));

    for (var j = 0; j < 3; j++) time[i][j] = Number(time[i][j]);

    delay[i] = Number(delay[i]) - 0.001;

    // 초로 모두 변환후
    // 시작과 끝을 저장
    // 이중 for문으로 계산

    time[i] = [time[i][0] * 3600000 + time[i][1] * 60000 + time[i][2] * 1000];
    time[i].unshift(time[i][0] - delay[i] * 1000);
  }

  var maxCount = 0;
  for (var i = 0; i < time.length; i++) {
    var s = time[i][0];
    var e = time[i][1];
    var count = [1, 1, 1, 1];
    for (var j = 0; j < time.length; j++) {
      if (i == j) continue;
      if (
        (s - 999 <= time[j][0] && time[j][0] <= s) ||
        (s - 999 <= time[j][1] && time[j][1] <= s) ||
        (time[j][0] <= s - 999 && s - 999 <= time[j][1])
      )
        count[0]++;
      if (
        (s <= time[j][0] && time[j][0] <= s + 999) ||
        (s <= time[j][1] && time[j][1] <= s + 999) ||
        (time[j][0] <= s + 999 && s + 999 <= time[j][1])
      )
        count[1]++;
      if (
        (e - 999 <= time[j][0] && time[j][0] <= e) ||
        (e - 999 <= time[j][1] && time[j][1] <= e) ||
        (time[j][0] <= e - 999 && e - 999 <= time[j][1])
      )
        count[2]++;
      if (
        (e <= time[j][0] && time[j][0] <= e + 999) ||
        (e <= time[j][1] && time[j][1] <= e + 999) ||
        (time[j][0] <= e + 999 && e + 999 <= time[j][1])
      )
        count[3]++;
    }
    console.log(count);
    if (Math.max(...count) > maxCount) maxCount = Math.max(...count);
  }
  return maxCount;
}

solution([
  "2016-09-15 20:59:57.421 0.351s",
  "2016-09-15 20:59:58.233 1.181s",
  "2016-09-15 20:59:58.299 0.8s",
  "2016-09-15 20:59:58.688 1.041s",
  "2016-09-15 20:59:59.591 1.412s",
  "2016-09-15 21:00:00.464 1.466s",
  "2016-09-15 21:00:00.741 1.581s",
  "2016-09-15 21:00:00.748 2.31s",
  "2016-09-15 21:00:00.966 0.381s",
  "2016-09-15 21:00:02.066 2.62s",
]);
