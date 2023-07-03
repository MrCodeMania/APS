import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

/*
1. plans 시작 시간을 기준으로 정렬
2-1. 시작 시간 + playtime 이 다음 과제의 시작 시간보다 높다면
    1) playtime -= 다음 과제 시작 시간 - 지금 과제 시작 시간 연산 후
    2) Stack에 push

2-2 시작 시간 + play time 이 다음 과제의 시작 시간보다 낮다면
    1) Stack.size() > 0 이면, pop하여 과제 이어서 진행
    2) 2-1, 2-2 반복
*/

class Solution {
        public String[] solution(String[][] plans) {
            String[] answer = new String[plans.length];

            Stack<Assignment> s = new Stack<>();

            List<Assignment> list = new ArrayList<>();
            for (String[] element : plans) {
                list.add(new Assignment(element));
            }

            list.add(new Assignment("end", 1000000, 100));

            Collections.sort(list);

            int complete = 0;
            int index = 0;
            int lastTime = 0;

            while(complete < list.size() - 1){

                while(lastTime < list.get(index).start){
                    // stack에서 꺼내고 list.get(index).start 보다 작다면
                    // lastTime 갱신 및 다음 stack을 꺼낸다.

                    // 크다면 time을 그만큼 제거하고 stack에 다시 넣고
                    // lastTime을 list.get(index).start로 갱신한다.
                    while(!s.isEmpty()){
                        Assignment top = s.pop();
                        if(lastTime + top.time <= list.get(index).start){
                            answer[complete++] = top.name;
                            lastTime += top.time;
                        } else {
                            top.time -= list.get(index).start - lastTime;
                            s.push(top);
                            break;
                        }
                    }

                    lastTime = list.get(index).start;
                }

                lastTime = list.get(index).start + list.get(index).time;

                index++;

                if(index < list.size()) {
                    if (lastTime > list.get(index).start) {
                        list.get(index - 1).time -= list.get(index).start - list.get(index - 1).start;
                        s.push(list.get(index - 1));
                        lastTime = list.get(index).start;
                    } else if (lastTime == list.get(index).start) {
                        answer[complete++] = list.get(index - 1).name;
                    } else {
                        lastTime -= list.get(index - 1).time;
                        s.push(list.get(index - 1));
                    }
                }
            }

            return answer;
        }
    }

    class Assignment implements Comparable<Assignment>{
        String name;
        int start;
        int time;
        public Assignment(String[] plan){
            this.name = plan[0];
            this.start = Integer.valueOf(plan[1].substring(0,2)) * 60 + Integer.valueOf(plan[1].substring(3,5));
            this.time = Integer.valueOf(plan[2]);
        }
        public Assignment(String name, int start, int time){
            this.name = name;
            this.start = start;
            this.time = time;
        }
        @Override
        public int compareTo(Assignment a){
            if(this.start < a.start)
                return -1;
            else if (this.start > a.start)
                return 1;
            else
                return 0;
        }
    }