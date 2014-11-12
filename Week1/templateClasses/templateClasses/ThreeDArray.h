#pragma once
template <typename T>
class ThreeDArray
{
public:
	T* _array;
	int xSize, ySize, zSize;
	ThreeDArray() : ThreeDArray(10, 10, 10){ };

	ThreeDArray(int x, int y, int z)
	{
		xSize = x;
		ySize = y;
		zSize = z;
		_array = new T[xSize * ySize * zSize];
	}

	ThreeDArray(const ThreeDArray& other)
	{
		copy(other);
	}

	ThreeDArray<T>& operator =(const ThreeDArray& other)
	{
		if (this != &other)
		{
			clean();
			copy(other);
		}

		return *this;
	}

	ThreeDArray(ThreeDArray&& move)
	{
		set(move);
		move.clean();
	}

	ThreeDArray<T>& operator=(ThreeDArray&& move)
	{
		if (this != &move)
		{
			clean();
			set(move);
			move.clean();
		}
		return *this;
	}

	void put(int x, int y, int z, T value)
	{
		_array[index(x, y, z)] = value;
	}

	T get(int x, int y, int z)
	{
		return _array[index(x, y, z)];
	}

	int index(int x, int y, int z)
	{
		if (x >= xSize || y >= ySize || z >= zSize)
			throw exception("Out of Bounds");
		return ySize * xSize * z + xSize * y + x;
	}

	int get_x_size(){ return xSize; };
	int get_y_size(){ return ySize; };
	int get_z_size(){ return zSize; };

	~ThreeDArray(){ clean(); }
private:
	void clean()
	{
		delete[] _array;
		xSize = 0;
		ySize = 0;
		zSize = 0;
	}

	void set(const ThreeDArray& value)
	{
		_array = value._array;
		xSize = value.xSize;
		ySize = value.ySize;
		zSize = value.zSize;
	}

	void copy(const ThreeDArray& value)
	{
		int length = value.xSize * value.ySize * value.zSize;
		_array = new T[length];

		for (int i = 0; i < length; i++)
		{
			_array[i] = value._array[i];
		}

		xSize = value.xSize;
		ySize = value.ySize;
		zSize = value.zSize;
	}
};

