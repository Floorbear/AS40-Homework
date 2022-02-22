#include <iostream>





int main() {
	int arry[9] = {14,2,5,29,123,5,9,3,9 };

	for (int i = 0; i < 8; i++) //n-1까지
	{
		for (int j = 0; j < (9 - i - 1);j++) //n-1-i
		{			
			if (arry[j] > arry[j + 1])
			{
				int temp = arry[j + 1];
				arry[j + 1] = arry[j];
				arry[j] = temp;
			}
		}
	}


	return 0;
}

