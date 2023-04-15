#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> sw(n + 1, 0);

    for(int i = 1; i <= n; i++){
        cin >> sw[i];
    }

    int student;
    cin >> student;

    while(student--){
        int gender;
        cin >> gender;

        int num;
        cin >> num;

        if(gender == 1){
            for(int i = num; i <= n; i+=num){
                sw[i] += 1;
                sw[i] %= 2;
            }
        }
        else{
            int left = num;
            int right = num;
            while(true){
                left -= 1;
                right += 1;

                if(!(left > 0 && right <= n)){
                    break;
                }

                if(sw[left] == sw[right]) {
                    sw[left] = (sw[left] + 1) % 2;
                    sw[right] = (sw[right] + 1) % 2;
                }
                else{
                    break;
                }
            }
            sw[num] = (sw[num] + 1) % 2;
                    
        }
    }

    for(int i = 1; i <= n; i++){
        cout << sw[i] << " ";
        if(i % 20 == 0)
            cout << endl;
    }
}