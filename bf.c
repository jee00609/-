#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
void init_table(int table[], int size);

int main(void)
{
	int table[SIZE];
	int n, data;
	long pos;
	FILE *fp = NULL;
	
// �迭�� �ʱ�ȭ�Ѵ�.
	init_table(table, SIZE);

// ���� ������ ���� ���� ����.
	if( (fp = fopen("sample.dat", "wb")) == NULL )
	{
		fprintf(stderr,"����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

// �迭�� ���� ���� ���Ͽ� �����Ѵ�.
	fwrite(table, sizeof(int), SIZE, fp);
	fclose(fp);

// ���� ������ �б� ���� ����.
	if( (fp = fopen("sample.dat", "rb")) == NULL )
	{
		fprintf(stderr,"�Է��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

// ����ڰ� ������ ��ġ�� ������ ���Ϸκ��� �д´�.
	while(1)
	{	
	     printf("���Ͽ����� ��ġ�� �Է��Ͻʽÿ�(0���� %d, ����-1): ", SIZE - 1);
	     scanf("%d", &n);
	     
		 if( n == -1 ) 
			 break;
	     
		 pos = (long) n * sizeof(int);
	     
		 fseek(fp, pos, SEEK_SET);
	     
		 fread(&data, sizeof(int), 1, fp);
	     
		 printf("%d ��ġ�� ���� %d�Դϴ�.\n", n, data);

		 fseek(fp,4L, SEEK_CUR);
		 
		 fread(&data, sizeof(int), 1, fp);

		 printf("%d ��ġ�� �ٴ�����(%d)�� %d�Դϴ�.\n", n,n+2,data);

	}


	fclose(fp);
	
	
	return 0;
} 

// �迭�� �ε����� �������� ä���.
void init_table(int table[], int size)
{
	int i;

	for(i = 0; i < size; i++)
		table[i] = i * i;
}