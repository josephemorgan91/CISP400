// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 6
// 2017-04-19

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <fstream>

template <class T> class Vector
{
	private:
		int m_index_offset;
		unsigned m_size;
		unsigned m_length;
		T* m_array;

		void Double();
		void Halve();

	public:
		Vector (int i = 0);
		Vector (const T*, unsigned s, int i = 0);
		Vector (const Vector&);
		virtual ~Vector();

		Vector& operator=(const Vector&);

		template <class P> friend std::ostream& operator<< (std::ostream&, const Vector<P>&);
		template <class P> friend std::ostream& operator<< (std::ostream&, const Vector<P>*);

		T& operator[] (int i);
		const T& operator[] (int i) const;

		Vector operator() (int first, int last) const;

		Vector& operator+= (const T&);
		Vector& operator+= (const Vector&);

		size_t Length() const;

		void Delete(const int i);
		void Delete(int first, int last);
		void Delete();

		void Insert(const T&, int i);
		void Insert(const T&);

		void write (std::ofstream&) const;
		void read (std::ifstream&);
};

#endif

template <class T> Vector<T>::Vector(int i) : m_index_offset(i), m_size(0), m_length(0)
{
	m_array = new T[m_size]; //TODO: Should I change this to void?
}

template <class T> Vector<T>::Vector(const T* first_element, unsigned s, int i) : m_index_offset(i), m_size(0), m_length(0)
{
	m_array = new T[m_size];

	while (m_size < s)
	{
		Double();
	}

	for (unsigned i = 0; i < s; i++)
	{
		m_array[i] = first_element[i];
		m_length++;
	}
}

template <class T> Vector<T>::Vector(const Vector& other) : m_index_offset(other.m_index_offset),  m_size(other.m_size), m_length(other.m_length)
{
	m_array = new T[m_size];

	for (unsigned i = 0; i < m_length; i++)
	{
		m_array[i] = other.m_array[i];
	}
}
template <class T> Vector<T>::~Vector()

{
	delete[] m_array;
}

template <class T> void Vector<T>::Double()
{
	T* new_array;

	if (m_size == 0)
	{
		m_size = 1;
		new_array = new T[1];
		delete[] m_array;
		m_array = new_array;
	}

	else
	{
		m_size *= 2;
		new_array = new T[m_size];

		for (int i = 0; i < m_length; i++)
		{
			new_array[i] = m_array[i];
		}

		delete[] m_array;
		m_array = new_array;
	}
}

template <class T> void Vector<T>::Halve()
{
	if (m_size >= m_length * 2)
	{
		m_size /= 2;
		T* newm_array = new T[m_size];

		for (int i = 0; i < m_length; i++)
		{
			newm_array[i] = m_array[i];
		}

		delete[] m_array;
		m_array = newm_array;
	}
}

template <class T> Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other)
	{
		m_index_offset = other.m_index_offset;
		m_size = other.m_size;
		m_length = other.m_length;

		delete[] m_array;
		m_array = new T[m_size];

		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = other.m_array[i];
		}
	}

	return *this;
}

template <class P> std::ostream& operator<<(std::ostream& os, const Vector<P>& vec)
{
	os << "{";
	for (int i = 0; i < vec.m_length - 1; i++)
	{
		os << vec.m_array[i] << ", ";
	}
	os << vec[vec.m_length - 1] << "}";

	return os;
}

template <class P> std::ostream& operator<<(std::ostream& os, const Vector<P>* vec)
{
	os << (*vec);

	return os;
}

template <class T> T& Vector<T>::operator[](int i)
{
	int index = i - m_index_offset;

	if (index >= 0 && index < this->m_length)
	{
		return m_array[index];
	} else throw -1;
}

template <class T> const T& Vector<T>::operator[](int i) const
{
	int index = i - m_index_offset;

	if (index >= 0 && index < this->m_length)
	{
		return m_array[index];
	} else throw -1;
}

template <class T> Vector<T> Vector<T>::operator()(int first, int last) const
{
	int first_index = first - m_index_offset;
	int last_index = last - m_index_offset;
	int newm_size = ((last_index - first_index) - 1);

	Vector<T> copy;
	for (int i = 0; i < newm_size; i++)
	{
		copy += m_array[first_index + i];
	}
	return copy;
}

template <class T> Vector<T>& Vector<T>::operator+=(const T& value)
{
	if (m_size == m_length)
	{
		Double();
	}

	m_array[m_length] = value;
	m_length++;

	return *this;
}

template <class T> Vector<T>& Vector<T>::operator+=(const Vector& vec)
{
	for (int i = 0; i < vec.m_length; i++)
	{
		*this += vec.m_array[i];
	}

	return *this;
}

template <class T> size_t Vector<T>::Length() const
{
	return m_length;
}

template <class T> void Vector<T>::Delete(const int i)
{
	int index = i - m_index_offset;

	if (0 <= index && index < m_length)
	{
		m_length--;

		for (int i = index; i < m_length; i++)
		{
			m_array[i] = m_array[i+1];
		}

		if (m_size >= m_length * 2)
		{
			Halve();
		}
	} else throw -1;
}

template <class T> void Vector<T>::Delete(int first, int last)
{
	int first_index = first - m_index_offset;
	int last_index = last - m_index_offset;

	if ((first_index >= 0 && last_index < Length() + m_index_offset) && (first_index < last_index))
	{
		for (int num_deleted = 0; num_deleted < (last_index - first_index); num_deleted++)
		{
			Delete(first_index);
		}
	} else throw -1;
}

template <class T> void Vector<T>::Delete()
{
	Delete(m_index_offset);
}

template <class T> void Vector<T>::Insert (const T& value, int i)
{
	int index = i - m_index_offset;

	if (index < m_length)
	{
		if (m_length == m_size)
		{
			Double();
		}

		for (int j = m_length; j > index; j--)
		{
			m_array[j] = m_array[j - 1];
		}

		m_array[index] = value;
		m_length++;
	} else throw -1;
}

template <class T> void Vector<T>::Insert(const T& value)
{
	Insert(value, m_index_offset);
}

template <class T> void Vector<T>::write (std::ofstream& ofile) const
{
	if (!ofile.is_open()) ofile.open("vector.bin", std::ios::trunc | std::ios::binary);

	if (ofile.is_open())
	{
		ofile.write(reinterpret_cast<const char*>(&m_index_offset), sizeof(m_index_offset));
		ofile.write(reinterpret_cast<const char*>(&m_length), sizeof(m_length));
		ofile.write(reinterpret_cast<const char*>(m_array), m_length * sizeof(T));
	} else throw -6;

	ofile.close();
}

template <class T> void Vector<T>::read (std::ifstream& ifile)
{
	if (!ifile.is_open()) ifile.open("vector.bin", std::ios::binary);

	if (ifile.is_open())
	{
		ifile.read(reinterpret_cast<char*>(&m_index_offset), sizeof(m_index_offset));
		ifile.read(reinterpret_cast<char*>(&m_length), sizeof(m_length));
		delete[] m_array;
		while (m_size < m_length) (m_size == 0) ? m_size = 1 : m_size *= 2;
		m_array = new T[m_size];
		ifile.read(reinterpret_cast<char*>(m_array), m_length * sizeof(T));
	} else throw -5;
}

/* *** Glossary of Throws ***
 *
 *  -1 : Index out of range.
 *  -5 : File could not be opened for reading.
 *  -6 : File could not be opened for writing.
 */
