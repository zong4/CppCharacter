
template <typename T>
class MyVector
{
private:
    size_t _size;
    size_t _maxSize;
    T*     _data;

public:
    MyVector() : _size(0), _maxSize(1) { _data = new T[_maxSize]; }
    MyVector(MyVector const& vec)
    {
        _data = new T[vec.maxSize()];
        for (int i = 0; i < vec.size(); i++)
        {
            _data[i] = vec.constData[i];
        }
    }
    ~MyVector() { delete _data; }

    inline size_t   size() const { return _size; }
    inline const T* constData() const { return _data; }
    inline T        operator[](int index) { return _data[index]; }

    void push_back(T const& val)
    {
        if (_size == _maxSize)
            reverse(_maxSize * 2);

        T[_size++] = val;
    }

    void reverse(size_t maxSize)
    {
        size_t newSize = maxSize > _maxSize * 2 ? maxSize : _maxSize * 2;
        reDistribute(newSize);
    }

protected:
    inline size_t maxSize() const { return _maxSize; }

    void reDistribute(size_t maxSize)
    {
        T* data = new T[maxSize];

        for (int i = 0; i < _size; i++)
        {
            data[i] = _data[i];
        }

        delete _data;
        _data = data;
    }
};