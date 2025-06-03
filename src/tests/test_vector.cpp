#include "../../include/vector.h"
#include <iostream>
#include <string>
#include <stdexcept>

namespace {
	const std::string RED = "\033[1;31m";
	const std::string GREEN = "\033[1;32m";
	const std::string RESET = "\033[0m";

	void print_ok(const std::string& what) {
		std::cout << GREEN << "[+] Ok! " << what << " work(s)" << RESET << std::endl;
	}

	void print_error(const std::string& what, const std::string& error) {
		std::cout << RED << "[!] " << what << " error: " << error << RESET << std::endl;
	}
}

namespace test_vector {
	void base(const std::string& name, auto&& test) {
		bool ok = true;
		try {
			test();
		} catch (std::exception& e) {
			ok = false;
			print_error(name, e.what());
		} if (ok) {
			print_ok(name);
		}
	}

	void default_allocator() {
		base("Default allocator", []() {
			Vector<int> v;
		});
	}

	void sized_allocator() {
		base("Sized allocator", []() {
			for (int i = 1; i < 50; i++) {
				Vector<int> v(i);
				if ((int)v.size() != i) {
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

	void sized_value_allocator() {
		base("Sized + value allocator", []() {
			for (int i = 1; i < 50; i++) {
				Vector<int> v(i, 25 - i);
				if ((int)v.size() != i) {
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

	void random_access() {
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

	void front_back() {
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

	void front_back_const() {
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

	void begin_end() {
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

	void push_back() {
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

	void pop_back() {
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

	void clear() {
		base("clear function", []() {
			Vector<int> v(50);
			v.clear();
			if (!v.empty()) {
				throw std::runtime_error("Vector not empty after clear");
			}
		});
	}

	void resize() {
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

	void reserve() {
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

	void shrink_to_fit() {
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

	void print_vector() {
		base("operator << function", []() {
			Vector<int> v(5);
			std::cout << "should be: ";
			for (int i = 0; i < 5; i++) {
				v[i] = i * 3 + 1;
				std::cout << v[i] << ' ';
			}
			std::cout << " and was: ";
			std::cout << v << '\n';
		});
	}

	void read_vector() {
		base("operator >> function", []() {
			Vector<int> v;
			std::cout << "Enter n (the number of elements), followed by n numbers: ";
			std::cin >> v;
			std::cout << "Read " << v.size() << " numbers\nv: ";
			for (size_t i = 0; i < v.size(); i++) {
				std::cout << v[i] << ' ';
			}
			std::cout << '\n';
		});
	}
}

void test() {
	test_vector::default_allocator();
	test_vector::sized_allocator();
	test_vector::random_access();
	test_vector::sized_value_allocator();
	test_vector::front_back();
	test_vector::front_back_const();
	test_vector::print_vector();
	test_vector::begin_end();
	test_vector::push_back();
	test_vector::pop_back();
	test_vector::clear();
	test_vector::resize();
	test_vector::reserve();
	test_vector::shrink_to_fit();

	// testez push_back()
	Vector<int> v;
	v.push_back(5);
	v.push_back(3);
	std::cout << "front: " << v.front() << std::endl;
	std::cout << "back: " << v.back() << std::endl;
	v.front() = 7;
	std::cout << "new front: " << v.front() << std::endl;

	v.clear();
	test_vector::read_vector();
}
