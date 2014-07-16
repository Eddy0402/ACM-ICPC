#include<iostream>
#include<sstream>
#include<strstream>
using namespace std;
stringstream sout;
char input[5000000];
class Node{
	public:
		Node *Left, *Right;
		int value;
		Node() : value(-1), Left(NULL), Right(NULL){ }
		Node *getNewLeft (){return (Left  = new Node()); }
		Node *getNewRight(){return (Right = new Node()); }
};
int read(Node *current,int JumpUp,istrstream &sin){
	int newValue,JumpHere = -1;
	if(!(sin >> newValue))return -1;
	if(newValue > JumpUp){
		return newValue;
	}else if(newValue < current -> value){
		current -> getNewLeft() -> value = newValue;
		JumpHere = read(current -> Left, current -> value,sin);
		if(JumpHere > JumpUp)return JumpHere;
	}else{
		current -> getNewRight() -> value = newValue;
		JumpHere = read(current -> Right, JumpUp, sin);
		if(JumpHere > JumpUp)return JumpHere;
	}
	if(JumpHere != -1){
		current -> getNewRight() -> value = JumpHere;
		JumpHere = read(current -> Right, JumpUp,sin);
		if(JumpHere > JumpUp) return JumpHere;
	}
	return -1;
}
void print(Node *current){
	if(current -> Left != NULL)
		print(current -> Left);
	if(current -> Right != NULL)
		print(current -> Right);
	sout << current -> value << "\n";
}
int main(void){
	ios::sync_with_stdio(false);
	cin.read(input,4999999);
    istrstream sin(input);

	Node Root;
	sin >> Root.value;
	read(&Root,2147483647,sin);
	print(&Root);

	sout.flush();
	cout << sout.rdbuf();
	return 0;
}
