#pragma once
template <typename T, int N>
class NDimarray
{
public:
	T* _array;
	int* dimSize;
	int length;
	NDimarray()
	{
		int* size = new int[2];
		size[0] = 10;
		size[1] = 5;

		NDimarray::NDimarray(size);
		delete[] size;
	}

	NDimarray(int* dimSizes)
	{
		dimSize = new int[N];
		length = 1;
		for (int i = 0; i < N; i++)
		{
			dimSize[i] = dimSizes[i];
			length *= dimSize[i];
		}
		_array = new T[length];
	}

	NDimarray(const NDimarray& other)
	{
		copy(other);
	}

	NDimarray<T, N>& operator =(const NDimarray& other)
	{
		if (this != &other)
		{
			clean();
			copy(other);
		}

		return *this;
	}

	NDimarray(NDimarray&& move)
	{
		set(move);
		move.clean();
	}

	NDimarray<T, N>& operator=(NDimarray&& move)
	{
		if (this != &move)
		{
			clean();
			set(move);
			move.clean();
		}
		return *this;
	}

	void put(int* pos, T value)
	{
		_array[index(pos)] = value;
	}

	T get(int* pos)
	{
		return _array[index(pos)];
	}

	int index(int* pos)
	{
		int location = 0;
		int ofset = 1;
		for (int i = 0; i < N; i++)
		{
			if (pos[i] >= dimSize[i])
			{
				throw exception("Out of Bounds");
			}

			location += ofset * pos[i];

			ofset *= dimSize[i];
		}
		return location;
	}

	int get_dim_size(int dim){
		if (dim >= N)
		{
			throw exception("out of bounds exception");
			return -1;
		}
		return dimSize[dim];
	};

	~NDimarray(){ clean(); }
private:
	void clean()
	{
		delete[] _array;
		delete[] dimSize;
		length = 0;
	}

	void set(const NDimarray& value)
	{
		_array = value._array;
		dimSize = value.dimSize;
	}

	void copy(const NDimarray& value)
	{

		_array = new T[length];

		for (int i = 0; i < length; i++)
		{
			_array[i] = value._array[i];
		}

		dimSize = new int[value.getDimAmount()];
		for (int i = 0; i < value.getDimAmount; i++)
		{
			dimSize[i] = value.dimSize[i];
		}
	}

	int getDimAmount()
	{
		return N;
	}
};

