#include <stdio.h>
#include <stdlib.h>
int main()
{
	int p,r;
	printf("Enter no. of Processes: ");
	scanf("%d",&p);
	printf("Enter no. of Resources: ");
	scanf("%d",&r);
    int max_alloc[p][r],curr_alloc[p][r],curr_avail[p+1][r+1],max_need[p][r],i,j,temp[r],max_res[r],free[r],safe_seq[p],traversed[p],process = 0,l,accepted,safe,k;
    printf("---MAX ALLOCATION---\n");
    for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
			scanf("%d",&max_alloc[i][j]);
		traversed[i] = 0;
	}
	printf("---CURRENT ALLOCATION---\n");
    for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&curr_alloc[i][j]);
	printf("---RESOURCES PRESENT---\n");
	for(i=0;i<r;i++)
		scanf("%d",&max_res[i]);
	printf("---MAX NEED---\n");
    for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			max_need[i][j] = max_alloc[i][j] - curr_alloc[i][j];
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
			printf("%d ",max_need[i][j]);
		printf("\n");
	}
	for(j=0;j<r;j++)
	{
		temp[j] = 0;
		for(i=0;i<p;i++)
		{
			temp[j] += curr_alloc[i][j];
		}
	}
	for(j=0;j<r;j++)
		free[j] = max_res[j] - temp[j];
	for(i=0;i<p;i++)
	{
		safe_seq[i] = -1;
		accepted = 0;
		j = 0;
		while(accepted != 1 && j<p)
		{
			safe = 1;
			for(k =0 ;k < r; k++)
				if((free[k] - max_need[j][k]) < 0)
					safe = 0;
			if(safe == 1 && traversed[j] == 0)
			{
				safe_seq[i] = j;
				accepted = 1;
				traversed[j] =1;
				process++;
				for(l = 0;l < r;l++)
					free[l] += curr_alloc[j][l];
			}
			else
				j++;
		}
	}
	printf("\n");
	if(process < p)
		printf(".....No safe sequence is possible.....");
	else
	{
		for(i = 0;i < p;i++)
			printf("P%d ",safe_seq[i]);
	}
	return 0;
}

