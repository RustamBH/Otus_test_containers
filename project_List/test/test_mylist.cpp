#include "MyList.h"
//#include <algorithm>
#include <gtest/gtest.h>


TEST(Lst, Empty) {
    // Arrange
    MyList<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.getSize(), 0);
    ASSERT_TRUE(list.is_empty());
}

TEST(Lst, PushBack) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.getSize(), count);
    ASSERT_FALSE(list.is_empty());
}

TEST(Lst, PushFront) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_front(i);
    }

    // Assert
    ASSERT_EQ(list.getSize(), count);
    ASSERT_FALSE(list.is_empty());
}

TEST(Lst, Insert) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }    

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.insert(5, i);
    }

    // Assert
    ASSERT_EQ(list.getSize(), count * 2);
    ASSERT_FALSE(list.is_empty());
}

TEST(Lst, PopBack) {
    // Arrange 
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.pop_back();
    }

    // Assert
    ASSERT_EQ(list.getSize(), 0);
    ASSERT_TRUE(list.is_empty());
}

TEST(Lst, PopFront) {
    // Arrange 
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.pop_front();
    }

    // Assert
    ASSERT_EQ(list.getSize(), 0);
    ASSERT_TRUE(list.is_empty());
}

TEST(Lst, Erase) {
    // Arrange 
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 1; i < count - 1; ++i) {
        list.erase(i);
    }

    // Assert
    ASSERT_EQ(list.getSize(), 2);
    ASSERT_FALSE(list.is_empty());
}

TEST(Lst, GetElement) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }    

    // Act (empty for this test)

    // Assert    
    for (size_t i = 0; i < count; ++i) {        
        ASSERT_EQ(list[i], i);
    }    
    ASSERT_FALSE(list.is_empty());
}
/*
TEST(Lst, GetElement2) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }    

    // Act (empty for this test)
    for (size_t i = 0; i < count; ++i) {        
        list.erase(list[i]);
    }

    // Assert    
    ASSERT_EQ(list.getSize(), 0);
    ASSERT_TRUE(list.is_empty());
}
*/

TEST(Lst, GetSize) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }     

    // Assert        
    ASSERT_EQ(list.getSize(), count);    
    ASSERT_FALSE(list.is_empty());
}

TEST(Lst, CopyContainer) {
    // Arrange
    const size_t count = 10;
    MyList<size_t> list;    

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }     

    // Act
    //std::copy(list.begin(), list.end(), list2);     
    MyList<size_t> list2{list};

    // Assert         
    for (size_t i = 0; i < count; ++i) {        
        ASSERT_EQ(list2[i], list[i]);
    }         
    ASSERT_FALSE(list.is_empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}