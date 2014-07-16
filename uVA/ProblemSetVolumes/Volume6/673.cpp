#include<cstdio>
#include<stack>
using namespace std;
char reverse(char a){
	return a == ')' ? '(' : '[';
}
int main(void){
	bool result;
	int testCases;
	char input[130],*cursor;
	scanf("%d ",&testCases);
	while(testCases--){
		stack<char> left;
		gets(input);
		cursor = input;
		result = true;
		if(*cursor != '\0')
			do{
				if(*cursor == '(' || *cursor == '[')
					left.push(*cursor);
				else if(left.size() > 0 && reverse(*cursor) == left.top())
					left.pop();
				else{
					result = false;
					break;
				}
			}while(*(++cursor) != '\0');
		if(left.size() != 0)result = false;
		puts(result ? "Yes" : "No");
	}
	return 0;
}
