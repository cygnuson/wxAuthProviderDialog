#pragma once

#include <wx\app.h>

class TestApp : public wxApp
{
public:
    virtual bool OnInit();
private:

};

DECLARE_APP(TestApp)
