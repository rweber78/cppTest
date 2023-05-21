#include "gtest/gtest.h"

#include "Chrono.h"
//#include "Logger.h"

#include "WebInterface.h"

struct TypeErasureFixture : public ::testing::Test
{
public:
   TypeErasureFixture()
   {
   }

};

TEST_F(TypeErasureFixture, ShowTypeErasure)
{
   Chrono testChrono("Test TypeErasure");

   WebRequest request1 = WebRequest(CrowWebRequest());
   printf("Name 1 = %s\n", request1.name().c_str());
   EXPECT_EQ("Crow", request1.name());

   WebRequest request2 = WebRequest(IsapiWebRequest());
   printf("Name 2 = %s\n", request2.name().c_str());
   EXPECT_EQ("ISAPI", request2.name());

}
