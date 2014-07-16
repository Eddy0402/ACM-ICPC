#include <cstdio>
using namespace std;
int Table[1000];
int Hand;
int T, H;
int main()
{
	while (scanf("%d" ,&T) != EOF) {
		for (int i=0; i < T; ++i)
			scanf("%d", &Table[i]);
		scanf("%d", &H);
		int num = 0;
		for (int i=0; i < H; ++i){
			scanf("%d", &Hand);
			Hand = Hand;
			int hh = Hand%13;
			for (int j = 0; j < T; ++j) {
				int tt = Table[j] % 13;
				if (tt == 12) {
					if (Table[j] == Hand+1 || tt == hh)
						num++;
				}
				else if (tt== 0){
					if (Table[j] == Hand-1 || tt == hh)
					num++;
				}
				else {
					if (tt == hh || Table[j] == Hand+1 || Table[j] == Hand-1)
						++num;
				}
				}
			}
			printf("%d\n", num);
		}
	
	return 0;
}