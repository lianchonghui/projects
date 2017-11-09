#include<iostream>
int main(){
	std::cout<<"hello c++"<<std::endl;
	int num1 = 1;
	int num2 = 1;
	int sum = 0;
	//std::cout<<num1++<<std::endl;
	//std::cout<<++num2<<std::endl;
	while(num1<=10){
		sum += num1++;
	}
	std::cout<<sum<<std::endl;
	sum = 0;
	while(num2<=10){
		sum += num2;
		num2++;
	}
	std::cout<<sum<<std::endl;
	return 0;
}
