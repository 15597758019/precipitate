int main()
{
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 7;
	int sz = sizeof(arr)/sizeof(arr[0]);
	int left = 0;//���±� 
	int right = sz-1;//���±� 
	while(left <= right)
	{
		int mid;
		mid = (left+right)/2;

		if (k>arr[mid])
		left = mid+1;
		else if(k<arr[mid])
		right = mid-1;
		else 
		{
			printf("�ҵ��ˣ��±���%d\n",mid);
			break;
		}

		if(left>right)
		{
			printf("û�ҵ�");
		}
		
		
	}

 } 
