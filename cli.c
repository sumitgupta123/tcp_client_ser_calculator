#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int main()
{
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));

	ser.sin_family=AF_INET;
	ser.sin_port=htons(10000);
	ser.sin_addr.s_addr=INADDR_ANY;

	int sock_id=socket(AF_INET,SOCK_STREAM,0);

	connect(sock_id,(struct sockaddr*)&ser,sizeof(ser));

	char a[10],b[10],c[3];

	printf("first no:");
	scanf("%s",a);
	send(sock_id,a,strlen(a),0);
	printf("enter the operator:");
	scanf("%s",c);
	send(sock_id,c,strlen(c),0);
	printf("second no:");
	scanf("%s",b);
	//send(sock_id,a,strlen(a),0);
	//send(sock_id,c,strlen(c),0);
	send(sock_id,b,strlen(b),0);

	char d[20];
	memset(d,0,20);
	recv(sock_id,d,20,0);

	printf("result is: %s\n",d);

	close(sock_id);
	return 0;
}

