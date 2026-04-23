#include <gtest/gtest.h>
#include "gta2/EntityManager.h"
#include <cstring>

using namespace gta2;

// Test: Verify structure size is exactly 0x2F04 (12036 bytes)
TEST(EntityManagerTest, StructureSize) {
    EXPECT_EQ(sizeof(EntityManager), 0x2F04);
}

// Test: Constructor initializes data to zero
TEST(EntityManagerTest, ConstructorInitialization) {
    EntityManager manager;
    
    // Check if raw data is zeroed (constructor logic)
    bool allZero = true;
    for (size_t i = 0; i < sizeof(manager.raw_data); ++i) {
        if (manager.raw_data[i] != 0) {
            allZero = false;
            break;
        }
    }
    // Note: Our mock constructor zeros memory, so this should pass
    EXPECT_TRUE(allZero);
    
    // Check initial count
    EXPECT_EQ(manager.GetCount(), 0);
}

// Test: Reset functionality
TEST(EntityManagerTest, ResetFunctionality) {
    EntityManager manager;
    
    // Simulate some state change (direct memory manipulation for test)
    manager.GetCount() = 10;
    manager.raw_data[0x10] = 0xFF;
    
    manager.Reset();
    
    EXPECT_EQ(manager.GetCount(), 0);
    EXPECT_EQ(manager.raw_data[0x10], 0);
}

// Test: AllocateSlot returns -1 when no slots available (mock behavior)
TEST(EntityManagerTest, AllocateSlotEmpty) {
    EntityManager manager;
    // In our mock, FindFreeSlot returns -1 always
    int32_t slot = manager.AllocateSlot();
    EXPECT_EQ(slot, -1);
    EXPECT_EQ(manager.GetCount(), 0); // Count shouldn't increase if allocation fails
}

// Test: Global pointer initialization
TEST(EntityManagerTest, GlobalPointer) {
    // Initially null
    EXPECT_EQ(gEntityManager, nullptr);
}

// Test: Method placeholders exist and don't crash
TEST(EntityManagerTest, UnknownMethodsSafe) {
    EntityManager manager;
    
    // Call a few unknown methods to ensure they are safe stubs
    EXPECT_NO_THROW(manager.Sub_Unknown_01());
    EXPECT_NO_THROW(manager.Sub_Unknown_15());
    EXPECT_NO_THROW(manager.Sub_Unknown_30());
}

// Test: Create methods return nullptr in mock state
TEST(EntityManagerTest, CreateMethodsMock) {
    EntityManager manager;
    
    EXPECT_EQ(manager.CreateCar(0, 0, 0, 1), nullptr);
    EXPECT_EQ(manager.CreatePed(0, 0, 0, 1), nullptr);
    EXPECT_EQ(manager.CreateWeapon(1, 0, 0, 0), nullptr);
}

// Test: GetEntity with invalid index
TEST(EntityManagerTest, GetEntityInvalidIndex) {
    EntityManager manager;
    EXPECT_EQ(manager.GetEntity(-1), nullptr);
    EXPECT_EQ(manager.GetEntity(100), nullptr);
}

// Test: FreeSlot safety
TEST(EntityManagerTest, FreeSlotSafety) {
    EntityManager manager;
    // Should not crash on invalid indices in mock implementation
    EXPECT_NO_THROW(manager.FreeSlot(-1));
    EXPECT_NO_THROW(manager.FreeSlot(100));
}

// Test: Update methods safety
TEST(EntityManagerTest, UpdateMethodsSafe) {
    EntityManager manager;
    EXPECT_NO_THROW(manager.Update());
    EXPECT_NO_THROW(manager.UpdateAI());
    EXPECT_NO_THROW(manager.UpdatePhysics());
}

// Test: DebugDraw safety
TEST(EntityManagerTest, DebugDrawSafe) {
    EntityManager manager;
    EXPECT_NO_THROW(manager.DebugDraw());
}

// Test: RemoveEntity safety
TEST(EntityManagerTest, RemoveEntitySafe) {
    EntityManager manager;
    EXPECT_NO_THROW(manager.RemoveEntity(-1));
    EXPECT_NO_THROW(manager.RemoveEntity(50));
}

// Test: RemoveAllByType safety
TEST(EntityManagerTest, RemoveAllByTypeSafe) {
    EntityManager manager;
    EXPECT_NO_THROW(manager.RemoveAllByType(1));
    EXPECT_NO_THROW(manager.RemoveAllByType(999));
}

// Test: Find methods return -1 in empty state
TEST(EntityManagerTest, FindMethodsEmpty) {
    EntityManager manager;
    EXPECT_EQ(manager.FindFreeSlot(), -1);
    EXPECT_EQ(manager.FindByType(1), -1);
    EXPECT_EQ(manager.FindNearest(0, 0, 1), -1);
}

// Test: IsSlotUsed returns false in empty state
TEST(EntityManagerTest, IsSlotUsedEmpty) {
    EntityManager manager;
    EXPECT_FALSE(manager.IsSlotUsed(0));
    EXPECT_FALSE(manager.IsSlotUsed(100));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
