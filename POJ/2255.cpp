#include<iostream>
#include<stack>
using namespace std;
void postOrder(string preOrder,string inOrder){
	if(preOrder.size() > 1){
		int find = inOrder.find(preOrder[0]);
		postOrder(string(preOrder,1,find) , string(inOrder,0,find));
		postOrder(string(preOrder,find + 1,preOrder.size() - find ), string(inOrder,find + 1,inOrder.size() - find ));
	}
	if( preOrder.size() )cout << preOrder[0];
}
int main(){
	string preOrder,inOrder;
	while(cin >> preOrder >> inOrder){
		postOrder(preOrder,inOrder);
		cout << "\n";
	}
	cout.flush();
	return 0;
}
