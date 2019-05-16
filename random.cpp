#include <random>
#include <ctime>
static std::mt19937 mt;
static int getRandomInt(int inicio,int fin){
	mt.seed(time(0));
	std::uniform_int_distribution<int>dist(inicio,fin-1);
	return dist(mt);
}
