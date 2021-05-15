#include <iostream>
#include <cstring>


template<typename T>
class vector {
public:
    class iterator final {
    public:
        iterator(T *data, int index) :
                m_data(data), m_index(index) {};

        const T &operator->() const {
            return m_data[m_index];
        };

        T &operator->() {
            return m_data[m_index];
        };

        const T &operator*() const {
            return m_data[m_index];
        };

        T &operator*() {
            return m_data[m_index];
        };

        iterator &operator++() {
            m_index++;
            return *this;
        };

        iterator operator++(int amount) {
            auto prev = *this;
            m_index += amount;
            return prev;
        };

        iterator &operator--() {
            if (m_index != 0) {
                m_index--;
            }
            return *this;
        };

        iterator operator--(int amount) {
            if (amount < m_index) {
                m_index -= amount;
            } else { m_index = 0; }
            return *this;
        };

        bool operator==(const iterator &rhs) const {
            return (rhs.m_index == m_index && rhs.m_data == m_data);
        };

        bool operator!=(const iterator &rhs) const {
            return (rhs.m_index != m_index || rhs.m_data != m_data);
        };

        bool operator<(const iterator &rhs) const {
            return rhs.m_index < m_index;
        };
    private:
        T *m_data;
        int m_index;
    };

    vector(int capacity = 0) {
        m_size = 0;
        m_capacity = capacity;
        m_data = new T[m_capacity];
    };

    void Resize() {
        if (m_capacity == 0)
            m_capacity = 1;

        m_capacity *= 2;
        T *pointer = new T[m_capacity];
        if (m_data != nullptr)
            std::copy(m_data, m_data + m_capacity / 2, pointer);

        delete[] m_data;
        m_data = pointer;
    }

    void PushBack(const T &object) {
        if (m_size >= m_capacity)
            Resize();

        m_data[m_size] = object;
        ++m_size;
    };

    void PopBack() {
        m_size--;
    };

    T &operator[](int index) {
        return m_data[index];
    };

    u_int GetSize() const {
        return m_size;
    };

    iterator begin() {
        return iterator(m_data, 0);
    };

    iterator end() {
        return iterator(m_data, m_size);
    };
private:
    T *m_data;
    int m_size;
    int m_capacity;
};