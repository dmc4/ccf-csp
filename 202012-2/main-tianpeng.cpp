/*
	CCF-CSP, 202012-2,
	
	   id     sub_time(Beijing)   Language    Result   Score    Time    Space
	2320727, 02-11 17:37,             C++,   Correct,   100,   140ms, 8.410MB
*/

/*
 Ref: https://blog.csdn.net/qq_43464088/article/details/112080044?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
*/

/*                                 | current_threashold == 3
                                   | i==4
                                   V

                  i:   1   2   3   4   5   6    m==6
                     +---+---+---+---+---+---+
sorted            y: | 0 | 1 | 1 | 3 | 5 | 7 |
by y                 +---+---+---+---+---+---+
(threshold)  result: | 0 | 0 | 1 | 1 | 1 | 1 |
                     +---+---+---+---+---+---+
                             <-- | -->
               accurate = zeroes + ones
                       
                     +---+---+---+---+---+---+
prefix[i] =          | 0 | 0 | 1 | 2 | 3 | 4 |
  prefix[i-1] +      +---+---+---+---+---+---+
  result[i]
  
zeroes = i - 1 - prefix(i-1)         ones = prefix[m] - prefix[i-1]

when i==4:	
	zeroes = 4 - 1 - 1 = 2           ones = 4 - 1 = 3
*/

#include<bits/stdc++.h>

using namespace std;


const int M = 1E5 + 1;
pair<int, int> lines[M];
int prefix[M] = {0};
set<int> thresholds;

int main()
{
	int m, i, max_sum = -1, best_threshold;
	
	cin >> m;
	
	for (int i = 1; i <= m; ++ i) {
		cin >> lines[i].first >> lines[i].second;
	}
	
    sort(lines+1, lines+m+1);
	
	for (int i = 1; i <= m; ++ i) {
		prefix[i] = prefix[i-1] + lines[i].second;
	}
	
	for (int i = 1; i <= m; ++ i) {
		int current_threshold = lines[i].first;
		if (0 == thresholds.count(current_threshold)) {	
			thresholds.insert(current_threshold);
			
			int ones = prefix[m] - prefix[i-1];	// >= current_threshold
			int zeroes = i - 1 - prefix[i-1];	// < current_threshold
			int accurate = ones + zeroes;
			if (accurate >= max_sum) {
				max_sum = accurate;
				best_threshold = current_threshold;
			}
		}
	}
	
	cout << best_threshold;
	
	return 0;
}

