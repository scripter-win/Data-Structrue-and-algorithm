#pragma 
//typedef int rank;
#define rank int
#define default_capacity 3
template <typename T> class Vector
{
protected:
	rank _size;
	int capacity;
	T* elem;
	void copyfrom(T const*c, rank lo, rank hi);
public:
	Vector(int c =default_capacity,int s=0,T v=0) { elem = new T[capacity = c]; for (int i = 0; i < s; i++)elem[i] = v; }
	Vector(T const*c,rank n) { copyfrom(c,0,n); }
	Vector(Vector<T> const& V) { copyfrom(V,0,v.size); }
	~Vector() { delete[]elem; }
	rank size() { return _size; }
	bool empty() { return !_size; }
	int disordered() const;
	rank find(T const& e, int lo, int hi)const;
	rank find(T const& e) const { return find(e, 0, _size) };
	rank serach(T const& e, int hi, int lo)const;
	rank serach(T const& e)const { return serach(e, 0, _size) };
	//可写访问接口
	T& operator[] (rank r)const;				//重载 [] 运算符，用数组方式访问对应元素
	Vector<T> & operator= (Vector<T> const &);  //重载 = 运算符 ，方便直接克隆向量
	T    remove(rank r) ;				 //删除秩为 r 的元素
	int  remove(rank lo, rank hi);	     //删除秩区间为 lo 到 hi 的元素
	rank insert(T const& e, rank r);     //在秩为 r 的位置插入元素
	rank insert(T const& e) { return insert(e, _size); }  //默认在最后插入元素
	void sort(int lo, int hi);           //对[lo,hi)排序
	void sort() { sort(0, _size); }       //整体排序
	void unsort(int lo ,int hi) {}       //[lo,hi)乱序
	void unsort() { unsort(0, _size); };  //整体乱序
	int  deduplicate();                  //无序去重
	int  uniquify();					 //有序去重
	void insertsort(int lo ,int hi) ;
	void insertsort() { insertsort(0, _size); }
private:
};

template<typename T> T& Vector<T>::operator[](rank r)const
{
	return elem[r];
}


template<typename T> rank Vector<T>::insert(T const& e, rank r)
{
	for (int i = _size; i > r; i--)
	{
		elem[i] = elem[i - 1];
	}
	elem[r] = e;
	_size++;
	return r;
}


template<typename T> void Vector<T>::insertsort(int lo ,int hi)
{
	for (int i = lo + 1; i < hi ; i++)
	{
		int x = elem[i];
		int index = i - 1;
		while (elem[index] > x && index >= lo)
		{
			elem[index+1] = elem[index];
			index--;
		}
		elem[index + 1] = x;
	}
}
