#include <string>
#include <fstream>
#include <limits>
#include "../Vector/Vector.h"

template <class T>
void test (Vector<T>&);

template <class T>
void test_access_operator(Vector<T>&);

template <class T>
void test_insert_at_beginning(Vector<T>&);

template <class T>
void test_insert_at_index(Vector<T>&);

template <class T>
void test_delete_single_element(Vector<T>&);

template <class T>
void test_delete_range_of_elements(Vector<T>&);

template <class T>
void test_read_write(Vector<T>&);

template <class T>
void test_assignment(Vector<T>&);

template <class T>
void test_append(Vector<T>&);

template <class T>
void test_delete_initial(Vector<T>&);

int main() {
	char selection;
	int offset;
	std::string tabline = "\n   ";

	std::cout
		<< " *** Exhaustive CISP 400 Vector Test Suite ***" << std::endl
		<< "  *             By: Joseph Morgan           * " << std::endl << std::endl
		<< "Select type of Vector. Options:" << tabline
		<< "[c] - char" << tabline
		<< "[i] - int" << tabline
		<< "[d] - double"
		<< std::endl
		<< "Make a selection: ";
	std::cin >> selection;

	std::cout << "If you would like to use a virtual index, enter it here. For no virtual index, enter zero. " << std::endl
		<< "Virtual Index: ";
	std::cin >> offset;

	switch (selection) {
		case 'c' : {
			Vector<char> container(offset);
			test(container);
			break;
		}
		case 'i' : {
			Vector<int> container(offset);
			test(container);
			break;
		}
		case 'd' : {
			Vector<double> container(offset);
			test(container);
			break;
		}
		default : std::cout << "Invalid selection" << std::endl;
	}

	return 0;
}

template <class T>
void test (Vector<T>& vec) {
	T* array = new T[80];
	T temp;
	std::string tabline = "\n    ";
	char selection;
	bool stop = false;

	std::cout << "Enter values to fill Vector, enter -1 or q to deliminate: ";

	std::cin >> temp;
	for(int i = 0; temp != -1 && temp != 'q'; i++) {
		vec += temp;
		std::cin >> temp;
	}

	std::cout << vec << std::endl;
	Vector<T>* vec_ptr = &vec;
	std::cout << vec_ptr << std::endl;
	std::cout << "Length: " << vec.Length() << std::endl;

	while (!stop) {
		std::cout << "Testing suite assumes that your Vector class follows the interface outlined in the assignment."
			<< "If you encounter errors, make sure function delcarations match those on d2l." << std::endl
			<< "Please select the member function that you'd like to test." << tabline
			<< "[a] - Test access operator: Vector<T>.operator[]" << tabline
			<< "[b] - Test insert at beginning: Vector<T>.Insert(const T&)" << tabline
			<< "[c] - Test insert at index: Vector<T>.Insert(const T&, int )" << tabline
			<< "[d] - Test delete single element: Vector<T>.Delete(const int)" << tabline
			<< "[e] - Test delete range of elements: Vector<T>.Delete(int, int)" << tabline
			<< "[f] - Test write/read operation: Vector<T>.Write(std::ofstream&) Vector<T>.Read(std::ifstream&)" << tabline
			<< "[g] - Test assignment operator: Vector<T>.operator=(const Vector&)" << tabline
			<< "[h] - Test append vector operator: Vector<T>.operator+=(const Vector&)" << tabline
			<< "[i] - Test delete initial element: Vector<T>.delete()" << tabline
			<< "[q] - Quit" << tabline
			<< "[z] - Test all functions" << std::endl;
		std::cout << std::endl << "Please make a selection: ";

		std::cin >> selection;

		switch (selection) {
			case 'a' : {
				test_access_operator(vec);
				break;
			}

			case 'b' : {
				test_insert_at_beginning(vec);
				break;
			}

			case 'c' : {
				test_insert_at_index(vec);
				break;
			}

			case 'd' : {
				test_delete_single_element(vec);
				break;
			}

			case 'e' : {
				test_delete_range_of_elements(vec);
				break;
			}

			case 'f' : {
				test_read_write(vec);
				break;
			}

			case 'g' : {
				test_assignment(vec);
			}

			case 'h' : {
				test_append(vec);
			}

			case 'i' : {
				test_delete_initial(vec);
			}

			case 'q' : {
				stop = true;
				break;
			}

			case 'z' : {
				test_access_operator(vec);
				test_insert_at_beginning(vec);
				test_insert_at_index(vec);
				test_delete_single_element(vec);
				test_delete_range_of_elements(vec);
				test_delete_initial(vec);
				test_append(vec);
				test_assignment(vec);
				test_read_write(vec);
				break;
			}

			default : {
				std::cout << "Invalid input" << std::endl;
			}
		}
	}
}

template <class T>
void test_access_operator(Vector<T>& vec) {
	bool stop = false;
	char input;
	int index;

	while (!stop) {
		std::cout << "Input an index to get the element at that index of your vector: ";
		std::cin >> index;

		try {
			std::cout << vec[index] << std::endl;
		} catch (int i) {
			std::cerr << "Error: Thrown - " << i << std::endl;
		}

		std::cout << "Length: " << vec.Length() << std::endl;
		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_insert_at_beginning(Vector<T>& vec) {
	bool stop = false;
	char input;
	T temp;
	Vector<T>* vec_ptr;

	while (!stop) {
		std::cout << "Enter values to insert into beginning of existing Vector, enter -1 or q to deliminate: ";
		std::cin >> temp;

		while(temp != -1 && temp != 'q') {
			vec.Insert(temp);
			std::cin >> temp;
		}

		std::cout << vec << std::endl;
		vec_ptr = &vec;
		std::cout << vec_ptr << std::endl;
		std::cout << "Length: " << vec.Length() << std::endl;
		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_insert_at_index(Vector<T>& vec) {
	bool stop = false;
	T temp;
	unsigned index;
	Vector<T>* vec_ptr;
	char input;

	while (!stop) {
		try {
			std::cout << "Input a single value to insert into index: ";
			std::cin >> temp;
			std::cout << std::endl;
			std::cout << "Input the index that you'd like to insert it at: ";
			std::cin >> index;
			std::cout << std::endl;
			vec.Insert(temp, index);
			std::cout << vec << std::endl;
			vec_ptr = &vec;
			std::cout << vec_ptr << std::endl;
			std::cout << "Length: " << vec.Length() << std::endl;
		} catch (int i) {
			std::cerr << "Error: Caught " << i << std::endl;
		}

		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_delete_single_element(Vector<T>& vec) {
	bool stop = false;
	unsigned index;
	char input;

	while (!stop) {
		std::cout << "Input an index to delete the element at that index: ";
		std::cin >> index;
		std::cout << std::endl;

		try {
			vec.Delete(index);
		} catch (int i) {
			std::cerr << i << std::endl;
		}

		std::cout << vec << std::endl;
		std::cout << "Length: " << vec.Length() << std::endl;
		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_delete_range_of_elements(Vector<T>& vec) {
	bool stop = false;
	int index;
	int second_index;
	char input;

	while (!stop) {
		try {
			std::cout << "Input two indices to delete all elements between them, including the first (but not including the second): ";
			std::cin >> index;
			std::cin >> second_index;
			std::cout << std::endl;

			vec.Delete(index, second_index);

			std::cout << vec << std::endl;
			std::cout << "Length: " << vec.Length() << std::endl;
			std::cout << "Again? (y/n): ";
			std::cin >> input;
		} catch (int i) {
			std::cerr << "Error: Caught " << i << std::endl;
		}
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_read_write(Vector<T>& vec) {
	bool stop = false;
	char input;
	std::string filename;

	while (!stop) {
		try {
			std::cout << "Please enter the filename that you'd like to read/write from. If file doesn't exist, it will be created: " << std::endl;
			std::cin >> filename;

			std::ofstream outfile(filename.c_str());
			std::ifstream infile(filename.c_str());

			std::cout << "Writing array to file..." << std::endl;
			std::cout << "Contents of Vector to write: " << vec << std::endl;
			vec.Write(outfile);
			std::cout << "Write operation succeeded without errors." << std::endl
				<< "Excution will now pause so that the user can verify the existance of vector.bin." << std::endl
				<< "Press enter to continue: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			std::cout << "Reading file and appending it to vector..." << std::endl;
			vec.Read(infile);
			std::cout << "New contents of vector: " << std::endl << vec << std::endl;
		} catch (int i) {
			std::cout << "Error: Caught " << i << std::endl;
		}
		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_assignment(Vector<T>& vec) {
	bool stop = false;
	char input;
	T temp[80];
	Vector<T> vec_to_assign;

	while (!stop) {
		int  i = 0;
		std::cout << "Enter values to fill new Vector (note: max size is 80), enter -1 or q to deliminate: ";

		std::cin >> temp[0];
		for(i = 1; temp[i] != -1 && temp[i] != 'q'; i++) {
			std::cin >> temp[i];
		}

		vec_to_assign = *new Vector<T>(temp, i);
		vec = vec_to_assign;

		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}

template <class T>
void test_append(Vector<T>& vec) {
	bool stop = false;
	char input;
	T temp[80];
	Vector<T> vec_to_append;

	while (!stop) {
		int  i = 0;
		std::cout << "Enter values to fill new Vector (note: max size is 80), enter -1 or q to deliminate: ";

		std::cin >> temp[0];
		for(i = 1; temp[i] != -1 && temp[i] != 'q'; i++) {
			std::cin >> temp[i];
		}

		vec_to_append = *new Vector<T>(temp, i);
		vec += vec_to_append;

		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}

	delete &vec_to_append;
}

template <class T>
void test_delete_initial(Vector<T>& vec) {
	bool stop = false;
	char input;

	while (!stop) {
		std::cout << "Would you like to delete the inital element of your vector? (y/n) ";
		std::cin >> input;
		if (input == 'y') vec.Delete();

		std::cout << "Again? (y/n): ";
		std::cin >> input;
		if (input == 'n') stop = true;
	}
}
