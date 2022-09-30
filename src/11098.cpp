#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Information {
	int price;
	std::string name;
	static bool condByPrice(const Information& i1, const Information& i2) {
		return i1.price < i2.price;
	}
};

int main(void) {
	int T; // TestCase
	std::cin >> T;

	std::vector<std::vector<Information>> cases(T);

	for (int i = 0; i < T; i++) {
		int num_of_players;
		std::cin >> num_of_players;
		cases[i].resize(num_of_players);
		for (int j = 0; j < num_of_players; j++) {
			std::cin >> cases[i][j].price;
			std::cin >> cases[i][j].name;
		}

		std::sort(cases[i].begin(), cases[i].end(), &Information::condByPrice);
		std::cout << cases[i].front() << std::endl;
	}

	return 0;
}