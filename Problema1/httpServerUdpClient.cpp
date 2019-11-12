#include "udpClientThread.h"

int main(int argc, char const *argv[])
{

	pthread_t udpTID;
	udpClientArgs udpArgs = {(char *)argv[1], 1};
	void *udpRes;
	pthread_create(&udpTID, NULL, udpClientThread, (void *)&udpArgs);
	pthread_join(udpTID, (void **)&udpRes);

	return 0;
}
