// C has malloc and free for dynamic memory handling.
// C++ has new/delete.
// Vector object with dynamic dimensions
// static variables, static member variables
// Generic Programming = Templates in C++

// const keyword

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (in CS409/509 Adv. C++ Course)
// inheritance (later)

// function overloading
// operators and operator overloading
// function parameters: pass by value, pass by reference

// auto, AAA rule (almost always auto)

#include <iostream>


int a = 5; // static initialization

int VectorTCount = 0;

template <typename T>
struct Vector
{
    int size;
    T* data;

    Vector(int size, T* initial_values) : size(size), data(new T[size]) {
        for(int i=0; i<size; i++)
            data[i] = initial_values[i];

        VectorTCount++;
    }
    ~Vector() {
        delete[] data;
        VectorTCount--;
    }

    void setIndex(int index, T value)
    {
//        IntVector& iv = *this;
//        iv.data[index] = value;
        this->data[index] = value;
    }

    void print() const
    {
//        this->size = 5;
        for(int i=0; i<this->size; i++) {
            std::cout << this->data[i];
            if(i != this->size - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

};

template <typename T>
void print(const Vector<T>& iv)
{
    static bool firstTime = true;

    if(firstTime) {
        std::cout << "Hi there, I am free function print that prints an IntVector" << std::endl;
        firstTime = false;
    }
    for(int i=0; i<iv.size; i++) {
        std::cout << iv.data[i];
        if(i != iv.size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    {
        std::cout << VectorTCount << std::endl;

        int iv_values[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        auto iv = Vector<int>(10, &iv_values[0]);

        std::cout << VectorTCount << std::endl;

        {
            auto iv2 = Vector<int>(5, &iv_values[0]);
            std::cout << VectorTCount << std::endl;
        }

        std::cout << VectorTCount << std::endl;

        {
            double dv_values[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
            auto dv = Vector<double>(5, &dv_values[0]);
            std::cout << VectorTCount << std::endl;
            print(dv);
        }


        iv.data[2] = 5;
//        setValueOfIntVector(iv, 2, 5);
        iv.setIndex(0, 10);
        iv.setIndex(1, 25);
        iv.setIndex(2, 5);

        print(iv);
        print(iv);
        print(iv);

        iv.print();

        // ...
    }


    // C has malloc and free for dynamic memory handling.
    int* ptr = (int*)malloc(sizeof(int)*100);
    ptr[0] = 1;

    ptr[10] = 5;
    *(ptr + 10) = 5;

    //    ptr[100] = 2; // out of bounds
    ptr[-1] = 0; // out of bounds
    *(ptr + (-1)) = 0;
    *((-1) + ptr) = 0;

    free(ptr);

    // C++ ancient way
    int* ptr2 = new int[100];
    // ...
    delete[] ptr2;

    int* value = new int;
    delete value;

    // ...








    return 0;
}
