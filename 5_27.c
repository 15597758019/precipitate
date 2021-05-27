int main()
{
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 7;
	int sz = sizeof(arr)/sizeof(arr[0]);
	int left = 0;//左下标 
	int right = sz-1;//又下标 
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
			printf("找到了，下标是%d\n",mid);
			break;
		}

		if(left>right)
		{
			printf("没找到");
		}
		
		
	}

 } 
