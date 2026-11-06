#include <iostream>

//typedef unsigned int uint32;

struct Player {
	int health;
	int level;
	char nickname[20];
};

void savePlayer(const Player& player) {
	FILE* file = nullptr;
	if (!fopen_s(&file, "player.txt", "w"))
	{
		fprintf_s(file, "health: %d\nlevel: %d\nnickname: %s", player.health, player.level, player.nickname);
		fclose(file);
	}
}

void readPlayer(Player& player) {
	FILE* file = nullptr;
	if (!fopen_s(&file, "player.txt", "r"))
	{
		fscanf_s(file, "health: %d\nlevel: %d\nnickname: %s", &player.health, &player.level, player.nickname, 20);
		fclose(file);
	}
}

int main()
{
	Player p{ 100, 4, "anton" };

	savePlayer(p);

	Player load;
	readPlayer(load);

	std::cout << load.health << '\n';
	std::cout << load.level << '\n';
	std::cout << load.nickname << '\n';

	//FILE* file = nullptr;

	//errno_t res = fopen_s(&file, "test.txt", "r");

	//if (res) {
	// std::cout << "Error opening file\n";
	//}
	//else {

	// while (!feof(file))
	// {
	//  int i = 0;
	//  double d = 0.0;

	//  fscanf_s(file, "integer: %d, double: %lf\n", &i, &d);

	//  std::cout << i << ' ' << d;
	// }

	// //char text[] = "some text to write";
	// ////fwrite(text, sizeof(char), strlen(text), file);

	// //fprintf_s(file, "integer: %d, double: %.2f", 23, 34.567);

	// //fclose(file);
	//}



}