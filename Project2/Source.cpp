//Для класса Apple описанного ранее добавить нужные конструктора и деструктора.
#include <iostream>
class Apple {
public:
	Apple() {
		this->massa = 0.0f;
		this->num_of_seeds = 0;
		strcpy_s(this->color, "0\0");
		strcpy_s(this->ripeness, "0\0");
	}
	Apple(float massa, int num_of_seeds) {
		this->massa = massa;
		this->num_of_seeds = num_of_seeds;
		strcpy_s(this->color, "0\0");
		strcpy_s(this->ripeness, "0\0");
	}
	Apple(Apple& test) {
		this->massa = test.get_massa();
		this->num_of_seeds = test.get_seeds();
		strcpy_s(this->color, test.get_color());
		strcpy_s(this->ripeness, test.get_ripeness());
	}
	int get_growth() {
		return this->growth;
	}
	void set_growth(int _growth) {
		this->growth = _growth;
	}
	int get_massa() {
		return this->massa;
	}
	void set_massa(float _massa)
	{
		this->massa = _massa;
	}
	int get_seeds() {
		return this->num_of_seeds;
	}
	const char* get_color() {
		return this->color;
	}
	const char* get_ripeness() {
		return this->ripeness;
	}
	void set_seeds(int _num_of_seeds)
	{
		this->num_of_seeds = _num_of_seeds;
	}
	void show_inform() {
		std::cout << "massa = " << this->massa << "\nnumber of seeds = " << this->num_of_seeds << "\ncolor: " << this->color << "\nripeness: " << this->ripeness << "\n";
	}
	void enter_apple() {
		std::cout << "enter mas: ";
		float _massa;
		std::cin >> _massa;
		set_massa(_massa);
		std::cout << "enter number of seeds: ";
		int seeeds;
		std::cin >> seeeds;
		set_seeds(seeeds);
		std::cout << "enter apple growth(growth change occurs from 1 to 3): ";
		int growing_apple;
		std::cin >> growing_apple;
		set_growth(growing_apple);
		switch (get_growth()) {
		case 1:
			strcpy_s(this->color, "green\0");
			strcpy_s(this->ripeness, "not ripe\0");
			break;
		case 2:
			strcpy_s(this->color, "red\0");
			strcpy_s(this->ripeness, "ripe\0");
			break;
		case 3:
			strcpy_s(this->color, "brown\0");
			strcpy_s(this->ripeness, "rotten\0");
			break;
		default:
			std::cout << "error.\n";
			break;
		}
		system("pause");
		system("cls");
	}
private:
	float massa;
	int num_of_seeds;
	char color[30];
	int growth;
	char ripeness[30];
};

int main()
{
	Apple test(2.3, 4);
	test.show_inform();
	test.enter_apple();
	test.show_inform();
	Apple test2(test);
	std::cout << "copy:\n";
	test2.show_inform();
}