#include<stdio.h>

void main()
{
	int qpag = 0;
	scanf("%d",&qpag);
	int totmin = qpag / 5;
	int resto = qpag % 5;
	int qhor = totmin / 60;
	int qmin = totmin - (60*qhor);
	int qseg = (resto * 60)/5;
	printf("%d\n",qhor);
	printf("%d\n",qmin);
	printf("%d\n",qseg);
}

