var max = 0;

function dfs(dungeons, visit, k, cnt) {
  if (cnt > max) max = cnt;
  for (var i = 0; i < dungeons.length; i++) {
    if (k >= dungeons[i][0] && !visit[i]) {
      visit[i] = 1;
      dfs(dungeons, visit, k - dungeons[i][1], cnt + 1);
      visit[i] = 0;
    }
  }
}

function solution(k, dungeons) {
 
  
  for (var i = 0; i < dungeons.length; i++) { 
      var visit = Array(dungeons.length).fill(0);
    if (k >= dungeons[i][0]) {
      visit[i] = 1;
      dfs(dungeons, visit, k - dungeons[i][1], 1);
      visit[i] = 0;
    }
  }

  return max;
}