#include <iostream>
#include <cstring>

int main(){
	char str[] = "a";
	char str1[] = "b";
	std::cout<<strcmp(str,str1)<<"  "<<strcmp(str1,str)<<"  "<<strcmp(str,str)<<std::endl;
	return 0;
} 
