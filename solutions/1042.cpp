#include<cstdio>
//S = 83, D = 68, H = 72, C = 67, J = 74
#define MAX 55
typedef struct Card {
	char Ch;
	char ID;
} card;
card Cards[MAX];
int standard[MAX];
void print (card car)
{
	printf("%c%d", car.Ch, car.ID);
}
void display(card * car)
{
	print(car[1]);
	for(int i = 2; i<=54; i++) {
		printf(" ");
		print(car[i]);
	}
}
void init(char ch, int begin, int end)
{
	int j = 1;
	for(int i = begin; i<=end; i++) {
		Cards[i].Ch = ch;
		Cards[i].ID = j++;
	}
}
int main()
{
	init('S', 1,  13);
	init('H', 14, 26);
	init('C', 27, 39);
	init('D', 40, 52);
	Cards[53].Ch = Cards[54].Ch = 'J';
	Cards[53].ID = 1;
	Cards[54].ID = 2;
	int roll;
	scanf("%d", &roll);
	card * new_ = new card[55];
	card * out_ = new card[55];
	for(int i = 1; i<=54; i++)
		scanf("%d", &standard[i]);
	for(int i = 1; i<=54; i++)
		new_[i] = Cards[i];

	while(roll--) {
		for(int i = 1; i<=54; i++) {
			out_[standard[i]] = new_[i];
		}
		card * temp = new_;
		new_ = out_;
		out_ = temp;
	}
	display(new_);
	return 0;
}
