class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for(int i = 0; i < n; i++) {
            String binaryArr1 = Integer.toBinaryString(arr1[i]);
            String binaryArr2 = Integer.toBinaryString(arr2[i]);
            
            while(binaryArr1.length() < n) {
                binaryArr1 = "0" + binaryArr1;
            }
            while(binaryArr2.length() < n) {
                binaryArr2 = "0" + binaryArr2;
            }
            
            String temp = "";
            for(int j = 0; j < n; j++) {
                if(binaryArr1.charAt(j) == '1' || binaryArr2.charAt(j) == '1') {
                    temp += "1";    
                } else {
                    temp += "0";
                }
            }
            
            answer[i] = temp;
        }
        
        for(int i = 0; i < n; i++) {
            answer[i] = answer[i].replaceAll("0", " ");
            answer[i] = answer[i].replaceAll("1", "#");
        }
        
        return answer;
    }
}