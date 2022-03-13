#include <iostream>
//브루트 포스는 완전탐색이라고 할수 있는데, 보통 깊이우선탐색과 너비우선탐색이 존재한다.
using namespace std;
int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;

	while (1)
	{
		if (e == s && s == m)
		{
			break;
		}
		if (e <= s)
		{
			if (e <= m)
			{
				e = e + 15;
				continue;
			}

			else
			{
				m = m + 19;
				continue;
			}
		}
		else if (s <= e)
		{
			if (s <= m)
			{
				s = s + 28;
			}
			else
			{
				m = m + 19;
			}
		}
	}
	cout << e;
	return 0;
}