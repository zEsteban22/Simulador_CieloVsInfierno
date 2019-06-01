#include"randomxd.h"
static std::mt19937 mt(time(0));
int getRandomInt(int inicio,int fin){
	std::uniform_int_distribution<int>dist(inicio,fin-1);
	return dist(mt);
}
