#pragma once

#include <memory>
#include <string>

struct IsapiWebRequest
{
   std::string name() const { return "ISAPI"; }
};

struct CrowWebRequest
{
   std::string name() const { return "Crow"; }
};

class WebRequest
{
   struct WebRequestConcept
   {
      virtual ~WebRequestConcept() = default;

      [[nodiscard]] virtual std::string name() const = 0;
   };

   template <typename T>
   struct WebRequestModel
       : WebRequestConcept
   {
      explicit WebRequestModel(const T &t)
          : object(t) {}

      ~WebRequestModel() override = default;

      [[nodiscard]] std::string name() const override { return object.name(); }

   private:
      T object;
   };

   std::unique_ptr<WebRequestConcept> fRequest;

public:
   template <typename T>
   explicit WebRequest(const T &obj)
       : fRequest(new WebRequestModel<T>(obj)) {}

   [[nodiscard]] std::string name() const { return fRequest->name(); }
};