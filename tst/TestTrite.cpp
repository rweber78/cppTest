 #include "gtest/gtest.h"

#include "Chrono.h"
#include "Logger.h"

struct TriteFixture : public ::testing::Test
{
 public:
   TriteFixture()
   {
   }

};

TEST_F(TriteFixture, ShowTrite)
{
   Chrono triteChrono("ShowTrite");

   EXPECT_EQ(0, 0);
   printf("Trite parts:\n");
   uint8_t b1, b2, b3;
   b1 = 0x7F;
   b2 = 0x99;
   b3 = 0xAD;
   uint32_t trite = (b1 << 16) | (b2 << 8) | b3;
   printf("  %02x  %02x  %02x  %06x\n", b1, b2, b3, trite);
}
