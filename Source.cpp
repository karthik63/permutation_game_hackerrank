#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int dp[32768]; int n;

int perms(int nums[20], int config, int player)
{
	register int i;

	if (dp[config] != -1)
	{
		return dp[config];
	}

	int flag1 = 0, flag2=0, temp1 = -1, temp2;

	for (i = 0; i < n; i++)
	{
		if ((1 << i)&config)
		{
			if (nums[i] >= temp1)
			{
				temp1 = nums[i]; flag2++;
			}
			else
			{
				flag2++; flag1 = 1; break;
			}
		}
	}

	if (flag1 == 0||flag2 == 1)
	{
		dp[config] = abs(player - 1);
		return abs(player - 1);
	}

	int ans1 = abs(player-1), ans2;

	for (i = 0; i < n; i++)
	{
		if ((1 << i)&config)
		{
			int temp = config&(~(1 << i));
			
			ans1 = perms(nums, temp, abs(player - 1));
		}

		if (ans1 == player)
			break;
	}

	if (ans1 == player)
	{
		dp[config] = player;
		return player;
	}
	else
	{
		dp[config] = abs(player - 1);
		return abs(player - 1);
	}
}

int main()
{
	register int ii; int  t;
	
	cin >> t;

	for (ii = 0; ii < t; ii++)
	{
		int ans;
		register int i;
		
		for (i = 0; i < 32768; i++)
			dp[i] = -1;

		cin >> n;	int nums[20];

		for (i = 0; i < n; i++)
		{
			cin >> nums[i];
		}

		ans = perms(nums, (1<<n)-1, 1);

		if (ans == 1)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
}