function matching(keyRotate, lock) {
    
    
  // 20 * 20 20 * 20 20 * 20 공간에
  // 20 * 20 20 * 20 20 * 20
  // 20 * 20 20 * 20 20 * 20
  
  // 가운데 lock 올리고 60 * 60에 대해서 key를 완탐 xor 대입
  // lock이 올라간 크기만큼 완탐, 모두 1이면 true else false
  
      
      var space = [];
      
      for(var i = 0; i < lock.length * 3; i++){
          space[i] = [];
          for(var j = 0; j < lock.length * 3; j++){
              if(lock.length <= i && i < lock.length * 2 && lock.length <= j && j < lock.length * 2)
                  space[i].push(lock[i-lock.length][j-lock.length]);
              else
                  space[i].push(0);
          }
      }
      
      for(var i = 0; i < lock.length * 2; i++){
          for(var j = 0; j < lock.length * 2; j++){
              var spaceCopy = JSON.parse(JSON.stringify(space));
              for(var m = 0; m < keyRotate.length; m++){
                  for(var n = 0; n < keyRotate.length; n++){
                      spaceCopy[i+m][j+n] = keyRotate[m][n]^space[i+m][j+n];
                  }
              }

              var flag = true;
          
                for(var m = 0; m < lock.length; m++){

                  for(var n = 0; n < lock.length; n++){
                
                    if(spaceCopy[m + lock.length][n + lock.length] == 0 && flag)
                      flag = false;
               
                  }
                      if(!flag)
                          break;
              }
              
                          
                      if(flag)
                        return true;
             
              
          }
      }
      
      
  
    return false;
  }
  
  function solution(key, lock) {
    var answer = true;
      
      if(Number(lock.reduce((pre, cur) => pre.concat(cur,[0])).reduce((a,b) => a+b)) == lock.length * lock.length)
          return true;
  
    //key 4방향으로 돌리기
    var keyRotate = JSON.parse(JSON.stringify(key));
    var keyCopy = JSON.parse(JSON.stringify(key));
  
    // 패턴파악 후 회전, 총 3회전, 4 패턴파악
    answer = matching(keyRotate, lock);
    var t = 0;
  
    while (!answer && t < 3) {
      //rotate
      for (var i = 0, k = keyCopy.length - 1; i < keyCopy.length; i++, k--) {
        for (var j = 0; j < keyRotate.length; j++) {
          keyRotate[j][k] = keyCopy[i][j];
        }
      }
  
      answer = matching(keyRotate, lock);
      keyCopy = JSON.parse(JSON.stringify(keyRotate));
      t++;
    }
  
    return answer;
  }

  solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],[[1, 1, 1], [1, 1, 0], [1, 0, 1]]);