class ShallowCopy {
private:
    int* data;
public:
    ShallowCopy(int val) {
        data = new int(val);
    }
    ~ShallowCopy() {
        delete data;
    }
    // Shallow copy constructor and assignment operator
    ShallowCopy(const ShallowCopy& other) : data(other.data) {}
    ShallowCopy& operator=(const ShallowCopy& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
};

class DeepCopy {
private:
    int* data;
public:
    DeepCopy(int val) {
        data = new int(val);
    }
    ~DeepCopy() {
        delete data;
    }
    // Deep copy constructor and assignment operator
    DeepCopy(const DeepCopy& other) : data(new int(*(other.data))) {}
    DeepCopy& operator=(const DeepCopy& other) {
        if (this != &other) {
            data = new int(*(other.data));
        }
        return *this;
    }
};
