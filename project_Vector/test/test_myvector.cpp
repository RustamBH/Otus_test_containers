#include "MyVector.h"

#include <gtest/gtest.h>


TEST(Vector, Empty) {
    // Arrange
    MyVector<int> vec;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(vec.getSize(), 0);
    ASSERT_TRUE(vec.is_empty());
}

TEST(Vector, InitVector) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }    

    // Act
    MyVector<size_t> vec2 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Assert
    for (size_t i = 0; i < count; ++i) {
        ASSERT_EQ(vec2[i], vec[i]);
    }
    
    //ASSERT_EQ(vec.getSize(), count);
    //ASSERT_EQ(vec2.getSize(), count);
    ASSERT_EQ(vec.getSize(), vec2.getSize());
    ASSERT_FALSE(vec2.is_empty());
}


TEST(Vector, PushBack) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }

    // Assert
    ASSERT_EQ(vec.getSize(), count);
    ASSERT_FALSE(vec.is_empty());
}

TEST(Vector, Insert) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }    

    // Act
    for (size_t i = 0; i < count; ++i) {
        vec.insert(5, i);
    }

    // Assert
    ASSERT_EQ(vec.getSize(), count * 2);
    ASSERT_FALSE(vec.is_empty());
}


TEST(Vector, Erase) {
    // Arrange 
    const size_t count = 10;
    MyVector<size_t> vec;

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        vec.erase(0);
    }

    // Assert
    ASSERT_EQ(vec.getSize(), 0);
    ASSERT_TRUE(vec.is_empty());
}

TEST(Vector, GetElement) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }    

    // Act (empty for this test)

    // Assert    
    for (size_t i = 0; i < count; ++i) {        
        ASSERT_EQ(vec[i], i);
    }    
    ASSERT_FALSE(vec.is_empty());
}

TEST(Vector, GetSize) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }     

    // Assert        
    ASSERT_EQ(vec.getSize(), count);    
    ASSERT_FALSE(vec.is_empty());
}

TEST(Vector, GetCapacity) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;

    // Act
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }     

    // Assert        
    ASSERT_GE(vec.getCapacity(), vec.getSize());    
    ASSERT_FALSE(vec.is_empty());
}

TEST(Vector, CopyContainer) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;    

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }     

    // Act         
    MyVector<size_t> vec2{vec};

    // Assert         
    for (size_t i = 0; i < count; ++i) {        
        ASSERT_EQ(vec2[i], vec[i]);
    }         
    ASSERT_FALSE(vec2.is_empty());
}

TEST(Vector, AssignContainer) {
    // Arrange
    const size_t count = 10;
    MyVector<size_t> vec;    

    for (size_t i = 0; i < count; ++i) {
        vec.push_back(i);
    }     

    // Act         
    MyVector<size_t> vec2;
    vec2 = vec;

    // Assert         
    for (size_t i = 0; i < count; ++i) {        
        ASSERT_EQ(vec2[i], vec[i]);
    }         
    ASSERT_FALSE(vec2.is_empty());
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}