#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>

int main()
{
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));

	ser.sin_family=AF_INET;
	ser.sin_port=htons(10000);
	ser.sin_addr.s_addr=INADDR_ANY;

	int sock_id,cli;
	sock_id=socket(AF_INET,SOCK_STREAM,0);

	bind(sock_id,(struct sockaddr*)&ser,sizeof(ser));

	listen(sock_id,1);
	int len=sizeof(ser);
	cli=accept(sock_id,(struct sockaddr*)&ser,&len);

	char a[10],b[10],c[3];
	memset(a,0,10);
	memset(b,0,10);
	memset(c,0,3);
	recv(cli,a,10,0);
	//printf("first no:%s %ld\n",a,strlen(a));
	recv(cli,c,3,0);
	recv(cli,b,10,0);
	int k,l;
	k=atoi(a);
	l=atoi(b);
	printf("%d %d\n",k,l);
	int y;
	char r[20];
	memset(r,0,20);
	int u=0;
	switch(c[0])
	{
		case '+':
			y=k+l;
			break;
		case '-':y=k-l;
			 break;
		case '*':y=k*l;
			 break;
		case '/':y=k/l;
			 break;
		case '%':y=k%l;
			 break;
		default:u=1;
	}
	if(u!=1)
		sprintf(r,"%d",y);
	else strcpy(r,"invalid operation");
	send(cli,r,strlen(r),0);
	close(sock_id);
	return 0;
}

