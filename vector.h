#ifndef vector_h
#define vector_h

#include <memory>
#include <algorithm>
#include <stdexcept>


template <typename T>
class Vector {
private:
    T* data;
    size_t size_;
    size_t capacity_;
    std::allocator<T> allocator_;

    void reallocate(size_t new_capacity) {
        T* new_data = allocator_.allocate(new_capacity);
        if (data) {
            std::move(data, data + size_, new_data);
            for (size_t i = 0; i < size_; ++i) {
                data[i].~T();
            }
            allocator_.deallocate(data, capacity_);
        }
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() : data(nullptr), size_(0), capacity_(0) {}

    ~Vector() {
        clear();
        allocator_.deallocate(data, capacity_);
    }

    Vector(const Vector& other) : data(nullptr), size_(0), capacity_(0) {
        if (other.size_ > 0) {
            data = allocator_.allocate(other.size_);
            std::uninitialized_copy(other.data, other.data + other.size_, data);
            size_ = other.size_;
            capacity_ = other.size_;
        }
    }

    Vector(Vector&& other) noexcept
        : data(other.data), size_(other.size_), capacity_(other.capacity_) {
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            clear();
            if (capacity_ < other.size_) {
                allocator_.deallocate(data, capacity_);
                data = allocator_.allocate(other.size_);
                capacity_ = other.size_;
            }
            std::uninitialized_copy(other.data, other.data + other.size_, data);
            size_ = other.size_;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            allocator_.deallocate(data, capacity_);
            data = other.data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : 2 * capacity_);
        }
        new (data + size_) T(value); // Placement new
        ++size_;
    }

    void push_back(T&& value) {
        if (size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : 2 * capacity_);
        }
        new (data + size_) T(std::move(value)); // Placement new
        ++size_;
    }

    void pop_back() {
        if (size_ > 0) {
            data[size_ - 1].~T(); // Explicit destructor call
            --size_;
        }
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        for (size_t i = 0; i < size_; ++i) {
            data[i].~T(); // Explicit destructor call
        }
        size_ = 0;
    }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data[index];
    }
};

#endif
