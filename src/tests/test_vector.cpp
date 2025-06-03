#include "../../include/vector.h"
#include <iostream>
#include <string>
#include <stdexcept>

#include "base_test.h"

class TestVector : public BaseTest {
	static void default_allocator() {
		base("Default allocator", []() {
			Vector<int> v;
		});
	}

	static void sized_allocator() {
		base("Sized allocator", []() {
			for (int i = 1; i < 50; i++) {
				Vector<int> v(i);
				if (static_cast<int>(v.size()) != i) {
					throw std::runtime_error("Incorrect size after allocation");
				}
				for (int j = 0; j < i; j++) {
					if (v[j] != 0) {
						throw std::runtime_error("Incorrect default value");
					}
				}
			}
		});
	}

	static void sized_value_allocator() {
		base("Sized + value allocator", []() {
			for (int i = 1; i < 50; i++) {
				Vector<int> v(i, 25 - i);
				if (static_cast<int>(v.size()) != i) {
					throw std::runtime_error("Incorrect size after allocation");
				}
				for (int j = 0; j < i; j++) {
					if (v[j] != 25 - i) {
						throw std::runtime_error("Incorrect value set");
					}
				}
			}
		});
	}

	static void random_access() {
		base("Random access []", []() {
			Vector<int> v(4);
			v[0] = 3;
			v[1] = 4;
			v[2] = 2;
			v[3] = 1;

			if (v[0] != 3 || v[1] != 4 || v[2] != 2 || v[3] != 1) {
				throw std::runtime_error("Incorrect value (set / get)");
			}
		});
	}

	static void front_back() {
		base("Front and back access", []() {
			Vector<int> v(5);

			v[0] = 3;
			if (v.front() != 3) {
				throw std::runtime_error("Incorrect get on front");
			}

			v.front() = 7;
			if (v[0] != 7) {
				throw std::runtime_error("Incorrect set on front");
			}

			v[v.size() - 1] = 5;
			if (v.back() != 5) {
				throw std::runtime_error("Incorrect get on back");
			}

			v.back() = 4;
			if (v[v.size() - 1] != 4) {
				throw std::runtime_error("Incorrect set on back");
			}
		});
	}

	static void front_back_const() {
		base("Const front and back access", []() {
			const Vector<int> v(5, 3);

			if (v.front() != 3) {
				throw std::runtime_error("Incorrect get on const front");
			}

			if (v.back() != 3) {
				throw std::runtime_error("Incorrect get on const back");
			}
		});
	}

	static void begin_end() {
		base("Begin and end iterators", []() {
			Vector<int> v(100);
			int cnt = 0;
			for (int* it = v.begin(); it != v.end(); it++) {
				cnt++;
				if (cnt > 100) { break; }
			}
			if (cnt != 100) {
				throw std::runtime_error("Incorrect number of steps");
			}
		});
	}

	static void push_back() {
		base("push_back function", []() {
			Vector<int> v;
			for (int i = 0; i < 15; i++) {
				v.push_back(3 * i - 5);
				if ((int)v.size() != i + 1) {
					throw std::runtime_error("Incorrect size after push_back");
				}
			}

			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i] != 3 * i - 5) {
					throw std::runtime_error("Incorrect value after push_back");
				}
			}
		});
	}

	static void pop_back() {
		base("pop_back function", []() {
			Vector<int> v(50);
			for (int i = 0; i < 15; i++) {
				v.pop_back();
				if ((int)v.size() != (50 - i - 1)) {
					throw std::runtime_error("Incorrect size after pop_back");
				}
			}
		});
	}

	static void clear() {
		base("clear function", []() {
			Vector<int> v(50);
			v.clear();
			if (!v.empty()) {
				throw std::runtime_error("Vector not empty after clear");
			}
		});
	}

	static void resize() {
		base("resize function", []() {
			Vector<int> v;
			v.resize(5, 3);
			if (v.size() != 5) {
				throw std::runtime_error("Incorrect size after resize");
			}
			for (size_t i = 0; i < v.size(); i++) {
				if (v[i] != 3) {
					throw std::runtime_error("Incorrect value after resize");
				}
			}

			v.resize(10, 2);
			if (v.size() != 10) {
				throw std::runtime_error("Incorrect size after resize");
			}
			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i] != 3 - i / 5) {
					throw std::runtime_error("Incorrect value after resize");
				}
			}

			v.resize(7, 9);
			if (v.size() != 7) {
				throw std::runtime_error("Incorrect size after resize");
			}
			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i] != 3 - i / 5) {
					throw std::runtime_error("Incorrect value after resize");
				}
			}
		});
	}

	static void reserve() {
		base("reserve function", []() {
			Vector<int> v(5);
			for (int i = 0; i < (int)v.size(); i++) {
				v[i] = -i - 1;
			}

			int old_cap = v.capacity();
			v.reserve(3);
			if (old_cap != (int)v.capacity()) {
				throw std::runtime_error("Capacity decreased in reserve");
			}

			v.reserve(17);
			if (v.capacity() != 17) {
				throw std::runtime_error("Incorrect capacity after reserve");
			}
			if (v.size() != 5) {
				throw std::runtime_error("Incorrect size after reserve");
			}

			for (int i = 0; i < (int)v.size(); i++) {
				if (v[i] != -i - 1) {
					throw std::runtime_error("Incorrect value after reserve");
				}
			}
		});
	}

	static void shrink_to_fit() {
		base("shrink_to_fit function", []() {
			Vector<int> v;
			v.push_back(5);
			v.reserve(14);
			v.shrink_to_fit();
			if (v.size() != v.capacity()) {
				throw std::runtime_error("Incorrect size after shrink_to_fit");
			} else if (v.capacity() != v.size()) {
				throw std::runtime_error("Incorrect capacity after shrink_to_fit");
			}
		});
	}

	static void print_vector() {
		base("operator << function", []() {
			Vector<int> v(5);
			std::stringstream ss;
			for (int i = 0; i < 5; i++) {
				v[i] = i * 3 + 1;
			}
			ss << v;
			if (ss.str() != "1 4 7 10 13 ") {
				throw std::runtime_error("Incorrect output from operator <<");
			}
		});
	}

	static void read_vector() {
		base("operator >> function", []() {
			Vector<int> v;
			std::stringstream ss("5\n1 2 3 4 5");
			ss >> v;
			if (v.size() != 5) {
				throw std::runtime_error("Incorrect size after read");
			}
			for (int i = 0; i < 5; i++) {
				if (v[i] != i + 1) {
					throw std::runtime_error("Incorrect value after read");
				}
			}
		});
	}

public:
	static void test_all() {
		default_allocator();
		sized_allocator();
		random_access();
		sized_value_allocator();
		front_back();
		front_back_const();
		print_vector();
		begin_end();
		push_back();
		pop_back();
		clear();
		resize();
		reserve();
		shrink_to_fit();

		print_vector();
		read_vector();
	}
};
