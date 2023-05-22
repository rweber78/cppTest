#pragma once

#include <memory>
#include <string>

struct IsapiWebRequest
{
   std::string name() const;
   void load(const std::string& xml);
};

struct CrowWebRequest
{
   std::string name() const;
   void load(const std::string& xml);
};

class WebRequest
{
   struct WebRequestConcept
   {
      virtual ~WebRequestConcept() = default;

      [[nodiscard]] virtual std::string name() const = 0;
      virtual void load(const std::string& xml) = 0;
   };

   template <typename T>
   struct WebRequestModel
       : WebRequestConcept
   {
      explicit WebRequestModel(const T &t)
          : object(t) {}

      ~WebRequestModel() override = default;

      [[nodiscard]] std::string name() const override { return object.name(); }
      void load(const std::string& xml) override { object.load(xml); }

   private:
      T object;
   };

   std::unique_ptr<WebRequestConcept> fRequest;

public:
   template <typename T>
   explicit WebRequest(const T &obj)
       : fRequest(new WebRequestModel<T>(obj)) {}

   [[nodiscard]] std::string name() const { return fRequest->name(); }
   void load(const std::string& xml) { fRequest->load(xml); }

};