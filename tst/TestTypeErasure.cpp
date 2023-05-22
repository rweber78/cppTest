#include "gtest/gtest.h"

#include "Chrono.h"
// #include "Logger.h"

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

   std::string xml{"Test string"};

   WebRequest request1 = WebRequest(CrowWebRequest());
   request1.load(xml);
   EXPECT_EQ("Crow", request1.name());

   WebRequest request2 = WebRequest(IsapiWebRequest());
   request2.load(xml);
   EXPECT_EQ("ISAPI", request2.name());
}
