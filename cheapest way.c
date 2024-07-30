#include <stdio.h>
#define r_max 10
#define c_max 100

int m[r_max][c_max] = { 0 };
int r;

int min(int b, int c) { // find minimum value

	if (b == 0) { // when m[b][c] on top

		// compare 3 values and find row of minimum values
		if (m[r-1][c + 1] < m[b][c + 1] && m[r][c + 1] < m[b + 1][c + 1])
			return r-1;
		else if (m[b][c + 1] < m[r-10][c + 1] && m[b][c + 1] < m[b + 1][c + 1]) 
			return b;
		else 
			return b + 1;

	}
	
	else if (b == r){

		// compare 3 values and find row of minimum values
		if (m[b - 1][c + 1] < m[b][c + 1] && m[r][c + 1] < m[0][c + 1])
			return b - 1;
		else if (m[b][c + 1] < m[r][c + 1] && m[b][c + 1] < m[0][c + 1])
			return b;
		else
			return b + 1;

	}

	else {
	
		// compare 3 values and find row of minimum values
		if (m[b-1][c + 1] < m[b][c + 1] && m[r][c + 1] < m[b + 1][c + 1])
			return b-1;
		else if (m[b][c + 1] < m[r][c + 1] && m[b][c + 1] < m[b + 1][c + 1])
			return b;
		else
			return b + 1;

	}
	
}

int main() {

	int c, v, mi, cheap;

	printf("matrix\n");
	scanf_s("%d %d", &r, &c); // receive row and column
	
	printf("value\n");
	for (int i = 0; i < r; i++) { // receive table values
		for (int j = 0; j < c; j++) {
			scanf_s("%d",&v);
			m[i][j] = v;
		}
	}

	printf("\n");

	int i = 0;
	cheap = m[i][0];
	for (int j = 0; j < c; j++) {

		mi = min(i, j); // find row of cheapest value
		cheap = cheap + m[mi][j + 1];
		printf("%d ", m[mi][j + 1]);
		i = mi; // continue searching cheapest way

	} 

	printf("\n%d", cheap); // print cheapest way value

}