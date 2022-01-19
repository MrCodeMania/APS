#include<iostream> 
int main()
{
	int n;std::cin>>n;
	int t=1;
	while(t <= n){
		int i = 0;
		while (i++ < t) {
			std::cout<<'*';}
		t++;
		std::cout<<std::endl;}}