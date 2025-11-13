import java.util.ArrayList;
class Solution {
    //반환값의 갯수를 모르니 List를 사용.
    public ArrayList<Integer> solution(String today, String[] terms, String[] privacies) {

        //약관종류 A~Z에 대한 유효기간 배열
        int[] duration = new int[26]; 
        for(String s : terms) duration[s.charAt(0)-65]=Integer.parseInt(s.substring(2,s.length()));

        // 오늘 날짜의 변환값
        // 필요한 값이 월단위 이므로 한달의 크기는 마음대로 설정(편의상 100으로 둠)
        int varToday = Integer.parseInt(today.substring(2,4))*1200
                        + Integer.parseInt(today.substring(5,7))*100
                        + Integer.parseInt(today.substring(8,10));        

        //정답 반환을 위한 배열 생성
        ArrayList<Integer> li = new ArrayList<>();


        for(int i=0; i<privacies.length; i++){

        // varToday와 같은 포맷으로 개인정보 수집 일자를 변환.
            int varDate = Integer.parseInt(privacies[i].substring(2,4))*1200
                + Integer.parseInt(privacies[i].substring(5,7))*100
                + Integer.parseInt(privacies[i].substring(8,10));

        // 약관종류에 따른 유효기간(월)을 불러옴.
            int varTerm = duration[privacies[i].charAt(11)-65];

        // 1월은 100임에 유의하여 유효기간이 지났으면 리스트에 번호 추가
        // 제시된 정보가 2021년1월5일 + 12달 일때 2022년1월5일 파기로 제시되었으니 값이 같을때도 포함.
            if( varToday >= varDate + varTerm*100 ) li.add(i+1);
        }

        // 리스트 반환
        return li;
    }
}