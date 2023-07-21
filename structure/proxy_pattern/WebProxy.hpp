#pragma once

#include "WebImp.hpp"

class WebProxy : public WebImp<WebProxy>
{
public:
    void request() { std::cout << "WebProxy::request()" << std::endl; }
};