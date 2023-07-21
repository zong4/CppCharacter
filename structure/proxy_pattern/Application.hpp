#pragma once

#include "WebImp.hpp"
#include "WebProxy.hpp"

class Application : public WebImp<Application>
{
private:
    WebProxy _webProxy;

public:
    void request() { _webProxy.request(); }
};