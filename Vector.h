class vector{
private:
    float* comp;
    int n;
public:
    vector (int n);
    vector (const vector& that);
    ~vector();

    friend float modul(vector&);
    void set(int , float);
	float operator [](int , float);
	vector operator +(const vector&);
    vector operator -(const vector&);
    vector operator ^(const vector&);
    float operator *(const vector&);
    vector operator *(float);
	void print();
};