#include<cstdio>

using namespace std;

#define R 504 // 8 * 63
#define C 100 // 10 * 10

struct Node {
	Node *up, *down ,*left, *right,*r2;
	Node *colRoot;
	int row; 
	int sum;
	int x,y;
};

class Dlx{
	public:
		Node *nodes,*row,*col,*head;
		int rowNum,colNum,nodeCount;
		int *result,resultCount;
		Dlx(){
			nodes=new Node[R*C];
			row=new Node[R];
			col=new Node[C+1];
			result=new int[R];
			rowNum=R;
			colNum=C;
			for(int i=0;i<=colNum;++i){
				col[i].up=col[i].down=col+i;
				col[i].left=col + (i+colNum)%(1+colNum);
				col[i].right=col + (i+1)%(1+colNum);
				col[i].sum=0;
			}
			head=col+colNum;
			for(int i=0;i<rowNum;++i){
				row[i].up=row[i].down=row[i].left=row[i].right=row[i].colRoot=row+i;
			}
			nodeCount=0;
		}
		~Dlx()
		{
			delete []nodes;
			delete []row;
			delete []col;
			delete []result;
		}
		void cover(Node *t);
		void uncover(Node *t);
		void solve(int k=0);
		void addNode(int r,int x,int y);
};
void Dlx::addNode(int r,int x,int y)
{
	nodes[nodeCount].x = x;
	nodes[nodeCount].y = y;
	int c = x * 10 + y;
	nodes[nodeCount].up=col[c].up;
	nodes[nodeCount].down=col+c;
	nodes[nodeCount].left=row[r].left;
	nodes[nodeCount].right=row+r;
	nodes[nodeCount].r2=row+r;
	nodes[nodeCount].row=r;
	nodes[nodeCount].colRoot=col+c;
	col[c].up=col[c].up->down=row[r].left=row[r].left->right=row[r].left->r2=nodes+nodeCount++;	
	col[c].sum++;
}

void Dlx::cover(Node *t){
	Node *p,*q;
	t->left->right=t->right;
	t->right->left=t->left;
	for(p=t->down;p!=t;p=p->down){
		for(q=p->right;q!=p;q=q->right)	{
			q->up->down=q->down;
			q->down->up=q->up;
			q->colRoot->sum--;
		}
	}	
}

void Dlx::uncover(Node *t){
	Node *p,*q;
	for(p=t->up;p!=t;p=p->up){
		for(q=p->left;q!=p;q=q->left){
			q->up->down=q->down->up=q;
			q->colRoot->sum++;
		}
	}
	t->left->right=t->right->left=t;
}

int Table[10][10];
int CCC = 0;
void Dlx::solve(int k){
	if(head->right==head){
		++CCC;
		resultCount=k;
			printf("{");
		for(int i = 0;i < k;++i){
			Node *temp = &row[result[i]];
			printf("{");
			for(int p = 0;p < 5;++p){
				temp = temp -> r2;
				printf("{%d,%d}",temp -> x,temp -> y);
				if(p != 4)printf(",");
			}
			printf("}");
			if(k != 19)printf(",\n");
		}
			printf("},");/*
		for(int i = 0;i < k;++i){
			Node *temp = &row[result[i]];
			for(int p = 0;p < 5;++p){
				temp = temp -> r2;
				Table[temp -> x][temp -> y] = i;
			}
		}
		for(int i = 0;i < 10;++i){
			for(int j = 0;j < 10;++j){
				printf("%2d ",Table[i][j]);
			}
			puts("");
		}*/
		puts("");
		return;
	}
	Node *pMin,*p,*q;
	for(pMin=head->right,p=pMin->right;p!=head;p=p->right){
		if(pMin->sum>p->sum)
			pMin=p;
	}
	cover(pMin);
	for(p=pMin->down;p!=pMin;p=p->down){
		result[k]=p->row;
		for(q=p->right;q!=p;q=q->right)
			cover(q->colRoot);
		solve(k+1);
		for(q=p->left;q!=p;q=q->left)
			uncover(q->colRoot);
	}
	uncover(pMin);
}
int main(){
	Dlx dlx;
	int count = 0;
	int start[8][5][2] = {
		{{0,0},{0,1},{0,2},{0,3},{1,1}},
		{{0,0},{0,1},{0,2},{0,3},{1,2}},
		{{1,0},{2,0},{3,0},{0,0},{1,1}},
		{{1,0},{2,0},{3,0},{0,0},{2,1}},
		{{1,0},{1,1},{1,2},{0,2},{1,3}},
		{{1,0},{1,1},{1,2},{0,1},{1,3}},
		{{0,1},{1,1},{2,1},{3,1},{1,0}},
		{{0,1},{1,1},{2,1},{3,1},{2,0}}
		};

	for(int t = 0;t < 8;++t){
		for(int i = 0;i < 10;++i){
			for(int j = 0;j < 10;++j){
				bool yes = true;
				for(int p = 0;p < 5;++p){
					if(start[t][p][0] + i >= 10){yes = false;break;}
					if(start[t][p][1] + j >= 10){yes = false;break;}
				}
				if(yes){
					for(int p = 0;p < 5;++p){
						dlx.addNode(count,start[t][p][0] + i,start[t][p][1] + j);
					}
					++count;
				}
			}
		}
	}
	dlx.solve();
	printf("%d\n",CCC);
	return 0;
}
