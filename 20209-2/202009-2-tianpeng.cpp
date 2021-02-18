#include<bits/stdc++.h>

/* in console:
    >type input_1.txt | c2
*/

/* Before sumit, comment printf! */
#define debug /*printf*/

/*  pp    time  bottom_left(x,y)   up_right(x,y) */
int n, k, t,    xl, yd,            xr, yu;

/* Is in the area (including boundary)? */
#define in(x, y) (xl <= x && x <= xr && yd <= y && y <= yu)

int jingguo = 0, douliu = 0;

#define N 20

/* pos(x, y) * t * n lines */
void test(void);

int main()
{	
	/* Read the first line */
	scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
	debug("%d pp, k=%d, %d time, bottom_left=(%d,%d), up_right=(%d,%d)\n",
			  n,     k,    t,    xl, yd,              xr, yu);
	
	test();
	
	/* output result */
	printf("%d\n%d", jingguo, douliu);
	
	return 0;
}

void test(void) {
	/* bucket */
	int b[N] = {0},    i, j,    x, y;
	
	for (i=0; i<n; ++i) {
		int jingguo_flag = 0;
		for (j=0; j<t; ++j) {
			scanf("%d %d", &x, &y);
			debug("%d %d ", x, y);
			
			if (in(x,y)) {	/* in the area */
				jingguo_flag = 1;
				++ b[i];
			} else if (b[i] < k) {
				b[i] = 0;	/* not continually */
			}
		}
		debug("\n");
		
		jingguo += jingguo_flag;
			
		if (k <= b[i]) {
			++ douliu;
		}
	}
}

