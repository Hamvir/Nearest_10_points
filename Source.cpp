#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>
using namespace std;
int main()
{
	float** array = new float*[1000000];
	cout << "Wait for few seconds as database is being created"<<endl;
	for (int i = 0; i < 1000000; i++)
	{
		array[i] = new float[100];
		for (int j = 0; j < 100; j++)
		{
			int temp = rand();
			if (temp > 0)
				temp = temp % 100;
			else
				temp = -1 * ((-1 * temp) % 100);
			array[i][j] = temp;
			//cout << i << " " << j << " " << array[i][j];
		}
	}
	cout << "Number of queries u want to ask??" << endl;
	int x;
	cin >> x;
	int i = 1;
	float nearest[10];
	int index[10];

	for (int j = 0; j <=9; j++)
	{
		index[j]=0;
		nearest[j] = -1;
	}
		

	
	cout << "if you want to manually enter query press 1 else if u want query to be randomly generated press 0" << endl;
	int flag;
	cin >> flag;

	while(i<=x)
	{ 
		float brr[100];
		if (flag == 1)
		{
			cout << "Ask a query consisting of 100 points" << endl;
			for (int j = 0; j < 100; j++)
			{
				cin >> brr[j];
				
			}
		}
		else
		{
			
			for (int j = 0; j < 100; j++)
			{
				brr[j] = rand();
			}
		}
		// add timing
		auto time1 = chrono::high_resolution_clock::now();
		for (int j = 0; j < 1000000; j++)
		{
			float sum = 0;
			for (int k = 0; k < 100; k++)
			{
				sum = sum + (array[j][k] - brr[k]) * (array[j][k] - brr[k]);
				if (j > 9 && sum > nearest[9])
					break;


			}
			//sum = sqrt(sum);

			if (nearest[9] > sum || nearest[9]==-1)
			{
				nearest[9] = sum;
				index[9] = j;
				for (int k = 8; k >= 0; k--)
				{
					if (nearest[k] > sum || nearest[k]==-1)
					{
						nearest[k + 1] = nearest[k];
						index[k + 1] = index[k];
						nearest[k] = sum;
						index[k] = j;
					}
					else break;
				}
			}
			
		}
		auto time2 = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::milliseconds>(time2 - time1);
		cout <<" i number query takes "<< duration.count() << " milli second(ms)" << endl;
		cout << "10 nearest neighbour to "<< i<<"number query are : " << endl;
		for (int j = 0; j < 10; j++)
		{
			//cout << nearest[j] << endl;
			cout << index[j];
			for (int k = 0; k < 100; k++)
			{
				cout << array[index[j]][k] << " ";
			}
			cout << endl;
		}

		i++;
	}
	
	delete[] array;
	return 0;
}